#include "main.h"


struct vlc_packet *tx_pkt;

// For DATA frame
#define DB_BYTE_LEN 5000
#define DB_SYMBOL_LEN 5000*8
static unsigned char data_buffer_byte[DB_BYTE_LEN];
static _Bool data_buffer_symbol[DB_SYMBOL_LEN];

// For ACK frame
#define ACK_BYTE_LEN 50
#define ACK_SYMBOL_LEN 50*8
static char ack_buffer_byte[ACK_BYTE_LEN];
static _Bool ack_buffer_symbol[ACK_SYMBOL_LEN];


//File ip output
FILE *exein, *exeout;

//TODO modify
void convertDatatoBits(char* data, uint size)
{
   
   //char b[sizeof(struct_data)];
   //memcpy(b, &struct_data, sizeof(struct_data));

   //char [] buff = new buff[size];
   unsigned char byte[8];

   FILE *exeout1;
   exeout1 = fopen("bytestream.txt", "a+");
   int i;
   for (i = 0; i < size; ++i)
   {
       unsigned char c = *(data + i);
      /*for (i = 0; i < 8; ++i) {
        byte[i] = (char)((c >> i) & 1);
      }*/
      //fwrite(byte, 1, sizeof(byte), exeout);
      fwrite(&c, 1, sizeof(c), exeout1);
   }
   fclose(exeout1);
}

void init()
{
   exein = fopen("1.png", "rb");
   if (exein == NULL) {
      perror("file open for reading");
      exit(EXIT_FAILURE);
   }

}

void dinit()
{
    if (fclose(exeout)) perror("close output file");
}

size_t getData(char* data_buffer)
{
    size_t flag;
    flag = fread(data_buffer, 1, sizeof data_buffer, exein);
    return flag;
}


//  ______  NOT USED AS OF NOW  ________
// On-Off Keying (OOK) WITH Manchester Run-Length-Limited (RLL) code
static void OOK_with_Manchester_RLL(char *buffer_before_coding,
    _Bool *buffer_after_coding, int len_before_coding)
{
    int byte_index, symbol_index = 0;
    unsigned char curr_byte, mask;

    // Convert the preamble -- OOK w/o Manchester RLL code
    for (byte_index=0; byte_index<PREAMBLE_LEN; byte_index++) {
        mask = 0x80;
        curr_byte = buffer_before_coding[byte_index] & 0xff;
        while (mask) {
            buffer_after_coding[symbol_index++] = (_Bool) (curr_byte & mask);
            mask >>= 1;
        }
    }

    // Convert the parts after the preamble -- OOK w Manchester RLL code
    for (byte_index=PREAMBLE_LEN; byte_index<len_before_coding; byte_index++) {
        mask = 0x80;
        curr_byte = buffer_before_coding[byte_index] & 0xff;
        while (mask) {
            if ((_Bool) (curr_byte & mask)) { // Bit 1 -- LOW-HIGH
                buffer_after_coding[symbol_index++] = false;
                buffer_after_coding[symbol_index++] = true;
            } else { // Bit 0 -- HIGH-LOW
                buffer_after_coding[symbol_index++] = true;
                buffer_after_coding[symbol_index++] = false;
            }
            mask >>= 1;
        }
    }
    
}

// JUST CONVERT TO OOK
static void SIMPLE_OOK(char *buffer_before_coding,
    _Bool *buffer_after_coding, int len_before_coding)
{
    int byte_index, symbol_index = 0;
    unsigned char curr_byte, mask;

    for (byte_index=0; byte_index<len_before_coding; byte_index++) {
        mask = 0x80;
        curr_byte = buffer_before_coding[byte_index] & 0xff;
        while (mask) {
            buffer_after_coding[symbol_index++] = (_Bool) (curr_byte & mask);
            mask >>= 1;
        }
    }
}


static void construct_frame_header(char* buffer, int buffer_len, int type, int payload_len)
{
    int i;
    //unsigned short crc;

    for (i=0; i<PREAMBLE_LEN-1; i++)
        buffer[i] = 0x0; // Preamble
    // SFD
    buffer[PREAMBLE_LEN] = 0x01;
    // Length of payload
    buffer[PREAMBLE_LEN+1] = (unsigned char) ((payload_len>>8) & 0xff);
    buffer[PREAMBLE_LEN+2] = (unsigned char) (payload_len & 0xff);
    // CRC
    //crc = crc16(buffer+PREAMBLE_LEN+SFD_LEN, MAC_HDR_LEN+payload_len);
    //buffer[buffer_len-2] = (char) ((0xff00&crc)>>8); // CRC byte 1
    //buffer[buffer_len-1] = (char) ((0x00ff&crc)); // CRC byte 2
}



static void generate_DATA_frame(struct vlc_packet *pkt)
{
    int i, payload_len, index_block, encoded_len, num_of_blocks = 0;

    payload_len = pkt->datalen + sizeof(pkt->file_id) + sizeof(pkt->seq_id);

    //encoded_len = payload_len+2*MAC_ADDR_LEN+PROTOCOL_LEN;
        
    data_buffer_byte_len = FRAME_LEN_WO_PAYLOAD/8 + payload_len ;
    
    memset (data_buffer_byte, 0, sizeof (unsigned char) * data_buffer_byte_len + CRC_LEN );
    
    data_buffer_symbol_len = (data_buffer_byte_len-PREAMBLE_LEN)*8*ENCODING_MUL + PREAMBLE_LEN*8;

    if (data_buffer_byte==NULL || data_buffer_symbol==NULL) {
        printk ("Ran out of memory generating new frames.\n");
        return;
    }
    
    // Construct a new data frame
    memcpy(data_buffer_byte+PREAMBLE_LEN, pkt->data,  pkt->datalen);
    construct_frame_header(data_buffer_byte, data_buffer_byte_len, payload_len);
    
    /// Encode the blocks of a frame
    /*for (index_block = 0; index_block < num_of_blocks; index_block++) {
        for (i = 0; i < ECC_LEN; i++)
            par[i] = 0;
        if (index_block < num_of_blocks-1) {
            encode_rs8(rs_decoder, 
                    data_buffer_byte+PREAMBLE_LEN+SFD_LEN+OCTET_LEN+index_block*block_size, 
                    block_size, par, 0);
        } else {
            encode_rs8(rs_decoder, 
                    data_buffer_byte+PREAMBLE_LEN+SFD_LEN+OCTET_LEN+index_block*block_size,
                    encoded_len%block_size, par, 0);
        }
        for (i = 0; i < ECC_LEN; i++)
            data_buffer_byte[FRAME_LEN_WO_PAYLOAD+payload_len+(index_block-1)*ECC_LEN+i] = par[i];
    }*/
    
    // Encoding the frame
    OOK_with_Manchester_RLL(data_buffer_byte, data_buffer_symbol,
                            data_buffer_byte_len);
    tx_data_curr_index = data_buffer_symbol_len;
    
}




int main()
{
   exeout = fopen("2.png", "wb");
   if (exeout == NULL) {
       perror("file open for writing");
       exit(EXIT_FAILURE);
   }

}


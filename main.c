#include "main.h"

// For DATA frame
#define DB_BYTE_LEN 2000
#define DB_SYMBOL_LEN 2000*16
static unsigned char data_buffer_byte[DB_BYTE_LEN];
static _Bool data_buffer_symbol[DB_SYMBOL_LEN];

// For ACK frame
#define ACK_BYTE_LEN 50
#define ACK_SYMBOL_LEN 50*16
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

int main()
{

   exein = fopen("1.png", "rb");
   if (exein == NULL) {
       perror("file open for reading");
       exit(EXIT_FAILURE);
   }
   exeout = fopen("2.png", "wb");
   if (exeout == NULL) {
       perror("file open for writing");
       exit(EXIT_FAILURE);
   }

   size_t n, m;
   unsigned char buff[12];
   do {
      
      n = fread(buff, 1, sizeof buff, exein);
      
      if (n)
      {
         m = fwrite(buff, 1, n, exeout);
         //printf("%s",buff);
         convertToByteStream(buff,12);

      }
      else   m = 0;
   
   } while ((n > 0) && (n == m));

   if (m) perror("copy");

   if (fclose(exeout)) perror("close output file");
   if (fclose(exein)) perror("close input file");
}


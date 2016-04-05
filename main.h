#include <stdio.h>
#include <stdlib.h>

#define BIT(x,n) (((x) >> (n)) & 1)


/////////////////////// VFTP packets /////////////////////
//TYPE 1
struct data_packet
{
	unsigned char file_id;
	unsigned int seq_id;
	unsigned int datalen; //in bytes
    u8 data[5000];
};

//TYPE 2
struct info_packet
{
	unsigned int file_id;
	unsigned int max_seq_id;
	char name_file[100];
};

////////////////////////////////////////////////////////////

//For broadcasting some requests/commands to 
struct request_packet
{
	//TBD in future
};


/* Frame format
 * -----------------------------------------------------------------
 * FIELD      | Preamble   | Type | Length   |    Payload    | CRC  |
 * BYTE/bits  | 1B         | 1B   |   2B     |   (max:255B)  |  1B  |
 * -----------------------------------------------------------------
 */
 // Here paylod is the packet


#define PREAMBLE_LEN 1 //in bytes
#define TYPE_LEN 1 
#define LENGTH_LEN 2 
#define CRC_LEN 2  

#define FRAME_LEN_WO_PAYLOAD \
    (PREAMBLE_LEN + TYPE_LEN + LENGTH_LEN) //in bytes

#define ENCODING_MUL 2 //from Manchester
#define SYMBOL_GROUP 1

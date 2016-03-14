#include <stdio.h>
#include <stdlib.h>

#define BIT(x,n) (((x) >> (n)) & 1)

struct data_packet
{
	int file_id;
	int seq_id;
	int datalen;
    u8 data[5000];
};

struct ack_packet
{
	int file_id;
	int max_seq_id;
	char name_file[100];
};

//For broadcasting some requests/commands to 
struct request_packet
{
	//TBD in future
};


/* Frame format
 * ----------------------------------------------------------
 * FIELD      | Preamble   | Type | Length  | Payload | CRC |
 * BYTE/bits  | 1B         | 2b   |   ?     |    ?    | 2   |
 * ----------------------------------------------------------
 */
 // Here paylod is the packet

#define PREAMBLE_LEN 6 //in bits
#define TYPE_LEN 2 // in bits
#define CRC_LEN 2  //in bits

#define FRAME_LEN_WO_PAYLOAD \
    (PREAMBLE_LEN+TYPE_LEN) //in bits

#define ENCODING_MUL 2

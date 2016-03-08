#include <stdio.h>
#include <stdlib.h>

#define BIT(x,n) (((x) >> (n)) & 1)

struct packet
{
	unsigned int seq_number;
	int data:12;

};

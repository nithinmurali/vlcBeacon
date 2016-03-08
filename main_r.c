#include "main.h"

//TODO modify
void convertByteToData(char* data, uint size)
{
   
  char byte[8];

   FILE *exeout;
   exeout = fopen("bytestream.txt", "a+");
   int i;
   for (i = 0; i < size; ++i)
   {
      char c = *(data + i);
      /*for (i = 0; i < 8; ++i) {
        byte[i] = (char)((c >> i) & 1);
      }*/
      //fwrite(byte, 1, sizeof(byte), exeout);
      fwrite(&c, 1, sizeof(c), exeout);
   }
   fclose(exeout);
}


int main()
{

  FILE *exein, *exeout;

   exein = fopen("bytestream.txt", "rb");
   if (exein == NULL) {
       perror("file open for reading");
       exit(EXIT_FAILURE);
   }

   exeout = fopen("3.png", "wb");
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
         //convertToByteStream(buff,12);

      }
      else   m = 0;
   
   } while ((n > 0) && (n == m));

   if (m) perror("copy");

   if (fclose(exeout)) perror("close output file");
   if (fclose(exein)) perror("close input file");
}


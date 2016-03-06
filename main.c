#include "main.h"

int main()
{

  FILE *exein, *exeout;

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
       if (n) m = fwrite(buff, 1, n, exeout);
       else   m = 0;
   } while ((n > 0) && (n == m));
   if (m) perror("copy");

   if (fclose(exeout)) perror("close output file");
   if (fclose(exein)) perror("close input file");
}
#include <stdio.h>
#include <stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *input[])
{
    FILE *a = fopen(input[1],"rb");
    FILE *b = fopen(input[2],"wb");

    BYTE x;
    while(fread(&x,sizeof(x),1,a)!=0)
    fwrite(&x,sizeof(x),1,b);
    fclose(a);
    fclose(b);
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file=fopen("phone.csv","a");
    if (file == NULL) 
    {
    perror("Error opening file");
    return 1;
    }
    char name[20];
    char number[20];
    gets(name);
    gets(number);
    fprintf(file,"%s,%s\n",name,number);
    fclose(file);
    return 0;
}
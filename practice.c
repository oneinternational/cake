#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>



int main(void)
{
    char  str[7];
    fgets(str, sizeof(str), stdin);
    printf("\n");
    fputs(str, stdout);
    return 0;
}
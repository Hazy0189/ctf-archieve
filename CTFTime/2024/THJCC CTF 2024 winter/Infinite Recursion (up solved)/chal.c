#include <stdio.h>
#include <strings.h>
#include <time.h>

void fsb()
{   
    char buf[0x10];
    printf("fsb> ");
    scanf("%15s", buf);
    printf(buf);
}
void bof()
{
    char buf[0x10];
    printf("bof> ");
    scanf("%s", buf);
}
int rand_fun()
{
    if (rand() & 1)
        fsb();
    else
        bof();
    rand_fun();
}
void main()
{
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    srand(time(0));
    printf("Try to escape haha >:)\n");
    rand_fun();
    system("/bin/sh");
}
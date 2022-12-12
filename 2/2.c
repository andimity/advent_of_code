#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    char i[4];
    FILE* input = fopen("input.txt","r");
    fgets(i,sizeof(i),input);
    printf("opponentChoice: %c, myChoice: %c\n",i[0],i[2]);
    fclose(input);
    return 0;
}

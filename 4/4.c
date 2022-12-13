#include <stdlib.h>
#include <stdio.h>
#define BUFFERSIZE      5


int get_int_from_file(FILE* inputfile){
    char digit;
    char buffer[BUFFERSIZE];
    for (uint8_t i=0; i<BUFFERSIZE; i++){  
        fgets(&buffer[i],2,inputfile);
        if(buffer[i]=='-' || buffer[i]==',' || buffer[i]=='\n'){
            break;
        }
    }
    return atoi(buffer);
}

int main(int argc, char const *argv[])
{   
    FILE* inputfile = fopen("input.txt","r");
    int start1 = get_int_from_file(inputfile);
    int end1 = get_int_from_file(inputfile);
    int start2 = get_int_from_file(inputfile);
    int end2 = get_int_from_file(inputfile);

    printf("range 1: %d - %d\n",start1,end1);
    printf("range 2: %d - %d\n",start2,end2);

    fclose(inputfile);
    return 0;
}

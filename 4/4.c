#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
    int start1,start2,end1,end2;

    do{
    start1 = get_int_from_file(inputfile);
    end1 = get_int_from_file(inputfile);
    start2 = get_int_from_file(inputfile);
    end2 = get_int_from_file(inputfile);

    if(!start1)break;

    printf("range 1: %d - %d\n",start1,end1);
    printf("range 2: %d - %d\n",start2,end2);
    } while (true);
    


    fclose(inputfile);
    return 0;
}

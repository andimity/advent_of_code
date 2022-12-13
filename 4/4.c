#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define BUFFERSIZE      5


static int get_int_from_file(FILE* inputfile){
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


static inline bool fully_contained(int start1, int end1, int start2, int end2){
    return (start1<=start2 && end2<=end1) || (start2<=start1 && end1<=end2);
}


int main(int argc, char const *argv[])
{   
    FILE* inputfile = fopen("input.txt","r");
    int start1,start2,end1,end2;
    int counter = 0;

    do{
    start1 = get_int_from_file(inputfile);
    end1 = get_int_from_file(inputfile);
    start2 = get_int_from_file(inputfile);
    end2 = get_int_from_file(inputfile);

    if(!start1)break;

    counter += fully_contained(start1,end1,start2,end2);

    // printf("%d-%d,%d-%d",start1,end1,start2,end2);
    // printf("-->%d\n",fully_contained(start1,end1,start2,end2));
    } while (true);
    
    printf("solution to part 1: %d\n",counter);

    fclose(inputfile);
    return 0;
}

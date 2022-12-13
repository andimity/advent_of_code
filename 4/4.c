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


static inline bool overlapping(int start1, int end1, int start2, int end2){
    return (end1 >= start2) && (end2>=start1);
}


int main(int argc, char const *argv[])
{   
    FILE* inputfile = fopen("input.txt","r");
    int start1,start2,end1,end2;
    int containCounter = 0;
    int overlapCounter = 0;

    do{
    start1 = get_int_from_file(inputfile);
    end1 = get_int_from_file(inputfile);
    start2 = get_int_from_file(inputfile);
    end2 = get_int_from_file(inputfile);

    if(!start1)break;

    containCounter += fully_contained(start1,end1,start2,end2);
    overlapCounter += overlapping(start1,end1,start2,end2);

    } while (true);
    
    printf("solution to part 1: %d\n",containCounter);
    printf("solution to part2: %d\n",overlapCounter);

    fclose(inputfile);
    return 0;
}

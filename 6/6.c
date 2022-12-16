#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_SIZE         4

// static bool repetition(char* buf, uint8_t len){
//     char reference = buf[0];
//     for(uint8_t i=1; i<len; i++){
//         if(buf[i] == reference) return true;
//     }
//     return false;
// }


static inline bool repetition(char* buffer){
    return (buffer[0]==buffer[1] || buffer[0]==buffer[2] || buffer[0]==buffer[3] \
        || buffer[1]==buffer[2] || buffer[1]==buffer[3] || buffer[2]==buffer[3]);
}


static void insert(char symbol, char* buffer, uint8_t length){
    static uint8_t least_recent = 0;
    buffer[least_recent] = symbol;
    least_recent++;
    if(least_recent >= length){
        least_recent = 0;
    }
}


int solve_part1(void){
    
    // declarations
    int symbolCounter = 0;
    char buffer[5];
    char next_symbol_buffer[2];
    FILE* input = fopen("input.txt","r");

    // init buffer
    fgets(buffer,sizeof(buffer),input);
    symbolCounter += WINDOW_SIZE;
    if(!repetition(buffer)){
        return symbolCounter;
    }
    // 
    while(fgets(next_symbol_buffer,sizeof(next_symbol_buffer),input) != NULL){   
        insert(next_symbol_buffer[0],buffer,WINDOW_SIZE);
        symbolCounter++;
        if(!repetition(buffer)){
            printf("marker identified: %s\n",buffer);
            return symbolCounter;
        }
    }
    fclose(input);
    return -1;
}


int main(int argc, char const *argv[])
{   
    printf("solution to part1: %d\n", solve_part1());
    printf("solution to part2: %d\n", 0);
    return 0;
}

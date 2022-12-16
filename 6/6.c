#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


static bool repetition(char* buffer, uint8_t len){
    for(uint8_t i=0; i<len; i++){
        char reference = buffer[i];
        for(uint8_t k=i+1; k<len; k++){
            if(buffer[k] == reference) return true;
        }
    }
    return false;
}


static void insert(char symbol, char* buffer, uint8_t length){
    static uint8_t least_recent = 0;
    buffer[least_recent] = symbol;
    least_recent++;
    if(least_recent >= length){
        least_recent = 0;
    }
}


int detect_start_marker(uint8_t windowSize){
    
    // declarations
    int symbolCounter = 0;
    char buffer[windowSize+1];
    char next_symbol_buffer[2];
    FILE* input = fopen("input.txt","r");

    // init buffer
    fgets(buffer,sizeof(buffer),input);
    symbolCounter += windowSize;
    if(!repetition(buffer,windowSize)){
        return symbolCounter;
    }
    // 
    while(fgets(next_symbol_buffer,sizeof(next_symbol_buffer),input) != NULL){   
        insert(next_symbol_buffer[0],buffer,windowSize);
        symbolCounter++;
        if(!repetition(buffer,windowSize)){
            printf("marker identified: %s\n",buffer);
            return symbolCounter;
        }
    }
    fclose(input);
    return -1;
}


int main(int argc, char const *argv[])
{   
    printf("solution to part1: %d\n", detect_start_marker(4));
    printf("solution to part2: %d\n", detect_start_marker(14));
    return 0;
}

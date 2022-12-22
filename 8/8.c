#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME        "test.txt"


static int count_rows(const char *filename)
{
    FILE *file = fopen(filename,"r");
    char c;
    int line_counter = 0;
    while(true){
        c = getc(file);
        if(c==EOF){
            line_counter++;
            break;
        }
        else if(c=='\n') line_counter++;
    }
    fclose(file);
    return line_counter;
}


static int count_columns(const char *filename)
{
    FILE *file = fopen(filename,"r");
    size_t len;
    fgetln(file,&len);
    fclose(file);
    return (int)len-1;
}

static uint8_t** matrix_allocate(uint16_t rows, uint16_t cols)
{   
    uint8_t **matrix = (uint8_t**) malloc(sizeof(uint8_t*) * rows * cols);
    for(uint16_t row=0; row<rows; row++){
        matrix[row] = (uint8_t*)malloc(cols);
    }

    printf("%d x %d matrix allocated\n", rows, cols);
    return matrix;
}


static void matrix_free(uint8_t** matrix, uint16_t rows)
{   
    for(uint16_t row=0; row<rows; row++){
        free((void*) matrix[row]);
    }
    free((void*) matrix);
}


static void matrix_fill(uint8_t** matrix, uint16_t rows, uint16_t cols, const char* filename)
{
    FILE *file = fopen(filename,"r");
    size_t len;
    char* line;
    for(uint16_t row=0; row<rows; row++){
        line = fgetln(file,&len);
        for(uint16_t col=0; col<cols; col++){
            matrix[row][col] = (uint8_t)line[col] - '0';
        }
    }
    printf("%d x %d matrix filled\n", rows, cols);
    fclose(file);
}


int main(int argc, char const *argv[])
{   
    uint16_t rows = count_rows(FILENAME);
    uint16_t cols = count_columns(FILENAME);
    uint8_t **forest = matrix_allocate(rows,cols);

    matrix_fill(forest,rows,cols,FILENAME);

    matrix_free(forest,rows);

    return 0;
}
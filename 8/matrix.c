#include "matrix.h"


static size_t** matrix_allocate(size_t rows, size_t cols)
{   
    size_t **matrix = (size_t**) malloc(sizeof(size_t*) * rows * cols);
    for(size_t row=0; row<rows; row++){
        matrix[row] = (size_t*)malloc(sizeof(size_t) * cols);
    }
    return matrix;
}


void matrix_free(Matrix *matrix)
{   
    for(size_t row=0; row<matrix->rows; row++){
        free((void*) matrix->data[row]);
    }
    free((void*) matrix->data);
}


static size_t count_rows(const char *filename)
{
    FILE *file = fopen(filename,"r");
    char c;
    size_t line_counter = 0;
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


static size_t count_columns(const char *filename)
{
    FILE *file = fopen(filename,"r");
    size_t len;
    fgetln(file,&len);
    fclose(file);
    return len-1;
}


static void matrix_fill(Matrix *matrix, const char* filename)
{   
    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    FILE *file = fopen(filename,"r");
    size_t len;
    char* line;
    for(size_t row=0; row<rows; row++){
        line = fgetln(file,&len);
        for(size_t col=0; col<cols; col++){
            matrix->data[row][col] = (size_t)line[col] - '0';
        }
    }
    fclose(file);
}


Matrix new_matrix_from_file(char* filename){
    Matrix new_matrix;
    new_matrix.rows = count_rows(filename),
    new_matrix.cols = count_columns(filename);
    new_matrix.data = matrix_allocate(new_matrix.rows, new_matrix.cols);
    matrix_fill(&new_matrix, filename);
    return new_matrix;
}
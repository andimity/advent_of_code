#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*generic matrix definition*/
typedef struct Matrix{
    size_t **data;
    size_t rows;
    size_t cols;
}Matrix;

Matrix new_matrix_from_file(char* filename);
void matrix_free(Matrix *matrix);

#endif
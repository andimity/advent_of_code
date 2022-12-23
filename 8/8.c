#include "matrix.h"
#include "8.h"


bool tree_is_visible(Matrix *forest, Tree tree);



int main(int argc, char const *argv[])
{   
    // uint16_t rows = count_rows(FILENAME);
    // uint16_t cols = count_columns(FILENAME);
    // uint8_t **forest = matrix_allocate(rows,cols);

    // matrix_fill(forest,rows,cols,FILENAME);

    // matrix_free(forest,rows);
    Matrix forest = new_matrix_from_file(FILENAME);
    matrix_free(&forest);

    return 0;
}
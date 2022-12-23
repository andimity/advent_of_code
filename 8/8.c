#include "./8/matrix.h"
#include "./8/8.h"


bool tree_is_visible(Matrix *forest, Tree tree);



int main(int argc, char const *argv[])
{   
    Matrix forest = new_matrix_from_file(FILENAME);
    matrix_free(&forest);

    return 0;
}
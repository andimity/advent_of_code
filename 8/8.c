#include "matrix.h"
#include "8.h"


static inline bool tree_is_on_the_edge(Matrix *forest, Tree tree){
    return (tree.col == forest->cols-1 || tree.col == 0 || tree.row == forest->rows-1 || tree.row == 0);
}


static bool tree_visible_from_north(Matrix *forest, Tree tree){
    size_t colIndex = tree.col;
    size_t rowIndex = tree.row;
    while(rowIndex > 0){
        rowIndex--;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            return false;
        }
    }
    // printf("(%d,%d) visible from north\n",tree.row, tree.col);
    return true;
}


static bool tree_visible_from_south(Matrix *forest, Tree tree){
    size_t colIndex = tree.col;
    size_t rowIndex = tree.row+1;
    while(rowIndex < forest->rows){
        if(forest->data[rowIndex][colIndex] >= tree.height){
            return false;
        }
        rowIndex++;
    }
    // printf("(%d,%d) visible from south\n",tree.row, tree.col);
    return true;
}


static bool tree_visible_from_east(Matrix *forest, Tree tree){
    size_t rowIndex = tree.row;
    size_t colIndex = tree.col+1;
    while(colIndex < forest->cols){
        if(forest->data[rowIndex][colIndex] >= tree.height){
            return false;
        }
        colIndex++;
    }
    // printf("(%d,%d) visible from east\n",tree.row, tree.col);
    return true;
}


static bool tree_visible_from_west(Matrix *forest, Tree tree){
    size_t rowIndex = tree.row;
    size_t colIndex = tree.col;
    while(colIndex > 0){
        colIndex--;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            return false;
        }
    }
    // printf("(%d,%d) visible from west\n",tree.row, tree.col);
    return true;
}


static inline bool tree_is_visible(Matrix *forest, Tree tree){
    return (\
        tree_is_on_the_edge(forest,tree) \
        || tree_visible_from_north(forest,tree) \
        || tree_visible_from_south(forest,tree) \
        || tree_visible_from_east(forest,tree) \
        || tree_visible_from_west(forest,tree) \
        );
}


static int count_visible_trees(Matrix *forest){
    int counter = 0;
    for(size_t row=0; row<forest->rows; row++){
        for(size_t col=0; col<forest->cols; col++){
            Tree tree = {
                .row = row,
                .col = col,
                .height = forest->data[row][col],
            };
            if(tree_is_visible(forest,tree)){
                counter++;
            }
        }
    }
    return counter;
}


static int scenic_score_north(Matrix *forest, Tree tree){
    int scenic_score = 0;
    size_t colIndex = tree.col;
    size_t rowIndex = tree.row;
    while(rowIndex > 0){
        scenic_score++;
        rowIndex--;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            break;
        }
    }
    return scenic_score;
}


static int scenic_score_south(Matrix *forest, Tree tree){
    int scenic_score = 0;
    size_t colIndex = tree.col;
    size_t rowIndex = tree.row+1;
    while(rowIndex < forest->rows){
        scenic_score++;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            break;
        }
        rowIndex++;
    }
    return scenic_score;
}


static int scenic_score_east(Matrix *forest, Tree tree){
    int scenic_score = 0;
    size_t rowIndex = tree.row;
    size_t colIndex = tree.col+1;
    while(colIndex < forest->cols){
        scenic_score++;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            break;
        }
        colIndex++;
    }
    return scenic_score;
}


static int scenic_score_west(Matrix *forest, Tree tree){
    int scenic_score = 0;
    size_t rowIndex = tree.row;
    size_t colIndex = tree.col;
    while(colIndex > 0){
        scenic_score++;
        colIndex--;
        if(forest->data[rowIndex][colIndex] >= tree.height){
            break;
        }
    }
    return scenic_score;
}


static int scenic_score(Matrix *forest, Tree tree){
    return ( \
        scenic_score_north(forest, tree)
        * scenic_score_south(forest, tree)
        * scenic_score_east(forest, tree)
        * scenic_score_west(forest, tree)
    );
}


static int maximal_scenic_score(Matrix *forest){
    int maximal_scenic_score = 0;
    for(size_t row=0; row<forest->rows; row++){
        for(size_t col=0; col<forest->cols; col++){
            Tree tree = {
                .row = row,
                .col = col,
                .height = forest->data[row][col],
            };
            int score = scenic_score(forest, tree);
            // printf("(%zu,%zu) -> %d\n",row,col,score);
            if(score > maximal_scenic_score){
                maximal_scenic_score = score;
            }
        }
    }
    return maximal_scenic_score;
}


int main(int argc, char const *argv[])
{   
    Matrix forest = new_matrix_from_file(FILENAME);
    printf("part one, visible trees: %d\n",count_visible_trees(&forest));
    printf("part two, highest scenic score: %d\n",maximal_scenic_score(&forest));
    matrix_free(&forest);
    return 0;
}
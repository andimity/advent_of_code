#include <stdio.h>
#include <stdlib.h>


static int shape_score(char shape){
    switch (shape)
    {
    case 'X': return 1; break; // Rock
    case 'Y': return 2; break; // Paper
    case 'Z': return 3; break; // Sciccor
    default: printf("unknown symbol for shape"); return -1; break;
    }
}

static int outcome_score(char opponentChoice, char myChoice){
    switch (opponentChoice){
    case 'A': // Rock
        switch (myChoice){
        case 'X': return 3; break; // Rock -> Draw
        case 'Y': return 6; break; // Paper -> Win
        case 'Z': return 0; break; // Sciccor -> Lose
        default: printf("unknown symbol for my choice"); return -1; break;
        }
    case 'B': // Paper
        switch (myChoice){
        case 'X': return 0; break; // Rock -> Lose
        case 'Y': return 3; break; // Paper -> Draw
        case 'Z': return 6; break; // Sciccor -> Win
        default: printf("unknown symbol for my choice"); return -1; break;
        }
    case 'C': // Sciccor
        switch (myChoice){
        case 'X': return 6; break; // Rock -> Win
        case 'Y': return 0; break; // Paper -> Lose
        case 'Z': return 3; break; // Sciccor -> Draw
        default: printf("unknown symbol for my choice"); return -1; break;
        }
    default: printf("unknown symbol for opponent choice"); return -1;
    }
}


static inline int calculate_score(char opponentChoice, char myChoice){
    return outcome_score(opponentChoice, myChoice) + shape_score(myChoice);
}


int main(int argc, char const *argv[])
{   
    char i[5];
    FILE* input = fopen("input.txt","r");
    while(fgets(i,sizeof(i),input) != NULL){        
        printf("opponentChoice: %c, myChoice: %c\n",i[0],i[2]);
        printf("score: %d\n", calculate_score(i[0],i[2]));
    }
    fclose(input);
    return 0;
}

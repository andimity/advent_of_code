#include <stdio.h>
#include <stdlib.h>


static int shape_score(char shape){
    switch (shape)
    {
    case 'X': return 1; break; // Rock
    case 'Y': return 2; break; // Paper
    case 'Z': return 3; break; // Sciccor
    default: printf("unknown symbol for shape: %c\n",shape); return -1; break;
    }
}

static int outcome_score_1(char opponentChoice, char myChoice){
    switch (opponentChoice){
    case 'A': // Rock
        switch (myChoice){
        case 'X': return 3; break; // Rock -> Draw
        case 'Y': return 6; break; // Paper -> Win
        case 'Z': return 0; break; // Sciccor -> Lose
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    case 'B': // Paper
        switch (myChoice){
        case 'X': return 0; break; // Rock -> Lose
        case 'Y': return 3; break; // Paper -> Draw
        case 'Z': return 6; break; // Sciccor -> Win
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    case 'C': // Sciccor
        switch (myChoice){
        case 'X': return 6; break; // Rock -> Win
        case 'Y': return 0; break; // Paper -> Lose
        case 'Z': return 3; break; // Sciccor -> Draw
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    default: printf("unknown symbol for opponent choice: %c\n",opponentChoice); return -1;
    }
}


static inline int calculate_score_1(char opponentChoice, char myChoice){
    return outcome_score_1(opponentChoice, myChoice) + shape_score(myChoice);
}


static int calculate_score_2(char opponentChoice, char myChoice){
    switch (opponentChoice){
    case 'A': // Rock
        switch (myChoice){
        case 'X': return 0+3; break; // Lose -> Sciccor
        case 'Y': return 3+1; break; // Draw -> Rock
        case 'Z': return 6+2; break; // Win -> Paper
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    case 'B': // Paper
        switch (myChoice){
        case 'X': return 0+1; break; // Lose -> Rock
        case 'Y': return 3+2; break; // Draw -> Paper
        case 'Z': return 6+3; break; // Win -> Sciccor
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    case 'C': // Sciccor
        switch (myChoice){
        case 'X': return 0+2; break; // Lose -> Paper
        case 'Y': return 3+3; break; // Draw -> Sciccor
        case 'Z': return 6+1; break; // Win -> Rock
        default: printf("unknown symbol for my choice: %c\n",myChoice); return -1; break;
        }
    default: printf("unknown symbol for opponent choice: %c\n",opponentChoice); return -1;
    }
}


int main(int argc, char const *argv[])
{   
    int score1 = 0;
    int score2 = 0;
    char opponentChoice;
    char myChoice;
    char buffer[5];
    FILE* input = fopen("input.txt","r");
    while(fgets(buffer,sizeof(buffer),input) != NULL){   
        opponentChoice = buffer[0];
        myChoice = buffer[2];
        score1 += calculate_score_1(opponentChoice, myChoice);
        score2 += calculate_score_2(opponentChoice, myChoice);
    }
    fclose(input);
    printf("total score part1: %d\n",score1);
    printf("total score part2: %d\n",score2);
    return 0;
}

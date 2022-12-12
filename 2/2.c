#include <stdio.h>
#include <stdlib.h>


int outcome_score(char opponentChoice, char myChoice){
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

int main(int argc, char const *argv[])
{   
    char i[4];
    FILE* input = fopen("input.txt","r");
    fgets(i,sizeof(i),input);
    printf("opponentChoice: %c, myChoice: %c\n",i[0],i[2]);
    printf("outcome score: %d\n", outcome_score(i[0],i[2]));
    fclose(input);
    return 0;
}

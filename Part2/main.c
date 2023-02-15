#include <stdio.h>
#include <stdlib.h>

#define TDC 8 // TD conversion
#define TDE 7 // TD extra point
#define TD 6 // TD without extra point
#define FG 3 // field goal
#define SAFETY 2 // safety

void calcScore(int score) {
    for(int tdc = 0; tdc <= score/TDC; tdc++){ // TD conversion for 8
        for(int tde = 0; tde <= score/TDE; tde++) { // TD extra point for 7
            for (int td = 0; td <= score/TD; td++) { // TD without extra point for 6
                for (int fg = 0; fg <= score/FG; fg++) { // field goal for 3
                    for (int safety = 0; safety <= score/SAFETY; safety++) { // safety for 2
                        if (tdc*TDC + tde*TDE + td*TD + fg*FG + safety*SAFETY == score) { //Make sure the score is correct
                                printf("%d 'TD + 2', %d 'TD + 1', %d 'TD', %d 'FG', %d 'Safety'\n",tdc,tde, td, fg, safety); //Print the combination
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <score>\n", argv[0]);
        return 1;
    }
    int score = atoi(argv[1]);
    calcScore(score);
    return 0;
}

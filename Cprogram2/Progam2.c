/*
 * Progam2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Manoj Turaga
 */
#include <stdio.h>

void scores(int score)
{
    if(score >= 1)
    {
        printf("Possible combinations of scoring plays:\n");
        for(int two_pt = 0; two_pt <= score / 8; two_pt++)
        {
            for(int one_pt = 0; one_pt <= (score - two_pt*8) / 7; one_pt++)
            {
                for(int tds = 0; tds <= (score - two_pt*8 - one_pt*7)/6; tds++)
                {
                    for(int fgs = 0; fgs <= (score - two_pt*8 - one_pt*7 - tds*6) / 3; fgs++)
                    {
                        for(int sfts = 0; sfts <= (score - tds*6 - two_pt*8 - one_pt*7 - fgs*3) / 2; sfts++)
                        {
                            if(tds*6 + two_pt*8 + one_pt*7  + fgs*3 + sfts*2 == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", two_pt, one_pt, tds, fgs, sfts);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score;
    while(1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        fflush(stdout);  //This line is necessary since Eclipse only prints stuff once program terminates
        scanf("%d", &score);
        if(score == 0 || score == 1)
        {
            break;
        }
        scores(score);
        printf("\n");
    }
    return 0;
}



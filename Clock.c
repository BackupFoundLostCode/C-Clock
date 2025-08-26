#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>

int main(){

    system("color 02");
    while (true) {
        int hour = 0;
        int min = 0;
        int sec = 0;

        printf("How much Hours, Min and Sec ?:\n");
        if (scanf("%u %u %u", &hour, &min, &sec )!= 3) {
            printf("ERROR!\n");
            return 1;
        }
        if (hour < 0 || min < 0 || sec <0) {
            printf("ERROR! Numer = (-)\n");
            continue;
        }
        printf("Hour: %u Min: %u Sec: %u\n", hour, min, sec);

        while (hour > 0 || min > 0 || sec > 0) {
            sleep(1);

            if (sec > 0) {
                sec--;
            } else {
                if (min > 0) {
                    min--;
                    sec = 59;
                } else if (hour > 0) {
                    hour--;
                    min = 59;
                    sec = 59;
                }
            }
            printf("\rHour: %d Min: %d Sec: %d\n", hour, min, sec);
            fflush(stdout);
        }
        int countdown = 0;
        bool your = true;
        while (your) {
            printf("\a");
            sleep(2);
            countdown++;
            if (countdown == 15) {
                your=false;
            }
        }
        printf("BOOMM!!\n");
        printf("Exit Programm? x for EXIT.\n");
        char ending;
        scanf(" %c", &ending);
        if (ending == 'x') {
            printf("EXIT Programm\n");
            exit(0);
        }
    }
}

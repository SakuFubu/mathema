#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double T = 0;           //時刻0の時の水位(m)
    double Y = 1;           //初期状態：時刻0
    double PI = 3.14159;    //円周率の下五桁まで

//初期状態
    printf("t= %.1lf y= %.1lf\n",T,Y);

//0<=t<=1.5で、0.1秒ごとの水位の変化を求める
    for(int i = 1; i <= 15; i++){
        T = T + 0.1;
        Y = sqrt(1 - (2 * T) / PI);

        printf("t= %.1lf y= %.3lf\n",T,Y);
    }

    return 0;
}
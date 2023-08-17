#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    double T = 0;   //初期状態：時刻0
    double Y = 1;   //時刻0の時の水位(m)

//初期状態
    printf("t= %.1lf y= %.3lf\n",T,Y);  

//0<=t<=2で、0.1秒ごとの水位の変化を求める
    for(int i = 1; i <= 20; i++){
        T = T + 0.1;
        Y = exp(((-25) * T) / (32 * 3.14159));

//t秒後の高さyを出力する
        printf("t= %.1lf y= %.3lf\n",T,Y);
    }

    return 0;
}
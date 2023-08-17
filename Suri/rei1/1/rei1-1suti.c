#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    double R = 0.8;     //円柱のタンクの半径
    double A = 0.5;     //公式v = ay の比例定数
    double PI = 3.14159;    //円周率の下五桁まで
    double DT = 0.1;    //微小時間
    double Y = 1;   //時刻0の時の水位(m)
    double T = 0;   //初期状態：時刻0

//初期状態
    printf("t= %.1lf y= %.1lf\n",T,Y);

//0<=t<=2で、0.1秒ごとの水位の変化を求める
    for(int i = 1; i <= 20; i++){
        Y = Y - (A * Y * DT) / (PI * R * R);
        printf("t= %.1lf y= %lf\n", i*DT, Y);
    }
    
    return 0;
}
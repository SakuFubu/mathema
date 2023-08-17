#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double A = 1;           //公式v = ay の比例定数
    double PI = 3.14159;    //円周率の下五桁まで
    double DT = .0001;      //微小時間
    double Y = 1;           //時刻0の時の水位(m)
    double T = 0;           //初期状態：時刻0

//初期状態
    printf("t= %.1lf y= %.1lf\n",T,Y);

//0<=t<=1.5で、0.0001秒ごとの水位の変化を求める
    for(int i = 1; i <= 15000; i++){
        Y = Y - (A * Y * DT) / (PI * sin(Y) * sin(Y));
        double Y1 = (Y * 1000) / 1000;

        //yが0以下の時ループを終わって、前の値を出力する
        if(Y < 0){
            printf("t= %.3lf y= 0\n", ((double)(i-1)/10000));
            break;
        }

        //iの値が一致した時出力する
        if(i == ((int)(i / 1000) * 1000)){
            printf("t= %.1lf y= %.3lf\n", T+i*DT,Y1);
        }
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double A = 1;           //公式v = ay の比例定数
    double PI = 3.14159;    //円周率の下五桁まで
    double DT = .001;       //微小時間
    double Y = 1;           //時刻0の時の水位(m)
    double T = 0;           //初期状態：時刻0

//初期状態
    printf("t= %.1lf y= %.1lf\n",T,Y);

//0<=t<=1.5で、0.001秒ごとの水位の変化を求める
    for(int i = 1; i <= 1500; i++){

        Y = Y - (A * DT) / (PI * Y);

        double Y1 = (1000 * Y) / 1000;

        //iの値が一致した時出力する
        if(i == ((int)(i / 100) * 100)){
            printf("t= %.1lf y= %.3lf\n",i*DT,Y1);
        }
    }
    return 0;
}
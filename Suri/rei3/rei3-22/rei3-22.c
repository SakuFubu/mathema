#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    double a = 0.1;
    double t = 0;
    double Xmax = 4;
    double Ymax = 4;
    double Zmax = 15;
    double Tmax = 16;         // 何秒まで
    double Z[41][41];
    double displace[41][41];
    double dx = Xmax/40;
    double dy = Ymax/40;
    double dt = 0.01;

    int n = 0;
    FILE *fpout;

    for(int i = 0;i <= 40;i++){             // 初期化
        for(int j = 0;j <= 40;j++){
            if(20 <= i && i <= 30 && 20 <= j && j <= 30){        // 初期条件
                Z[i][j] = 15;
            }else{
                Z[i][j] = 0;
            }
        }
    }
    
    n = Tmax*100;       // Tmax = 16
    for(int k = 1; k <= n; k++){
        if(t == 0){                         // t = 0
            fpout = fopen("data0.txt","w");
            fprintf(fpout,"# z = , (t = 0)\n");
            for(int j = 1;j <= 40;j++){
                for(int i = 1;i <= 40;i++){
                    fprintf(fpout,"%lf \n",Z[i][j]);
                }
            }
        }
        for(int j = 1;j <= 39;j++){         // 各時間における、それぞれのタンクの水位を求める
            for(int i = 1;i <= 39;i++){
                displace[i][j] = Z[i][j] + 
                    a*(Z[i+1][j] + Z[i-1][j] + Z[i][j+1] + Z[i][j-1] - 4*Z[i][j])*dt/pow(dx,2);
            }
        }
        for(int j = 1;j <= 39;j++){         // 結果の反映
            for(int i = 1;i <= 39;i++){
                Z[i][j] = displace[i][j];
            }
        }
        for(int i = 1;i <= 39;i++){         // 断熱条件
            Z[i][0] = Z[i][1];              // 境界上の点とその一列内側の点の温度を等しくした
            Z[i][40] = Z[i][39];
            Z[0][i] = Z[1][i];
            Z[40][i] = Z[39][i];
        }
        Z[0][0] = Z[1][1];
        Z[0][40] = Z[1][39];
        Z[40][0] = Z[39][1];
        Z[40][40] = Z[39][39];
        switch(k){
            case 50:            // t = 0.5
                fpout = fopen("data1.txt","w");
                fprintf(fpout,"# z = , (t = 0.5)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 100:           // t = 1
                fpout = fopen("data2.txt","w");
                fprintf(fpout,"# z = ,(t = 1)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 200:           // t = 2
                fpout = fopen("data3.txt","w");
                fprintf(fpout,"# z = ,(t = 2)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 400:           // t = 4
                fpout = fopen("data4.txt","w");
                fprintf(fpout,"# z = ,(t = 4)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 800:           // t = 8
                fpout = fopen("data5.txt","w");
                fprintf(fpout,"# z = ,(t = 8)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 1600:           // t = 16
                fpout = fopen("data6.txt","w");
                fprintf(fpout,"# z = ,(t = 16)\n");
                for(int j = 1;j <= 40;j++){
                    for(int i = 1;i <= 40;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            default:
                t = t + dt;
        }

        
    }
    fclose(fpout);
    return 0;
}

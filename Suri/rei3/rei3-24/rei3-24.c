#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    double a = 0.1;
    double t = 0;
    double Xmax = 6;
    double Ymax = 6;
    double Zmax = 20;
    double Tmax = 32;         // 何秒まで
    double Z[61][61];
    double displace[61][61];
    double dx = Xmax/60;
    double dy = Ymax/60;
    double dt = 0.01;

    int n = 0;
    FILE *fpout;

    for(int i = 0;i <= 60;i++){             // 初期化
        for(int j = 0;j <= 60;j++){
            if(10 <= i && i <= 25 && 0 <= j && j <= 20){        // 初期条件
                Z[i][j] = 20;
            }
            else if(i+j > 60){      // x+y <= 6 を満たさない範囲を強調表示
                Z[i][j] = -5;
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
            for(int j = 1;j <= 60;j++){
                for(int i = 1;i <= 60;i++){
                    fprintf(fpout,"%lf \n",Z[i][j]);
                }
            }
        }
        for(int i = 1;i <= 58;i++){         // 各時間における、それぞれのタンクの水位を求める
            for(int j = 1;j <= 59-i;j++){
                displace[i][j] = Z[i][j] + 
                    a*(Z[i+1][j] + Z[i-1][j] + Z[i][j+1] + Z[i][j-1] - 4*Z[i][j])*dt/pow(dx,2);
            }
        }
        for(int i = 0;i <= 58;i++){         // 結果の反映
            for(int j = 0;j <= 59-i;j++){
                Z[i][j] = displace[i][j];
            }
        }
        for(int i = 1;i <= 58;i++){          // 断熱条件より
            Z[i][0] = Z[i][1];
            Z[0][i] = Z[1][i];
            Z[i][60-i] = Z[i][59-i];
        }
        Z[0][0] = Z[1][1];                    // 境界線上の点の温度を一列内側のものと同じに
        Z[0][59] = Z[1][58];
        Z[0][60] = Z[1][58];
        Z[59][0] = Z[58][1];
        Z[59][1] = Z[58][1];
        Z[60][0] = Z[58][1];
        switch(k){
            case 50:            // t = 0.5
                fpout = fopen("data1.txt","w");
                fprintf(fpout,"# z = , (t = 0.5)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 100:           // t = 1
                fpout = fopen("data2.txt","w");
                fprintf(fpout,"# z = ,(t = 1)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 200:           // t = 2
                fpout = fopen("data3.txt","w");
                fprintf(fpout,"# z = ,(t = 2)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 400:           // t = 4
                fpout = fopen("data4.txt","w");
                fprintf(fpout,"# z = ,(t = 4)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 800:           // t = 8
                fpout = fopen("data5.txt","w");
                fprintf(fpout,"# z = ,(t = 8)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 1600:           // t = 16
                fpout = fopen("data6.txt","w");
                fprintf(fpout,"# z = ,(t = 16)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
                        fprintf(fpout,"%lf \n",Z[i][j]);
                    }
                }
                t = t + dt;
                break;

            case 3200:           // t = 32
                fpout = fopen("data7.txt","w");
                fprintf(fpout,"# z = ,(t = 16)\n");
                for(int j = 1;j <= 60;j++){
                    for(int i = 1;i <= 60;i++){
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

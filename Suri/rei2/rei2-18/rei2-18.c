#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int FNU(double, double, double);
int FNV(double, double, double);

int main(){
    double dx = 0.01;
    double t = 0;
    double dt = 0.00001;
    double Y[101];
    int n = 0;
    FILE *fpout;

    for(int i = 0;i <= 100;i++){
        if(i >= 25 && i <= 50){
            Y[i] = 12;
        }else if(i >= 75 && i <= 90){
            Y[i] = 7;
        }else{
            Y[i] = 0;
        }
    }
    

    n = 6400;
    for(int k = 1; k <= n; k++){
        if(t == 0){
            fpout = fopen("data0.txt","w");
            fprintf(fpout,"# x = , y = ,(t = 0.000)\n");
            for(int l = 1;l <= 100;l++){
                fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
            }
        }
        for(int i = 1; i <= 99; i++){
            Y[i] = Y[i] + ((Y[i+1] - 2*Y[i] + Y[i-1])*dt)/pow(dx,2);
        }
        Y[0]=Y[1];
        Y[100]=Y[99];
        switch(k){
            case 100:
                fpout = fopen("data1.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.001)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 200:
                fpout = fopen("data2.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.002)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 400:
                fpout = fopen("data3.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.004)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 800:
                fpout = fopen("data4.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.008)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 1600:
                fpout = fopen("data5.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.016)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 3200:
                fpout = fopen("data6.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.032)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 6400:
                fpout = fopen("data7.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.064)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 12800:
                fpout = fopen("data8.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.064)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
                }
                t = t + dt;
                break;

            case 25600:
                fpout = fopen("data9.txt","w");
                fprintf(fpout,"# x = , y = ,(t = 0.064)\n");
                for(int l = 1;l <= 100;l++){
                    fprintf(fpout,"%lf %lf\n",l*dx,Y[l]);
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

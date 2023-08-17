#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int FNU(double, double, double);
int FNV(double, double, double);

int main(){
    double Xmax = 1.2;
    double Xmin = -0.2;
    double dx = 0.01;
    double Delx = 0.5;
    double t = 0;
    double dt = 0.00001;
    double a = 0.5;
    double Ymax = 12;       
    double Ymin = -2;      
    double DelY = 2;
    double Y[101];
    int n = Ymax/DelY;
    int m = (-Ymin)/DelY;

    printf("# x = , y = (t = 0.001, 0.002, 0.004, 0.008, 0.016, 0.032, 0.064)\n");
    for(int l = 1;l <= 100;l++){
        printf("%lf ",l*dx);
    }
    printf("\n\n");

    for(int i = 1;i <= 100;i++){
        if(i <= 50){
            Y[i] = 10;
        }else{
            Y[i] = 0;
        }
    }
    Y[0] = 0;
    n = 6400;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= 99; i++){
            Y[i] = Y[i] + ((Y[i+1] - 2*Y[i] + Y[i-1])*dt)/(dx*dx);
        }
        t = t + dt;
        for(int j = 0;j <= 6;j++){
            if(k == pow(2,j)*100){
                for(int l = 1;l <= 100;l++){
                    printf("%lf ",Y[l]);
                }
                printf("\n");
            }
        }
        
    }
    return 0;
}

int FNU(double x, double xmin, double xmax){
    return ((640 * (x - xmin)) / (xmax - xmin));
}

int FNV(double y, double ymin, double ymax){        
    return ((400 * (ymax - y)) / (ymax - ymin));
}
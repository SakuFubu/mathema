#include<stdio.h>
#include<stdlib.h>

int FNU(double, double, double);
int FNV(double, double, double);

int main(){
    double Tmax = 8;
    double Tmin = -1;
    double t = 0;
    double a = 0.5;
    double R1 = 1;
    double R2 = 1;
    double R3 = 1;
    double Ymax = 22;       //今回は使わない
    double Ymin = -3;       // -3 <= y <= 22
    double Y1 = 8;
    double Y2 = 20;
    double Y3 = 2;
    int U0 = FNU(0,Tmin,Tmax);
    double dt = Tmax / (640-U0);

    printf("# t = , y1 = , y2 = , y3 =\n");

    for(int i = U0;i <= 640;i++){
        printf("%lf %lf %lf %lf\n",t,Y1,Y2,Y3);
        Y1 = Y1 + (a*(Y2-Y1)*dt)/(R1*R1);
        Y2 = Y2 + (a*(Y1-2*Y2+Y3)*dt)/(R2*R2);
        Y3 = Y3 + (a*(Y2-Y3)*dt)/(R3*R3);
        t = t + dt;
    }

    return 0;
}

int FNU(double t, double tmin, double tmax){
    return ((640 * (t - tmin)) / (tmax - tmin));
}

int FNV(double y, double ymin, double ymax){        //今回は使わない
    return ((400 * (ymax - y)) / (ymax - ymin));
}
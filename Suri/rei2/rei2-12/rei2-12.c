#include<stdio.h>
#include<stdlib.h>

int FNU(double, double, double);
int FNV(double, double, double);

int main(){
    double Tmax = 8;
    double Tmin = -1;
    double t = 0;
    double a = 0.5;
    double S = 1;
    double Ymax = 22;       //今回は使わない
    double Ymin = -3;       // -3 <= y <= 22
    double Y[8] = {0,3,10,6,7,2,8,0};
    Y[0] = Y[1];
    Y[7] = Y[6];
    int U0 = FNU(0,Tmin,Tmax);
    double dt = Tmax / (640-U0);

    printf("# t = , y1 = , y2 = , y3 = , y4 = , y5 = , y6 = \n");
    printf("%lf %lf %lf %lf %lf %lf %lf\n",t,Y[1],Y[2],Y[3],Y[4],Y[5],Y[6]);

    for(int i = U0; i <= 640; i++){
        for(int j = 1; j <= 6; j++){
            Y[j] = Y[j] + (a*(Y[j+1] - 2*Y[j] + Y[j-1])*dt)/S;
        }
        t = t + dt;
        printf("%lf %lf %lf %lf %lf %lf %lf\n",t,Y[1],Y[2],Y[3],Y[4],Y[5],Y[6]);
        Y[0] = Y[1];
        Y[7] = Y[6];
    }
    return 0;
}

int FNU(double t, double tmin, double tmax){
    return ((640 * (t - tmin)) / (tmax - tmin));
}

int FNV(double y, double ymin, double ymax){        //今回は使わない
    return ((400 * (ymax - y)) / (ymax - ymin));
}
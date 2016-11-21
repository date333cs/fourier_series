#include <stdio.h>
#include <math.h>

int N = 100; /* 何項目まで足すか */
double delta_t = 0.01; 
double start = -2.0*M_PI;   /* 横軸はじまり */
double end   =  2.0*M_PI;   /* 横軸おわり */

int main()
{
    
    int i;
    double t, f, y;
    
    for ( t = start; t < end;  t += delta_t ){
        
        y=0.0;
        for ( i = 1; i <= N; i++ ){
            y += 2.0*pow(-1.0, (double)(i+1)) * sin((double)(i*t))/(double)i;
        }
        
    printf("%.3lf \t %.3lf\n",t, y);
    }

    return 0;
}

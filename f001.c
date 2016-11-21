#include <stdio.h>
#include <math.h>

int main()
{

    double t;
    double delta_t = 0.01; 
    double start = -2.0*M_PI;   /* 横軸はじまり */
    double end   =  2.0*M_PI;   /* 横軸おわり */

    for ( t = start; t < end;  t+=delta_t ){
        printf("%.3lf \t %.3lf\n",t, 2.0*sin(t));
    }

    return 0;
}

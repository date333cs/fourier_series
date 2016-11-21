/* 
   violine.c

   A.Date 2011.11.1 

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIM 100000
#define MAX_K   300

char data_file1[] = "do_violine.dat";   /* データ：バイオリンの「ド」 */
int K = 30;             /* 項数．何項目まで足すか． この値を変える．*/
int start_i = 3000;     /* フーリエ級数展開開始位置．0 < i < 31000．変えて試す */
double delta_t = 0.01;

double f[MAX_DIM];
double a[MAX_K], b[MAX_K];

int read_data();        /* データをファイルから読み込む関数．気にしなくてよい */
double start = -M_PI;   /* 横軸はじまり */
double end   =  M_PI;   /* 横軸おわり */

int main (int argc, char *argv[] ){
    int i, k, n;
    double pi = M_PI;
    double fk;
    double t, y;
    int end_i = start_i + 628;

    n = read_data();
//    printf("There are %d data\n", n);

    for ( k=0; k<K; k++ ){
        a[k] = 0.0;
        b[k] = 0.0;
    }

    i = start_i;
    for ( t = start; t < end;  t+=delta_t ){

        a[0] += f[i];
        for ( k = 1; k <= K;  k++ ){
            a[k] += f[i]*cos( t*(double)k ) ;
            b[k] += f[i]*sin( t*(double)k ) ;
        }
        i++;
    }

    for ( k = 0; k <= K;  k++ ){
        a[k] = a[k] * delta_t*sqrt(2.0)/pi;
        b[k] = b[k] * delta_t*sqrt(2.0)/pi;
    }    


    i = start_i;
    for ( t = start; t < end;  t+=delta_t ){

        y = a[0]/2.0;
        for ( k = 1; k <= K;  k++ ){
            y +=  a[k] * cos( t* (double)k );
            y +=  b[k] * sin( t* (double)k );
        }    
        printf("%.5lf \t %.5lf \t %.5lf\n", t, f[i], y);
        i++;
    }
//    printf("n = %d  ( 628?) \n", i-start_i);
    
}


int read_data(){
    int i, n;
    int data;
    FILE *fp;

    fp = fopen(data_file1, "r");
    if (fp == NULL){
        fprintf(stderr, "Can't open data file: %s\n",data_file1);
        exit(-1);
    } 
    
    i=0;
    while( (n=fscanf(fp, "%d", &data) != EOF ) ){
        if( n == 1 ){
            f[i]=(double)data;
            i++;
        } 
        else{
            fprintf(stderr, "Something wrong in data1.\n");
            exit(-1);
        }
    }
    fclose(fp); 
    
    return(i);
}

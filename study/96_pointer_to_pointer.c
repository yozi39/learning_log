#include<stdio.h>
int main(){
    double num=8.8;
    double *ptr1=&num;
    double **ptr2=&ptr1;
    printf("before:%.2lf\n",num);
    **ptr2=88.88;    
    printf("now:%.2lf",num);
}
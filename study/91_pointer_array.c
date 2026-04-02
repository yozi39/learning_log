#include<stdio.h>
int main(){
    double num_1,num_2,num_3;
    double num[3];
    double sum = 0,average;
    double *ptr_arr[3];
    for(int i=0;i<=2;i++){
        double number;
        printf("请输入第%d个数",i+1);
        scanf("%lf",&number);
        num[i]=number;
    }
    for(int i = 0; i < 3; i++){
        ptr_arr[i]=&num[i];
    }
    for(int i=0;i<=2;i++){
        sum+=*ptr_arr[i];
    }
    average=sum/3;
    printf("和是:%.2lf;平均数是:%.2lf",sum,average);
}
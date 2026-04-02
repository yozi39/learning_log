#include<stdio.h>

int main(){
    float float_1 = 11.27;
    float float_2 = 11.12345678910;
    double double_1=11.12345678910;
    printf("float_1=%f\n",float_1);
    printf("float_2=%f",float_2);
    printf("\ndouble_1=%.10lf",double_1);
    printf("\nfloat_2=%.10f",float_2);
    int a = 1;
    printf("\n我是%d",a);
    char b = '\n';
    printf("\n%c",b);
    return 0;
}
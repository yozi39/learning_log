/*
    题目内容提取：
定义一个 int 类型变量 num_1，初始值为 8。
定义一个 char 类型变量 ch，初始值为 'e'。
定义一个 float 类型变量 num_2，初始值为 1.23。
定义一个 double 类型变量 num_3，初始值为 4.98。
定义一个 double 类型变量 result 来存储计算结果。
将变量 ch 转换为 double 类型，并与 num_1 相加，将结果赋值给 result，并打印出结果。
将 num_2 和 num_3 相加的结果转换为 int 类型，赋值给 result，并打印出结果。
打印格式：计算结果为 __
*/

#include<stdio.h>

int main(){
    int num_1 = 8;
    char ch = 'e';
    float num_2 = 1.23;
    double num_3 = 4.98;
    double result;
    result = (double) ch + num_1;
    printf("第一个值是：%lf\n",result);
    result = (int)(num_2 + num_3);
    printf("第二个结果是：%lf\n",result);
    return 0;
}
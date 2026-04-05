#include"121_include_exercise_func.h"
#include<stdio.h>

int main(){
    int sum=0;
    int result=0;
    sum=ADD(3,5);
    result=square(sum);
    printf("%d",result);
}
//启动 gcc 121_include_exercise.c 121_include_exercise_func.c -o gggg && .\gggg

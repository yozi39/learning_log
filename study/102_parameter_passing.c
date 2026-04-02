#include<stdio.h>
void pass_by_value(int a){
    a +=10;
    printf("in the function:%d\n",a);
}

void pass_by_pointer(int *a){
    *a += 10;
}

int main(){
    int num=10;
    printf("before:%d\n",num);
    pass_by_value(num);
    printf("pass by value:%d\n",num);
    pass_by_pointer(&num);
    printf("pass by point:%d\n",num);
    return 0;
}
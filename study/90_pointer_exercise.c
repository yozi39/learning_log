#include<stdio.h>
int main(){
    int num_1=5,num_2=10;
    int *ptr_1=NULL,*ptr_2=NULL;
    ptr_1=&num_1;
    ptr_2=&num_2;
    printf("num_1 is :%d\tnum_2 is :%d\n",num_1,num_2);
    int temp=*ptr_1;
    *ptr_1=*ptr_2;
    *ptr_2=temp;
    printf("num_1 isÊÇ :%d\tnum_2 is :%d\n",num_1,num_2);
    return 0;
}
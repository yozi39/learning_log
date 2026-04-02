#include<stdio.h>

// int main(){
//     char str_1[20]={"Hello"},str_2[20]={"World"};
//     char *ptr_1=str_1;
//     char **ptr_2=&ptr_1;
//     printf("before:%s\n",ptr_1);
//     *ptr_2=str_2;
//     printf("now:%s\n",str_2);
// }

int main(){
    int arr[5]={1,2,3,4,5};
    int *ptr_1=arr;
    int **ptr_2=&ptr_1;
    for(int i=0;i<5;++i){
        printf("%d ",*(*ptr_2+i));
    }
}
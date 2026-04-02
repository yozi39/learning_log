#include<stdio.h>
// int main(){
//     char c=getchar();
//     int i = 0;
//     while(c!='\n'){
//         i += 1;
//         c = getchar();
//     }
//     printf("totle = %d",i);
//     return 0;
// }


int main(){
    int target = 42;
    int guess;
    char a = 'f';
    do{
        scanf("猜测一个整数%d",&guess);
        if (guess > target){printf("太大了");}
        else if (guess < target){printf("太小了");}
        else if(guess = target){printf("正确");
            a = 't';
        }
        else {printf("输入一个合法的数字"); }
    }while(a !='t');
    return 0;
}
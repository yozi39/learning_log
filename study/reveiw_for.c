#include<stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    // int row;
    // printf("输入菱形的行数：");
    // scanf("%d",&row);
    // if(row<=0 && row%2!=0)printf("请输入一个正整数:");
    // else{
    //     while(row--){
    //         for(int i=0;i<=(row-1)/2;i++){
    //             printf(" ");
    //         }
    //         for(int j=0;j<=(row-1)/2-j;j++){
    //             printf("*");
    //         }
    //         printf("\n");
    //     }
    // }

    int row;
    printf("输入三角形的高度:");
    scanf("%d",&row);
    for(int i=1;i<=row;i++){
        for(int j=0;j<=row-i;j++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(){
#ifdef _WIN32
    /* 将控制台输入/输出编码设置为 UTF-8，避免中文乱码 */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int height;
    printf("输入三角形的高度: ");
    if (scanf("%d", &height)!=1 || height<=0) {
        printf("请输入一个大于0的整数。\n");
        return 1;
    }
    for (int row = 1; row <= height; row++){
        for (int s = 0; s < height - row; s++){
            printf(" ");
        }
        for (int w = 0; w < 2*row - 1; w++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
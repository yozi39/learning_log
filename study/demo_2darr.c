#include<stdio.h>
#ifdef _WIN32
#include<windows.h>
#endif
int main(){
#ifdef _WIN32
    /* 将控制台输入/输出编码设置为 UTF-8，避免中文乱码 */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("请输入第%d行,第%d列",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
    printf("\n");        
    }   
}
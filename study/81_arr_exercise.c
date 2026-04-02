#include<stdio.h>
// int main(){
//     int arr[5],i;
//     printf("please input 5 integers:\n");
//     for (i=0;i<5;i++){
//         scanf("%d",&arr[i]);
//     }
//     int max=arr[0];
//     int min=arr[0];
//     for (i=0;i<5;i++){
//         if(max<=arr[i]){
//             max=arr[i];
//         }
//         if(min>=arr[i]){
//             min=arr[i];
//         }
//     }
//     printf("max=%d\n",max);
//     printf("min=%d\n",min);
// }

int main(){
    int arr[5][5];
    arr[0][0]=1;
    int row;
    printf("please input the height of pascal triangl:");
    scanf("%d",&row);
    for(int i=0 ; i<row ;i++){
        arr[i][0]=1;
        arr[i][i]=1;
    }
    for(int i=2;i<row;i++){
        for (int j=1;j<i;j++){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<=i;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}


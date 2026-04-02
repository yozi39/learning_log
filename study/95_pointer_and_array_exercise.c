#include<stdio.h>
#include<string.h>
//题目一
// int main(){
//     char str_1[100],str_2[100],str_3[100];
//     int len=0;
//     scanf("%s %s %s",str_1,str_2,str_3);
//     char *ptr[3]={str_1,str_2,str_3};
//     for (int i=0;i<3;i++){
//         int j;
//         len = strlen(ptr[i]);
//         printf("long:%d\n",len);
//         for(j=0;j<len;j++){
//             printf("%c",*((ptr[i])+j));
//         }
//         printf("\n");
//     }
// }

//题目二
// int main(){
//     char arr[8]={'a','b','c','d','e','f','g','h'};
//     char *ptr = arr;
//     char *end;
//     end = ptr+7;
/*     
        while(ptr<end){
            char temp=*ptr;
            *ptr = *end;
            *end =temp;
            ptr++;
            end--;
        }
*/
//     for (int i=0;i<8;i++){
//         printf("%c ",*(end-i));
//     }
// }
#include<stdio.h>
int main(){
    for(int i=1;i<=50;++i){
        if(i>40 && i%2==0){
        break;
        }
        if(i%2==0){
            if(i%3==0){
                continue;
            }
            printf("%d\n",i);
        }
        
    }
}
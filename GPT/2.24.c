#include<stdio.h>
int main(){
    int num[10];
    int max,second_max;
    int max_time=1;
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
        if(i==0){
            max=num[i];
            second_max=num[i];
        }
        else {
            if(num[i]>max){
                max=num[i];
                max_time=1;
            }
            else if(max==num[i]){max_time+=1;}
            if(num[i]!=max && num[i]>second_max){second_max=num[i];}
        }
    }
    printf("max=%d,second_max=%d,max_time=%d",max,second_max,max_time);
}
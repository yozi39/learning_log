#include<stdio.h>
#include<limits.h>
int main(){
    int n,q=0;
    int min=INT_MAX;
    int second_min=INT_MAX;
    int max=INT_MIN;
    scanf("%d",&n);
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(min>num){
            second_min=min;
            min=num;

        }
        else if(second_min>num && num!=min){
            second_min=num;
        }
        if(max<num){
            max=num;
        }
    }
    if(second_min==INT_MAX){
        printf("second_min is not invalid,max=%d,min=%d",max,min);
    }
    else{printf("%d,%d,%d",max,min,second_min);}
    return 0;
}
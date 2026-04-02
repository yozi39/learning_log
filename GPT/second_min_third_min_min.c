#include<stdio.h>
#include<limits.h>
int main(){
    int second_min=INT_MAX,third_min=INT_MAX,min=INT_MAX;
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(min>num){
            third_min=second_min;
            second_min=min;
            min=num;
        }
        else if(second_min>num && num!=min){
            third_min=second_min;
            second_min=num;
        }
        else if(third_min>num && min!=num && second_min!=num){
            third_min=num;
        }
    }
    if(second_min==INT_MAX){printf("no second_min and third_min");}
    else if(third_min==INT_MAX){printf("no third_min");}
    else{printf("%d %d %d",min,second_min,third_min);}
    return 0;
}
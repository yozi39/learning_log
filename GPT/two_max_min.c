#include<stdio.h>
#include<limits.h>
int main(){
    int max=INT_MIN,min=INT_MAX,sec_max=INT_MIN,sec_min=INT_MAX;
    int n,num;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&num);
        if(min>num){
            sec_min=min;
            min=num;
        }
        else if(sec_min>num && num!=min){
            sec_min=num;
        }
        if(max<num){
            sec_max=max;
            max=num;
        }
        else if(sec_max<num && num!=max){
            sec_max=num;
        }
    }
    if(sec_max==INT_MIN || sec_min==INT_MAX){
        if(sec_max==INT_MIN){printf("%d no second max %d %d",max,min,sec_min);}
        else if(sec_min==INT_MAX){printf("%d %d %d no second min",max,sec_max,min);}
        else{printf("%d no second max %d no second min",max,min);}
    }
    else{printf("%d %d %d %d",max,sec_max,min,sec_min);}
}
#include<stdio.h>

#define SECONDS_PER_MINUTE 60
#define MINUTES_TO_SECONDS(m) (m*SECONDS_PER_MINUTE)

int main(){
    int minutes;
    scanf("%d",&minutes);
    int second;
    second = MINUTES_TO_SECONDS(minutes);
    printf("%d",second);
}
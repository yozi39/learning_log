#include<stdio.h>
int main(void){
    int online_status;
    int emo,sz_online;
    int goal=0,girl,beautiful;
    printf("请输入文本:");
    printf("zhy室友否上线，sz当然心情，sz是否在线，室友是否像或者是女性，室友是否漂亮可爱。");
    scanf("%d %d %d %d %d ",&online_status,&emo,&sz_online,&girl,&beautiful);
    if(online_status==1){
        if(emo==1 && sz_online){
            while(goal != 100){
                printf("帮助中...");
                goal++;
            }
        }
        if(emo==1 || sz_online){
            while(goal < 50 ){
                printf("帮助中...");
                goal++;
            }
            printf("力竭了");
            if(girl==1 && beautiful==1){
                while(goal !=100){
                    printf("你好香啊");
                }
            }
            else{printf("不行肝不动了");}
        }
        else {
            printf("可怜无助了室友一个人阴暗的爬行");
            for (int i=0;i<50;i++){
                printf("努力挣扎中");
            }
        }
    }
    printf("遗憾离场");
}
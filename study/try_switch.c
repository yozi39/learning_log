#include<stdio.h>

int main(){
    int day = 3;
    int room_type = 2;
    int price = 0;

    switch(room_type){
        case 2:
            switch(day){
                case 1:    
                case 2:
                case 3:
                    price = 100 * day;
                    break;
                default:
                    price = 80 * (day-3) + 300;
            }
            printf("单人房%d天，要%d钱",day,price);
            break;
        default:
            printf("我还没有写");
        }
    return 0;
}
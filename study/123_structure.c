#include<stdio.h>

typedef struct Book{
    char title[50];
    char author[20];
    double price;
    int quantity;
}Book;

double calculate_total_value(Book* books,int size){
    int result=0;
    for(int i=0;i<size;i++){
        result += ((books+i)->price)*((books+i)->quantity);
    }
    return result;
}

int main(){
    Book books[3]={{"C语言入门","咕咕嘎嘎",30.0,50},{"2","哈哈哈哈",45.0,30},{"3","原神",55.0,20}};
    double total_value=calculate_total_value(books,3);
    printf("total_value:%.2lf",total_value);
}
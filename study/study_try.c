/*
练习:给定一个日期2088年2月29日，判断该日期是否合法。如果合法，计算该日期的下一天日期并输出，
格式:下一天日期为..年..月...日。如果不合法，输出“错误:提供的日期不合法”*/


#include<stdio.h>

int main(){
    int year = 2088;
    int month = 2;
    int day = 29;
    if (year == 0 || month<1 || month>12 || day < 1 || day > 31){
        printf("日期不合法");
        return 1;
    }
    int leap_year;
    leap_year = ((year%4==0 && year%100 != 0) || year%400 == 0)? 1:0;
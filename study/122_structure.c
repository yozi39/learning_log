#include<stdio.h>
typedef struct student{
    char name[20];
    int age;
    double score;
}student;

void input_student_info(student* p){
    scanf(" %s %d %lf",p->name,&p->age,&p->score);
}

int main(){
    student stu;
    input_student_info(&stu);
    printf("%s %d %.2f",stu.name,stu.age,stu.score);
}
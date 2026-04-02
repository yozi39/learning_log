#include<stdio.h>
double BMI=0;
void calculate_bmi(double weight,double height){
    BMI=weight/(height*height);
}
int main(){
    double weight,height;
    printf("input your weight and height:\n");
    scanf("%lf %lf",&weight,&height);
    calculate_bmi(weight,height);
    printf("%.2lf\n",BMI);
    if(BMI <= 18.5)printf("shou");
    else if(BMI>18.5 && BMI<=25)printf("normal");
    else if(BMI>25 && BMI <=30)printf("fat");
    else if(BMI >30) printf("pig");
}
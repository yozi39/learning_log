#include<iostream>
using namespace std;
int factorial(int num){
    int sum=1;
    for(int i=1;i<=num;i++){
        sum = sum*i;
    }
    return sum;
}
int sum_factorial(int a,int b){
    int a1,b1,result;
    a1=factorial(a);
    b1=factorial(b);
    result=a1+b1;
    return result;
}
int main(){
    int num1,num2;
    int sum;
    cin>>num1>>num2;
    sum = sum_factorial(num1,num2);
    cout<<num1<<"!+"<<num2<<"!="<<sum<<endl;
}
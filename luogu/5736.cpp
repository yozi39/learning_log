#include<bits/stdc++.h>
using namespace std;

int n,num;

bool is(int num){
    if(num==1)return false;
    for(int i=2;i<=num/i;i++){//1除外
        if(num%i==0)return false;
    }
    return true;
}

int main(){
    cin>>n;
    while(n--){
        cin>>num;
        if(is(num))cout<<num<<' ';
    }
}
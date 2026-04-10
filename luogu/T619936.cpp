#include<bits/stdc++.h>
#define change 64
using namespace std;

int sum(string a){
    int sum=1;
    int end=a.length();
    for(int i=0;i<end;i++){
        sum *= (a[i]-change);
    }
    return (sum%47);
}

int main(){
    string hui;
    string team;
    cin>>hui>>team;
    if(sum(hui) == sum(team))cout<<"GO";
    else{
        cout<<"STAY";
    }
}
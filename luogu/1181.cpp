#include<bits/stdc++.h>
using namespace std;

int sum=0,cnt=1,tmp;

void yes(){
    cnt++;
    sum=tmp;  //超了之后不能丢弃而是变成第一个数字
}

void no(){
    sum+=0;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        tmp=a[i];
        sum+=tmp;
        (sum>m)?yes():no();
    }
    cout<<cnt;
}
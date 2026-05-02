#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=1e6+12;

int a[N],b,c[N];
string x;
int la,lc;

void div(int a[],int b,int c[]){
    LL t=0;
    for(int i=lc-1;i>=0;i--){
        t = t*10+a[i];    //余数是=不是+= 不然会多加一次
        c[i] = t/b;
        t %= b;
    }
    while(lc-1>0 && c[lc-1]==0)lc--;
}

int main(){
    cin>>x>>b;
    la=x.size();lc=la;
    for(int i=0;i<la;i++)a[la-1-i]=x[i]-'0';

    div(a,b,c);

    for(int i=lc-1;i>=0;i--)cout<<c[i];
}
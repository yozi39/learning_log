#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N]={0},b[N]={0},c[N]={0};//必须初始化,并且会爆栈所以要全局变量

int main(){
    string x,y;
    while(cin>>x>>y){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int la,lb,lc;
        la=x.size();
        lb=y.size();
        lc=max(la,lb);

        for(int i=0;i<la;i++)a[i]=x[la-1-i]-'0';//减去字符
        for(int i=0;i<lb;i++)b[i]=y[lb-1-i]-'0';

        for(int i=0;i<lc;i++){
            c[i]+=a[i]+b[i];
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        if(c[lc])lc++;

        for(int i=lc-1;i>=0;i--)cout<<c[i];
        cout<<'\n';
    }
}
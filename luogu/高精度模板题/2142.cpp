#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int a[N]={0},b[N]={0},c[N]={0};
int la,lb,lc;
string x,y;

int main(){
    cin>>x>>y;
    la=x.size();//比较之前先定义
    lb=y.size();
    lc=max(la,lb);
    if(la != lb){
        if(la<lb){
            swap(x,y);
            cout<<'-';
        }
    }
    else{
        if(x<y){
            swap(x,y);
            cout<<'-';
        }
    }
    la=x.size();
    lb=y.size();//更新两个长度
    for(int i=0;i<la;i++)a[la-1-i]=x[i]-'0';//'0'不要忘
    for(int i=0;i<lb;i++)b[lb-1-i]=y[i]-'0';

    for(int i=0;i<lc;i++){
        c[i]+=a[i]-b[i];
        if(c[i]<0){
            c[i+1]-=1;
            c[i]+=10;
        }
    }
    int pos=lc;
    while(pos-1>0 && c[pos-1] == 0){
        pos--;
    }
    for(int i=pos-1;i>=0;i--)cout<<c[i];//逆序输出,不小心把pos 和 lc 搞混了pos 就是最前面的
}
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int a[N],b[N],c[N];
string x,y;
int la,lb,lc;
int pos;

void mul(int a[],int b[],int c[]){
    for(int i=0;i<la;i++){
        for(int j=0;j<lb;j++){
            c[j+i]+=a[i]*b[j];
        }
    }
    for(int i=0;i<lc;i++){
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
    while(pos-1>0 && c[pos-1] == 0)pos--;
}

int main(){
    cin>>x>>y;
    la=x.size();lb=y.size();lc=la+lb;
    pos=lc;
    for(int i=0;i<la;i++)a[la-1-i]=x[i]-'0';
    for(int i=0;i<lb;i++)b[lb-1-i]=y[i]-'0';
    
    mul(a,b,c);

    for(int i=pos-1;i>=0;i--)cout<<c[i];
}
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=1e6+10;
int a[MAXN],b[MAXN],c[MAXN];
int la,lb,lc;
string x;

void div(int a[],int b){
    int t=0;
    for(int i=la-1;i>=0;i++){
        t=a[i]+t*10;
        c[i]=t/b;
        t%=b;
    }
    while(lc-1>0 && c[lc-1]==0)lc--;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        LL n,max=-1;
        bool yes=1;
        cin>>n;
        LL num[n+1];
        for(int i=1;i<=n;i++){
            cin>>num[i];
            if(num[i]>max)max=num[i];
        }
        
        for(int i=1;i<=n;i++){
            if(max%num[i] != 0)yes=0;        
        }
        if(yes)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
        
    }
}
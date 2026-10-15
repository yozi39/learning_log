#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x & -x)

const int N=4200;

int n,m;
LL s[N][N];

void modify(int x,int y,LL k){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            s[i][j]+=k;
        }
    }
}

LL query(int x,int y){
    LL sum=0;
    for(int i=x;i;i-=lowbit(i)){
        for(int j=y;j;j-=lowbit(j)){
            sum+=s[i][j];
        }
    }
    return sum;
}

int main(){
    cin>>n>>m;
    
    int op;
    while(cin>>op){
        if(op==1){
            int a,b,x,y;LL k;
            cin>>a>>b>>x>>y>>k;
            modify(a,b,k);
            modify(x+1,b,-k);
            modify(a,y+1,-k);
            modify(x+1,y+1,k);
        } else {
            int x,y;
            cin>>x>>y;
            cout<<query(x,y)<<'\n';
        }
    }
}
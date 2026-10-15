#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x & -x)

const int N=5e3;

int n,m;
LL a[N][N];

void modify(int x,int y,LL k){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            a[i][j]+=k;
        }
    }
}

LL query(int x,int y){
    LL sum=0;
    for(int i=x;i;i-=lowbit(i)){
        for(int j=y;j;j-=lowbit(j)){
            sum+=a[i][j];
        }
    }
    return sum;
}

int main(){
    cin>>n>>m;

    int op;
    while (cin>>op)
    {
        int x,y,c,d;
        cin>>x>>y>>c;
        if(op==1){
            modify(x,y,c);
        } else {
            cin>>d;
            cout<<query(x-1,y-1)-query(x-1,d)-query(c,y-1)+query(c,d)<<'\n';
        }
    }
    
}
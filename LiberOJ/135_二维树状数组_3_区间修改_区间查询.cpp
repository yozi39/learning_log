#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x & -x)

const int N=4200;

int n,m;
struct BIT{
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
}A,B,C,D;
//d[i][j],d[i][j]*i.d[i][j]*j,d[i][j]*i*j

void add(int x,int y,LL k){
    A.modify(x,y,k);
    B.modify(x,y,k*x);
    C.modify(x,y,k*y);
    D.modify(x,y,k*x*y);
}

LL sum(int x,int y){
    return A.query(x,y)*(x*y+x+y+1)-
    B.query(x,y)*(y+1)-
    C.query(x,y)*(x+1)+
    D.query(x,y);
}

int main(){
    cin>>n>>m;

    int op;
    while (cin>>op)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        if(op==1){
            LL k;
            cin>>k;
            add(x1,y1,k);
            add(x1,y2+1,-k);
            add(x2+1,y1,-k);
            add(x2+1,y2+1,k);
        } else {
            cout<<sum(x1-1,y1-1)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x2,y2)<<'\n';
        }
    }
    
}
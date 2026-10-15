#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)

const int N=305,M=105;

int n,m;
int a[N][N];
struct BIT
{
    int s[N][N];

    void modify(int x,int y,int k){
        for(int i=x;i<=n;i+=lowbit(i)){
            for(int j=y;j<=m;j+=lowbit(j)){
                s[i][j]+=k;
            }
        }
    }
    
    int query(int x,int y){
        int sum=0;
        for(int i=x;i;i-=lowbit(i)){
            for(int j=y;j;j-=lowbit(j)){
                sum+=s[i][j];
            }
        }
        return sum;
    }
}s[M];



int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            s[a[i][j]].modify(i,j,1);
        }
    }

    int q;
    cin>>q;

    while(q--){
        int op,x,y,aa,bb,c;
        cin>>op>>x>>y;
        if(op==1){
            cin>>c;
            s[a[x][y]].modify(x,y,-1);
            s[c].modify(x,y,1);
            a[x][y]=c;
        } else {
            cin>>aa>>bb>>c;
            cout<<s[c].query(y,bb)
                -s[c].query(x-1,bb)
                -s[c].query(y,aa-1)
                +s[c].query(x-1,aa-1)<<'\n';
        }
    }
}
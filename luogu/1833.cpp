#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int a,b,c,d,m,n;
char ch;
int f[N];
struct P1833
{
    int t,v,p;
}tree[N];

int main(){
    cin>>a>>ch>>b>>c>>ch>>d>>n;
    m=-(a*60+b)+(c*60+d);

    for(int i=1;i<=n;i++){
        cin>>tree[i].t>>tree[i].v>>tree[i].p;
    }

    for(int i=1;i<=n;i++){

        if(tree[i].p==0){
            for(int j=tree[i].t;j<=m;j++){
                f[j]=max(f[j],f[j-tree[i].t]+tree[i].v);
            }
        }

        else{
            for(int j=m;j>=0;j--){
                for(int k=0;k<=min( tree[i].p , j/tree[i].t );k++){
                    f[j]=max(f[j],f[j-k*tree[i].t]+k*tree[i].v);
                }
            }
        }

    }
    cout<<f[m];
}
/*
    斜线一个是x-i=C  一个是i+x=C
    所以能不能选就看当前的选项会不会等于到占用的C
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,ans=0;
int a[N],cnt=0;
int col[N],dg1[N],dg2[N];

void dfs(int x){
    if(x==n){
        ans++;
        if(cnt<3){
            cnt++;
            for(int i=0;i<n-1;i++){
                cout<<a[i]<<' ';
            }
            cout<<a[n-1];
            cout<<'\n';
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(col[i]!=1 && dg1[i+x]!=1 && dg2[x-i+n]!=1){
            a[x]=i;

            col[i]=1;
            dg1[x+i]=1;
            dg2[x-i+n]=1;

            dfs(x+1);

            col[i]=0;
            dg1[x+i]=0;
            dg2[x-i+n]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    cout<<ans;
}
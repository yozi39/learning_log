#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,a,b;
int k[N],st[N];

void bfs(int x){
    memset(st,-1,sizeof(st));
    st[x]=0;
    queue<int> q;
    q.push(x);
    int i=x;int dx[2]={1,-1};

    while(q.size() && i!=b){
        i=q.front();q.pop();
        for(int z=0;z<=1;z++){
            int x=i+k[i]*dx[z];
            if(x>=1 && x<=n && st[x]==-1){
                st[x]=st[i]+1;
                q.push(x);
            }
        }    
    }
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>k[i];

    bfs(a);

    cout<<st[b];
}
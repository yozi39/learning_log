#include<bits/stdc++.h>
using namespace std;

const int N=3e4+5;

int n,m;
int tr[N],fa[N];

struct node{
    int l,r,c;
}a[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void add(int x){
    for(;x<=n;x+=x&-x)tr[x]++;
}

int sum(int x){
    int ret=0;
    for(;x;x-=x&-x)ret+=tr[x];
    return ret;
}

int main(){
    cin>>n>>m;

    for(int i=0;i<=n;i++)fa[i]=i;

    for(int i=1;i<=m;i++)
        cin>>a[i].l>>a[i].r>>a[i].c;

    sort(a+1,a+1+m,[](node x,node y){
        return x.r<y.r;
    });

    int ans=0;

    for(int i=1;i<=m;i++){
        int l=a[i].l,r=a[i].r,c=a[i].c;
        int cnt=sum(r)-sum(l-1);
        int need=max(0,c-cnt);

        while(need--){
            int x=find(r);//找到最右边的可选位置
            add(x);
            fa[x]=find(x-1);//移除当前添加位置出可选
            ans++;
        }
    }

    cout<<ans<<'\n';
}
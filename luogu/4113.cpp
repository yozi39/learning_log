#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)

const int N=2e6+5;

int n,c,m;
int a[N];
int ret[N];
int last[N],pre[N],pos=1;
int s[N];

struct node{
    int l,r,id;

    bool operator<(const node& other) const{
        return r<other.r;
    }
}q[N];

void modify(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        s[i]+=k;
    }
}

int query(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=s[i];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>c>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }

    sort(q+1,q+1+m);

    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r,id=q[i].id;

        while(pos<=r){
            int x=a[pos];

            if(pre[x]){
                modify(pre[x],-1);
            }

            if(last[x]){
                modify(last[x],1);
            }

            pre[x]=last[x];
            last[x]=pos;

            pos++;
        }

        ret[id]=query(r)-query(l-1);
    }

    for(int i=1;i<=m;i++){
        cout<<ret[i]<<'\n';
    }

    return 0;
}
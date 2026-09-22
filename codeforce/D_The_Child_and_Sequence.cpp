#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lc p<<1
#define rc p<<1 | 1

const int N=1e5+5;

int n,m;
int a[N];
struct node{
    int l,r;
    LL sum,max;
}tr[N<<2];

void pushup(int p){
    tr[p].sum=tr[lc].sum+tr[rc].sum;
    tr[p].max=max(tr[lc].max,tr[rc].max);
}

void build(int p,int l,int r){
    tr[p]={l,r,a[l],a[l]};
    if(l==r)return;

    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,LL aim,LL value){
    LL l=tr[p].l,r=tr[p].r;
    if(l==aim && r==aim){
        tr[p].sum=tr[p].max=value;
        return;
    }

    int mid=(l+r)>>1;
    if(aim<=mid)modify(lc,aim,value);
    if(aim>mid)modify(rc,aim,value);
    pushup(p);
}

void modifyMOD(int p,LL x,LL y,LL MOD){
    if(tr[p].max<MOD)return;

    LL l=tr[p].l,r=tr[p].r;
    if(l==r){
        tr[p].sum%=MOD;
        tr[p].max=tr[p].sum;
        return;
    }

    LL mid=(l+r)>>1;
    if(x<=mid)modifyMOD(lc,x,y,MOD);
    if(y>mid)modifyMOD(rc,x,y,MOD);
    pushup(p);
}

LL query(int p,LL x,LL y){
    LL l=tr[p].l,r=tr[p].r;
    if(x<=l && y>=r){
        return tr[p].sum;
    }

    LL ret=0;
    LL mid=(l+r)>>1;
    if(x<=mid)ret+=query(lc,x,y);
    if(y>mid)ret+=query(rc,x,y);

    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    build(1,1,n);

    while(m--){
        LL op,l,r,x;
        cin>>op;
        switch (op)
        {
        case 1:
            cin>>l>>r;
            cout<<query(1,l,r)<<'\n';
            break;
        case 2:
            cin>>l>>r>>x;
            modifyMOD(1,l,r,x);
            break;
        case 3:
            cin>>l>>x;
            modify(1,l,x);
            break;
        default:
            break;
        }
    }
}
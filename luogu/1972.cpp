#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)

const int N=1e6+5;

int n;
int a[N];
int s[N],last[N];
int ret[N];
unordered_map<int,int> mp;
struct node{
    int l,r,id;
}q[N];

bool cmp(node& x,node& y){
    return x.r<y.r;
}

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

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }

    sort(q+1,q+1+m,cmp);

    int pos=1;
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r,id=q[i].id;
        while (pos<=r)
        {
            if(last[a[pos]]) modify(last[a[pos]],-1);
            modify(pos,1);
            last[a[pos]]=pos;
            pos++;
        }
        ret[id]=query(r)-query(l-1);
    }

    for(int i = 1;i<=m;i++){
        cout<<ret[i]<<'\n';
    }

    return 0;
}
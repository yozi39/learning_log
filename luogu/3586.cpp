#include<bits/stdc++.h>
typedef long long LL;
#define lowbit(x) (x & -x)

using namespace std;

const int N=1e6+5;

int n,m;
unordered_map<LL,int> mp;
int rkid;
struct node{
    char op;
    int x,y;
}q[N];
int t[N],a[N];
struct BIT
{
    LL s[N];

    void modify(int x,LL k){
        for(int i=x;i<=m;i+=lowbit(i)){
            s[i]+=k;
        }
    }

    LL query(int x){
        LL sum=0;
        for(int i=x;i;i-=lowbit(i))sum+=s[i];
        return sum;
    }
}A,B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].op>>q[i].x>>q[i].y;
        t[i]=q[i].y;
    }
    
    sort(t+1,t+1+m);
    for(int i=1;i<=m;i++){
        if(!mp.count(t[i]))mp[t[i]]=++rkid;
    }
    
    for(int i=1;i<=m;i++){
        char op=q[i].op;
        if(op=='U'){
            int x=q[i].x,k=q[i].y;
            if(a[x]){
                A.modify(mp[a[x]],-a[x]);
                B.modify(mp[a[x]],-1);
            }
            A.modify(mp[k],k);
            B.modify(mp[k],1);

            a[x]=k;
        } else{
            int c=q[i].x;
            int val=q[i].y;
            int s=mp[val];

            LL sum=A.query(s-1);
            LL cnt=B.query(m)-B.query(s-1);

            if(sum>=1LL*(c-cnt)*val) cout<<"TAK\n";
            else cout<<"NIE\n";
        }
    }
}
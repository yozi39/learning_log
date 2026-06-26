#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;

int p[N],phi[N],cnt;bool st[N];
void get_phi(){
    phi[1]=1;
    for(int i=2;i<=N-5;i++){
        if(!st[i]){
            phi[i]=i-1;
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt && 1ll*i*p[j]<=N-5;j++){
            long long x=i*p[j];
            st[x]=true;
            if(i%p[j]==0){
                phi[x]=phi[i]*p[j];
                break;
            }
            else{
                phi[x]=phi[i]*(p[j]-1);
            }
        }
    }
}

long long qpow(int a,int b,int c){
    long long ret=1;
    while(b){
        if(b&1)ret = ret * a % c;
        b >>= 1;
        a = 1ll*a*a%c;
    }
    return ret;
}

int dfs(int p){
    if(p==1) return 0;

    return qpow(2,dfs(phi[p])+phi[p],p);
}

int main(){
    get_phi();
    int T;cin>>T;
    while(T--){
        int p;cin>>p;
        cout<<dfs(p)<<'\n';
    }
}
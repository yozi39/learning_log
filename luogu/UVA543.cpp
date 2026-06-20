#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

bool st[N];
int p[N],cnt;

void get_prime(){
    int n=1e6;
    for(int i=2;i<=n;i++){
        if(!st[i])p[++cnt]=i;

        for(int j=1;1ll*i*p[j]<=n;j++){
            st[i*p[j]]=true;
            if(i%p[j]==0)break;
        }
    }
}

void solve(int x){
    for(int i=2;i<=cnt;i++){
        if(!st[x-p[i]]){
            printf("%d = %d + %d\n",x,p[i],x-p[i]);
            break;
        }
    }
}

int main(){
    get_prime();

    int x;
    while(cin>>x,x){
        solve(x);
    }
}
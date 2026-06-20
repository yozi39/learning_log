#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e8+5;
int n,q;
int cnt,f[N];bool st[N];

void get_prime(){//埃氏筛
    for(LL i=2;i<=n;i++){
        if(!st[i]){//质数
            f[++cnt]=i;
            for(long long j=i*i;j<=n;j+=i){
                st[j]=true;
            }
        }
    }
}

void other_prime(){//线性筛
    for(LL i=2;i<=n;i++){
        if(!st[i])f[++cnt]=i;
        for(LL j=1;f[j]>0 && i*f[j]<=n;j++){
            st[i*f[j]]=true;
            if(i%f[j]==0)break;
        }
    }
}

int main(){
    cin>>n>>q;

    other_prime();

    while(q--){
        int in;scanf("%d",&in);
        printf("%d\n",f[in]);
    }
}
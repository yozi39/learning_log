#include<bits/stdc++.h>
using namespace std;

int n,k,sum=0;
int ans=0;

void dfs(int x,int start){
    if(x==k){
        if(sum==n){
            ans++;
        }
        return;
    }
    
    for(int i=start;i<=n;i++){       
        if(sum+i*(k-x)>n)return; 
        sum+=i;
        dfs(x+1,i);
        sum-=i;
    }
}

int main(){
    cin>>n>>k;

    // if(n==200 && k==6){
    //     cout<<4132096;
    //     return 0;
    // }                  0.4ms遗址

    dfs(0,1);

    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;

#define qp '\n'
const int N = 20;

int n,a[N];

bool dfs(int x,int sum){
    if(x>n)return sum%360==0;
    return dfs(x+1,sum+a[x]) || dfs(x+1,sum-a[x]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    cout<<(dfs(1,0) ? "YES":"NO")<<qp;
}
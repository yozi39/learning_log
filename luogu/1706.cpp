#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
vector<int> path;
int n,st[N];

void dfs(int x){
    if(path.size()==n){
        for(auto v:path){
            printf("%5d",v);
        }
        cout<<'\n';
    }

    for(int i=1;i<=n;i++){
        if(st[i]!=1){
            path.push_back(i);
            st[i]=1;
            dfs(x+1);
            path.pop_back();
            st[i]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
}
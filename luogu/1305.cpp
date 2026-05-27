#include<bits/stdc++.h>
using namespace std;

const int N=300;
int n;
char l[N],r[N];

void dfs(char u){
    if(u=='*')return;
    
    cout<<u;
    dfs(l[u]);
    dfs(r[u]);
    return;
}

int main(){
    char root;
    cin>>n;
    cin>>root>>l[root]>>r[root];
    for(int i=2;i<=n;i++){
        char t;cin>>t;
        cin>>l[t];
        cin>>r[t];
    }

    dfs(root);
}
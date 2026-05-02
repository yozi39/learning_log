/*
    树的遍历bfs
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
vector<int> q[N];
int n;
bool st[N];

void bfs(){
    queue<int> a;
    a.push(1);
    st[1]=true;

    while(a.size()){
        int u=a.front();a.pop();
        cout<<u<<' ';
        
        for(auto v:q[u]){
            if(!st[v]){
                a.push(v);
                st[v]=true;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    bfs();
}
#include<bits/stdc++.h>
using namespace std;

const int N = 1500;
typedef pair<int,int> PII;

int n;
vector<PII> edge[N];
vector<int> ret;
bool st[N];

void dfs(int x){
    while(edge[x].size()){
        int y = edge[x].back().first,id = edge[x].back().second;
        edge[x].pop_back();
        if(st[id])continue;
        st[id] = true;
        dfs(y);
    }
    ret.push_back(x);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back({b,i});
        edge[b].push_back({a,i});
    }

    for(int i=1;i<=500;i++){
        sort(edge[i].begin(),edge[i].end(),greater<PII>());
    }
    int s = 0;
    for(int i=1;i<=500;i++){
        if(edge[i].size()){
            s = i;
            break;
        }
    }
    for(int i=1;i<=500;i++){
        if(edge[i].size()%2){
            s = i;
            break;
        }
    }

    dfs(s);
    for(int i=n;i>=0;i--){
        cout<<ret[i]<<'\n';
    }
}
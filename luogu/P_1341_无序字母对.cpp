#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 256;

LL n;
vector<char> ret;
vector<char> edge[N];
int deg[N];
bool used[N][N];

void dfs(char x){
    while(edge[x].size()){
        char y = edge[x].back();
        edge[x].pop_back();

        if(used[x][y])continue;
        used[x][y] = used[y][x] = true;
        dfs(y);
    }
    ret.push_back(x);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++,deg[b]++;
    }

    char s = 0;
    for(int i=0;i<N;i++){
        sort(edge[i].begin(),edge[i].end(),greater<char>());
        if(deg[i] && !s)s = i;
    }

    int cnt = 0;
    for(int i=0;i<N;i++){
        if(deg[i]%2){
            cnt++;
            if(cnt==1)s = i;
        }
    }
    if(cnt!=0 && cnt!=2){
        cout<<"No Solution";
        return 0;
    }

    dfs(s);

    if(ret.size()!=n+1){
        cout<<"No Solution";
    } else {
        for(int i=n;i>=0;i--)cout<<ret[i];
    }
}
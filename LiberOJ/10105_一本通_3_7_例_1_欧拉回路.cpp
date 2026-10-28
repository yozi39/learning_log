#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int t,in[N],out[N];
int n,m;
vector<PII> edge[N];
vector<int> ret;
bool st[N];

void dfs(int x){
    while(edge[x].size()){
        int y = edge[x].back().first,id = edge[x].back().second;
        edge[x].pop_back();
        if(st[abs(id)])continue;
        st[abs(id)] = true;
        dfs(y);

        ret.push_back(id);
    }
}

int main(){
    cin>>t;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back({b,i});
        out[a]++;in[b]++;
        if(t == 1){
            edge[b].push_back({a,-i});
            in[a]++,out[b]++;
        }
    }
    int s = 0;
    for(int i=1;i<=n;i++){
        if(t == 2 && out[i]-in[i]){
            cout<<"NO";
            return 0;
        }

        if(t == 1 && (out[i]&1)){
            cout<<"NO";
            return 0;
        }

        if(!s && out[i])s = i;
    }

    dfs(s);

    if(ret.size() == m){
        cout<<"YES\n";
        for(int i=m-1;i>=0;i--)cout<<ret[i]<<' ';
    } else {
        cout<<"NO";
    }
}
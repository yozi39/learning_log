#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

map<string,int> mp;
vector<int> ret;
int id,degree[N],cnt;
vector<PII> edge[N];
bool st[250005];

void dfs(int x){
    while(edge[x].size()){
        int y = edge[x].back().first;
        int i = edge[x].back().second;
        edge[x].pop_back();

        if(st[i])continue;
        st[i] = true;
        dfs(y);
        ret.push_back(x);
    }
}

int main(){
    string a,b;
    while(cin>>a>>b){
        cnt++;
        if(!mp.count(a))mp[a] = ++id;
        if(!mp.count(b))mp[b] = ++id;
        int ida=mp[a],idb=mp[b];
        edge[ida].push_back({idb,cnt});
        edge[idb].push_back({ida,cnt});
        degree[ida]++;degree[idb]++;
    }
    int s = 0,c=0;
    for(int i=1;i<=id;i++){
        if(degree[i]&1){
            s = i;
            c++;
        }
    }
    if(c!=0 && c!=2){
        cout<<"Impossible";
        return 0;
    }
    if(!s)s=1;
    dfs(s);
    if(cnt == ret.size())cout<<"Possible";
    else cout<<"Impossible";
}
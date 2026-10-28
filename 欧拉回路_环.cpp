#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e5 + 5,M = 1e6+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
vector<PII> edge[N];
int degree[N];
bool exist[N];//标记当前哪个点在栈中
vector<int> tmp;//模拟栈
bool st[N];//当前这个点被遍历过
bool del[M];//标记当前这个边是否删除
vector<int> ret[M];
int cnt;//记录一共有多少条回路

void dfs(int x){
    st[x] = true;
    while (edge[x].size())
    {
        int y = edge[x].back().first,id = edge[x].back().second;
        edge[x].pop_back();
        if(del[id])continue;

        del[id] = true;
        dfs(y);
    }
    
    if(exist[x]){//当前这个点已经在栈种
        //把回路加到结果中
        cnt++;
        ret[cnt].push_back(x);
        while (tmp.back() != x)
        {
            ret[cnt].push_back(tmp.back());
            exist[tmp.back()] = false;
            tmp.pop_back();
        }
        ret[cnt].push_back(x);
    } else {
        tmp.push_back(x);
        exist[x] = true;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,s,t;cin>>a>>b>>s>>t;
        if(s == t)continue;
        edge[a].push_back({b,i});
        edge[b].push_back({a,i});
        degree[a]++;degree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]&1){
            cout<<"NIE";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(!st[i])dfs(i);
    }

    cout<<cnt<<qp;
    for(int i=1;i<=cnt;i++){
        cout<<ret[i].size()-1<<' ';
        for(auto x: ret[i]){
            cout<<x<<' ';
        }
        cout<<qp;
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e5 + 5,M = 2e5+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int in[N],out[N];
vector<int> edge[N],ret;

void dfs(int x){
    while(edge[x].size()){//不能一边范围for一边删除迭代器
        int y = edge[x].back();
        edge[x].pop_back();
        dfs(y);
    }
    ret.push_back(x);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        in[b]++;out[a]++;
    }

    int s = 0;
    for(int i=1;i<=n;i++){
        if(out[i] - in[i] > 1){
            cout<<"No";
            return 0;
        }
        if(out[i] - in[i] == 1){
            if(!s)s = i;
            else {
                cout<<"No";
                return 0;
            }
        }
        sort(edge[i].begin(),edge[i].end(),greater<int>());
    }
    if(!s)s = 1;//忘记了没有起始点的时候随便选一个做起始点

    dfs(s);

    for(int i=m;i>=0;i--){
        cout<<ret[i]<<' ';
    }
}
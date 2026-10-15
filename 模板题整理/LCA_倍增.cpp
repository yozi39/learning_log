// P3379

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,s;
LL f[N][25],dep[N];
vector<int> edge[N];

void dfs(int x,int depth,int fa){
    //先去初始化
    dep[x] = depth;
    f[x][0] = fa;

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfs(y,depth+1,x);
    }
}

void init(int x){
    dfs(x,1,0);

    //初始化完成之后开始填表
    for(int i=1;i<=20;i++){
        for(int j = 1;j<=n;j++){
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    //先去保证两个到达同层之后再开始共同运动
    for(int i=20;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            x = f[x][i];
        }
    }

    //如果跳到相同深度的时候两个一样那么此时就是lca
    if(x == y)return x;

    //让两者都到达差一步到lca的位置来保证答案的正确性
    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }

    //返回lca还需要继续向上走一步
    return f[x][0];
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    init(s);

    while(m--){
        int a,b;
        cin>>a>>b;

        cout<<lca(a,b)<<qp;
    }
}
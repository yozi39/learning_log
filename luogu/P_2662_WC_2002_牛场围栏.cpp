#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3000 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int mod = INF;
set<int> l;
vector<int> a;
LL dist[N];
bool st[9000000];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tl;cin>>tl;
        for(int j=0;j<=m && j<tl;j++){
            if(!l.count(tl-j)){
                l.insert(tl-j);
                a.push_back(tl-j);
                mod = min(mod,tl-j);
            }
        }
    }

    memset(dist,INF,sizeof dist);
    dist[0] = 0;

    for(auto i:a){
        if(mod == i)continue;
        int d = __gcd(i,mod);
        for(int j=0;j<d;j++){
            for(int x = j,c=0;c<2;c+=(x==j)){
                int y = (i+x)%mod;
                dist[y] = min(dist[y],dist[x]+i);
                x = y;
            }
        }
    }
    
    for(int i=0;i<mod;i++){
        if(dist[i]==LINF){
            cout<<-1<<qp; // 这个余数下的长度永远不可达，没有最大值
            return 0;
        }
        while(dist[i]<=9000000){
            st[dist[i]] = true;
            dist[i] += mod;
        }
    }

    LL ret = -1;
    for(int i=1;i<=9000000;i++){
        if(!st[i])ret = i;
    }
    cout<<ret;
}
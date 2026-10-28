#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e3 + 5,M=1e4+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
double dist[N];
vector<pair<int,double>> edge[N];
int cnt[N];
bool st[N];

bool check(double mid){//wi - x <= 0  ->  判断负环
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    for(int i=1;i<=n;i++)dist[i]=1e12;
    queue<int> q;
    q.push(0);
    st[0] = true;

    while (q.size())
    {
        int x = q.front();q.pop();
        st[x] = false;

        for(auto t:edge[x]){
            int y = t.first;double z = t.second - mid;
            if(dist[y] > dist[x] + z){
                dist[y] = dist[x] + z;
                cnt[y] = cnt[x] + 1;

                if(cnt[y] >= n+1){
                    return true;
                }

                if(!st[y]){
                    q.push(y);
                    st[y] = true; 
                }
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;double c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++){edge[0].push_back({i,0});}

    double l=-1e7,r=1e7;
    while(r-l>1e-10){
        double mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.8lf",r);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 40 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,mid;
map<PLL,array<LL,N>> mp;//坐标,time,cnt;
PLL aim;
PLL cmd[N];
LL ret[N];

void check(PLL cur,int time){
    PLL need = {aim.first-cur.first,aim.second-cur.second};
    if(mp.count(need)){
        for(int i=0;i<=mid;i++){
            ret[time+i]+=mp[need][i];
        }
    }
}

void ldfs(int pos,PLL cur,int time){
    if(pos>mid){
        mp[cur][time]++;
        return;
    }

    ldfs(pos+1,cur,time);
    ldfs(pos+1,
        {cur.first+cmd[pos].first,cur.second+cmd[pos].second},
        time + 1);
}

void rdfs(int pos,PLL cur,int time){
    if(pos>n){
        check(cur,time);
        return;
    }

    rdfs(pos+1,cur,time);
    rdfs(pos+1,
        {cur.first+cmd[pos].first,cur.second+cmd[pos].second},
        time + 1);
}

int main(){
    cin>>n;
    cin>>aim.first>>aim.second;
    for(int i=1;i<=n;i++){
        cin>>cmd[i].first>>cmd[i].second;
    }

    mid = (1+n)/2;
    ldfs(1,{0,0},0);
    rdfs(mid+1,{0,0},0);

    for(int i=1;i<=n;i++){
        cout<<ret[i]<<qp;
    }
}
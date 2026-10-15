#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e3 + 5,MOD = 1e9+7;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,nn[N];
LL f[N][11][11][2][2];

LL dfs(int pos,bool limit,int pre1,int pre2,bool ok,bool zero){
    if(!pos)return ok? 1:0;
    if(~f[pos][pre1][pre2][ok][zero] && !limit)return f[pos][pre1][pre2][ok][zero];

    int up = limit? nn[pos]:9;
    LL ret = 0;
    for(int i=0;i<=up;i++){
        bool nz=zero || i!=0;
        bool nok=ok;
        int p1=pre1,p2=pre2;

        if(nz){
            if(zero && (i==pre1 || i==pre2)) nok=true;
            p2=pre1;
            p1=i;
        }

        ret+=dfs(pos-1,
            limit&&(i==nn[pos]),
            p1,p2,
            nok,
            nz
        )%MOD;
    }
    if(!limit) f[pos][pre1][pre2][ok][zero] = ret%MOD;
    return ret%MOD;
}

LL calc(string x){
    n=0;
    memset(f,-1,sizeof f);

    int pos = x.size();
    for(auto v:x){
        nn[pos] = v-'0';
        pos--;
    }

    return dfs(x.size(),1,10,10,0,0)%MOD;
}

string sub1(string s){
    int i=s.size()-1;
    while(i>=0 && s[i]=='0'){
        s[i]='9';
        i--;
    }
    s[i]--;

    if(s.size()>1 && s[0]=='0')
        s.erase(s.begin());

    return s;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    cout<<(calc(s2)-calc(sub1(s1))%MOD+MOD)%MOD<<qp;
}
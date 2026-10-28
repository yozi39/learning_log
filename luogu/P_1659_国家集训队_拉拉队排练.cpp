#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e6 + 5,MOD = 19930726;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,d[N],m;
LL k,cnt[N];
string s,t;

LL qpow(LL a,LL b){
    LL ret = 1;
    while(b){
        if(b&1)ret = ret*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return ret;
}

int main(){
    cin>>n>>k>>t;
    s = ' ';
    for(auto v:t){
        s+='#';
        s+=v;
    }
    s+="##";
    m = s.size()-2;

    for(int i=2,l=1,r=1;i<=m;i+=2){
        int len = r>=i? min(d[r-i+l],r-i+1):1;
        while(s[i+len] == s[i-len])len++;
        if(i+len-1>r)r = i+len-1,l = i-len+1;
        d[i] = len;
        cnt[d[i]-1]++;
    }
    
    LL ans = 1,cur = 0;
    for(int len=(n&1?n:n-1);len>=1 && k;len-=2){
        cur += cnt[len];
        LL take = min(k,cur);
        ans = ans*qpow(len,take)%MOD;
        k -= take;
    }
    cout<<(k? -1:ans);
}
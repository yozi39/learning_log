#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL n;
string s,t;
int d[N];

bool check(int l,int r){
    if(s[l] == '0' && s[r] == '1')return true;
    if(s[l] == '1' && s[r] == '0')return true;
    if(s[l] == '#' && s[l] == s[r])return true;
    return false;
}

int main(){
    cin>>n>>t;
    n = n*(n+1)/2;
    s = ' ';
    for(auto v:t){
        s+="#";
        s+=v;
    }
    s+="##";
    int m = s.size()-2;

    d[1] = 1;
    LL ret = 0;
    for(int i=3,l=1,r=1;i<=m;i+=2){
        int len = r>=i? min(d[r-i+l],r-i+1):1;
        while(check(i+len,i-len))len++;
        if(i+len-1 > r)r = i+len-1,l = i-len+1;
        d[i] = len;
        ret += 1ll*d[i]/2;
    }

    cout<<ret;
}
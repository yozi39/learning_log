#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2.2e7 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string t,s;
int d[N];

int main(){
    cin>>t;
    s = ' ';
    for(auto v:t){
        s+="#";
        s+=v;
    }
    s+="##";
    int n = s.size()-2;

    d[1] = 1;
    for(int i=2,l=1,r=1;i<=n;i++){
        int len = r>=i? min(d[r-i+l],r-i+1):1;
        while(s[i+len] == s[i-len])len++;
        if(i+len-1 > r)r = i+len-1,l = i-len+1;
        d[i] = len;
    }
    int ret = 1;
    for(int i=1;i<=n;i++){
        ret = max(ret,d[i]-1);
    }
    cout<<ret;
}
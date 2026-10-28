#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s,t;
int d[N],l[N],r[N];

int main(){
    cin>>t;
    s = " ";
    for(auto v:t){
        s += "#";
        s += v;
    }
    s+="##";
    int n = s.size()-2;

    for(int i=2,l=1,r=1;i<=n;i++){
        int len = r>=i? min(d[r-i+l],r-i+1):1;
        while(s[i-len] == s[i+len])len++;
        if(i+len-1>r)r = i+len-1,l = i-len+1;
        d[i] = len;
    }

    //预处理l,r数组
    for(int i=1,j=1;i<=n;i++){
        while(j<i+d[i]){
            l[j] = j-i;
            j += 2;
        }
    }

    for(int i=n,j=n;i>=1;i--){
        while(j>i-d[i]){
            r[j] = i-j;
            j -= 2;
        }
    }
    
    int ret = 0;
    for(int i=3;i<=n-2;i+=2)ret = max(ret,l[i]+r[i]);
    cout<<ret;
}
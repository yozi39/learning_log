#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s;
int pi[N];

void kmp(){
    for(int i=2,j=0;i<s.size();i++){
        while(j && s[j+1] != s[i])j = pi[j];
        if(s[j+1] == s[i]) j++;
        pi[i] = j;
    }
}

int main(){
    while (cin>>s,s!="."){
        s = ' '+s;
        kmp();
        int n = s.size()-1;
        int len = n-pi[n];
        cout<<(n%len==0 ? n/len : 1)<<qp;
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int len,pi[N];
string s;

void kmp(){
    for(int i=2,j=0;i<=len;i++){
        while(j && s[j+1] != s[i])j = pi[j];
        if(s[i] == s[j+1])j++;
        pi[i] = j;
    }
}

int main(){
    cin>>len>>s;
    s = ' ' + s;
    kmp();
    int n = pi[len];
    cout<<len-n;
}
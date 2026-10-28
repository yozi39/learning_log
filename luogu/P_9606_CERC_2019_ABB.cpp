#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 8e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,pi[N];
string s;

int main(){
    cin>>n>>s;
    string rs = s;
    reverse(rs.begin(),rs.end());
    s = ' '+rs+'\0'+s;
    for(int i=2,j=0;i<s.size();i++){
        while(j && s[i]!=s[j+1])j = pi[j];
        if(s[i] == s[j+1])j++;
        pi[i] = j;
    }
    
    cout<<n-pi[s.size()-1];
}
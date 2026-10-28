#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s1,s2,s3;
int pi[N];

void get_pi(string s){
    for(int i=2,j=0;i<s.size();i++){
        while(j && s[j+1]!=s[i])j = pi[j];
        if(s[j+1] == s[i])j++;
        pi[i] = j;
    }
}

int main(){
    cin>>s1>>s2;
    s3 = ' ' + s2 + '*' + s1;
    get_pi(s3);

    for(int i=1;i<s3.size();i++){
        if(pi[i] == s2.size())cout<<i-2*s2.size()<<qp;
    }

    for(int i=1;i<=s2.size();i++)cout<<pi[i]<<' ';
    // string s4 = ' ' + s2;
    // get_pi(s4);
    // for(int i=1;i<s4.size();i++){
    //     cout<<pi[i]<<' ';
    // }
}
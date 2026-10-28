#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 4e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s;
int pi[N];

void kmp(){
    for(int i=2,j=0;i<s.size();i++){
        while(j && s[j+1]!=s[i])j = pi[j];
        if(s[i] == s[j+1])j++;
        pi[i] = j;
    }
}

int main(){
    while(cin>>s){
        s = ' '+s;
        kmp();
        vector<int> ret;
        int j = pi[s.size()-1];
        while(j){
            ret.push_back(j);
            j = pi[j];
        }
        sort(ret.begin(),ret.end());
        for(auto v:ret){
            cout<<v<<' ';
        }
        cout<<s.size()-1<<qp;
    }
}
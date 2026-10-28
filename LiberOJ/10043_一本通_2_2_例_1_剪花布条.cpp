#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e3 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s1,s2;
int pi[N];
void kmp(string s){
    for(int i=2,j=0;i<s.size();i++){
        while(j && s[j+1]!=s[i])j = pi[j];
        if(s[j+1] == s[i])j++;
        pi[i] = j;
    }
}

int main(){
    while(cin>>s1&&s1!="#"){
        cin>>s2;

        string s = ' ' + s2 + '\0' + s1;
        kmp(s);
        LL cnt = 0;
        bool flag;
        for(int i=s2.size()+2;i<s.size();flag? i+=s2.size():i++){
            flag = false;
            if(pi[i]==s2.size()){
                cnt++;
                flag = true;
            }
        }
        cout<<cnt<<qp;
    }
}
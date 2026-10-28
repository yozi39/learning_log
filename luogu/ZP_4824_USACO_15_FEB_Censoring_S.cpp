//涉及到删除后拼接,题眼就可以想到  栈!!
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

string s,t;
int pi[N];
int n,m,st[N],top;

int main(){
    cin>>s>>t;
    n = s.size(),m=t.size();
    s = ' '+t+'\0'+s;

    st[++top] = 1;
    for(int i = 2;i<=n+m+1;i++){
        int j = pi[st[top]];
        while(j && s[i]!=s[j+1])j=pi[j];
        if(s[i] == s[j+1])j++;
        pi[i] = j;
        st[++top] = i;

        if(j == m){
            for(int k=0;k<m;k++)top--;
        }
    }

    for(int i=m+2;i<=top;i++){
        cout<<s[st[i]];
    }
}
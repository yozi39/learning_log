#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int main(){
    int T;cin>>T;
    while(T--){
        int len;
        char c;
        string s;
        int ret=0;
        
        cin>>len>>c>>s;
        s = " "+s;

        for(int i=1;i<=len/2;i++){
            int j = len - i + 1;
            if(s[i]==s[j])continue;
 
            if(s[i]==c || s[j]==c){
                ret++;
            } else {
                ret+=2;
            }
        }

        cout<<ret<<qp;
    }
}
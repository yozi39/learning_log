#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int a[20];

int read(){
    string s;cin>>s;
    if(s.size()==1){
        if(s[0]>='3' && s[0]<='9'){
            return s[0]-'0';        
        } else if (s[0] == 'A'){
            return 14;
        } else if (s[0] == 'J'){
            return 11;
        } else if (s[0] == 'Q'){
            return 12;
        } else if (s[0] == 'K'){
            return 13;
        } else if (s[0] == '2'){
            return 15;
        }
    } else {
        if(s[0] == 'S'){
            return 16;
        } else if(s[0] == '1'){
            return 10;
        } else if(s[0] == 'B'){
            return 17;
        }
    }
}

int main(){
    int T;cin>>T;
    while(T--){
        for(int i = 1;i<=17;i++){
            a[i] = read();
        }

        sort(a+1,a+1+17);

        LL ret=0,cnt=1;
        for(int i=2;i<=17;i++){
            if(a[i]>14)break;
            if(a[i] == a[i-1])continue;
            if(a[i]==a[i-1]+1){
                cnt++;
            } else {
                cnt = 1;
            }
            ret = max(ret,cnt);
        }

        if(ret<5) ret=0;
        cout<<ret<<qp;
    }
}
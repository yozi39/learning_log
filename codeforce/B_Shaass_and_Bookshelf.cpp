#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int t[N], w[N],f[10010];
int sumT;

int main() {
    cin >> n;

    memset(f,0x3f,sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> w[i];
        sumT += t[i];
    }

    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=sumT;j>=t[i];j--){
            f[j]=min(f[j],f[j-t[i]]+w[i]);
        }
    }

    for(int j=sumT;j>=0;j--){
        if(f[j]<=(sumT-j)){
            cout<<sumT-j;
            return 0;
        };
    }
}
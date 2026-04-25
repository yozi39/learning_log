#include<bits/stdc++.h>
using namespace std;

const long long MOD = 999999999LL;
const int MAXN = 100000 + 5;
int ans[MAXN];
int good[MAXN], bad[MAXN];
bool keypos[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int g = 0, b = 0;
    for(int i = 1; i <= n; i++){
        if(std::gcd((long long)i, MOD) != 1) good[++g] = i;
        else bad[++b] = i;
    }
    int need = 0;
    int cur = 1;
    while(cur <= n){
        int p = min(cur + 1, n);
        keypos[p] = true;
        need++;
        cur = p + 2; 
    }
    if(g < need){
        cout << "Baka!";
        return 0;
    }
    int pg = 1, pb = 1;
    for(int i = 1; i <= n; i++){
        if(keypos[i]){
            ans[i] = good[pg++];
        }
        else{
            if(pb <= b) ans[i] = bad[pb++];
            else ans[i] = good[pg++];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i];
        if(i != n) cout << ' ';
    }
}

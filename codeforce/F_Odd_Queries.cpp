#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n, q;
        cin >> n >> q;

        vector<LL> pre(n + 1, 0);

        for(int i = 1; i <= n; i++){
            LL x;
            cin >> x;
            pre[i] = pre[i - 1] + x;
        }

        LL total = pre[n];

        while(q--){
            int l, r;
            LL k;
            cin >> l >> r >> k;

            LL oldPart = pre[r] - pre[l - 1];
            LL newPart = k * (r - l + 1LL);

            LL newTotal = total - oldPart + newPart;

            cout << (newTotal % 2 ? "YES\n" : "NO\n");
        }
    }
}
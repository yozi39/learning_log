#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;
        int ans = 0, cnt = 0;
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '1'){
                cnt++;
                if(cnt > ans) ans = cnt;
            }
            else{
                cnt = 0;
            }
        }
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                cnt++;
                if(cnt > ans) ans = cnt;
            }
            else{
                cnt = 0;
            }
        }
        cout << ans << '\n';
    }
}
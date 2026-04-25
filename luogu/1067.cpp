#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = n;
    int tmp;
    int first = 1;
    for(int i = 0; i <= n; i++){
        cin >> tmp;
        if(tmp == 0){
            cnt--;
            continue;
        }
        if(first == 1){
            if(tmp < 0) cout << "-";
        }
        else{
            if(tmp > 0) cout << "+";
            else cout << "-";
        }
        int x = abs(tmp);
        if(cnt > 1){
            if(x != 1) cout << x;
            cout << "x^" << cnt;
        }
        else if(cnt == 1){
            if(x != 1) cout << x;
            cout << "x";
        }
        else{
            cout << x;
        }
        first = 0;
        cnt--;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
long long a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, greater<long long>());

    long double sum = 0;
    long double ans = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        long double now = sum * sum / i;
        if(now > ans){
            ans = now;
        }
    }
    cout << fixed << setprecision(10) << (double)ans;
}
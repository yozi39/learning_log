#include<bits/stdc++.h>
using namespace std;

struct Node{
    int NO;
    long long t;
}a[10010];

bool cmp(Node x, Node y){
    if(x.t != y.t) return x.t < y.t;
    return x.NO < y.NO;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].t;
        a[i].NO = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        cout << a[i].NO << ' ';
    }
    cout << '\n';
    long long sum = 0;
    double ans = 0;
    for(int i = 1; i < n; i++){
        sum += a[i].t;
        ans += sum;
    }
    ans /= n;
    printf("%.2lf", ans);
}
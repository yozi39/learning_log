#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, fixedCnt;
int a[N];
int fa[N];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y){
    int fx = find(x);
    int fy = find(y);

    if(fx != fy){
        fa[fx] = fy;
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        fa[i] = i;
    }

    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i] == i){
            fixedCnt++;
        }

        unite(i, a[i]);
    }

    int sz[N] = {};

    for(int i = 0; i < n; i++){
        sz[find(i)]++;
    }

    bool hasTwoCycle = false;

    for(int i = 0; i < n; i++){
        if(find(i) == i && sz[i] == 2){
            hasTwoCycle = true;
            break;
        }
    }

    if(fixedCnt == n){
        cout << n;
    }else if(hasTwoCycle){
        cout << fixedCnt + 2;
    }else{
        cout << fixedCnt + 1;
    }
}
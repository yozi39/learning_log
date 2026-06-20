#include<bits/stdc++.h>
using namespace std;
//质数筛的强应用;
/*
涉及向上取整((l + p - 1) / p) * 1LL * p
以及初始化sqrt(r)
还有max(1LL * p * p, ((l + p - 1) / p) * 1LL * p);防止把原本自己质数变成和数
*/
typedef long long LL;

LL l, r;
const int N = 1000005;

bool vis[50005];   // 筛 sqrt(r) 内小质数
bool st[N];        // st[x-l] 表示 x 是合数
vector<int> prime;
int cnt;

void get_file(){
    int limit = sqrt(r);

    for(int i = 2; i <= limit; i++){
        if(!vis[i]){
            prime.push_back(i);
        }

        for(auto p : prime){
            if(1LL * i * p > limit) break;

            vis[i * p] = true;

            if(i % p == 0) break;
        }
    }
}

void get_prime(){
    for(auto p : prime){
        LL start = max(1LL * p * p, ((l + p - 1) / p) * 1LL * p);

        for(LL x = start; x <= r; x += p){
            st[x - l] = true;
        }
    }

    if(l == 1) st[0] = true;

    for(LL x = l; x <= r; x++){
        if(!st[x - l]){
            cnt++;
        }
    }
}

int main(){
    cin >> l >> r;

    get_file();
    get_prime();

    cout << cnt;
}
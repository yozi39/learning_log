#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e6+10;

LL a[N];
LL cnt=0;

void up(int x){
    while(x>1 && a[x]<a[x/2]){
        swap(a[x],a[x/2]);
        x/=2;
    }
}

void down(int x){
    while(x * 2 <= cnt){ // 只要有左孩子
        int son = x * 2; // 先假设左孩子更小

        if(son + 1 <= cnt && a[son + 1] < a[son]){
            son++; // 右孩子更小，就选右孩子
        }

        if(a[x] <= a[son]) break; // 父亲已经 <= 最小孩子，不用动

        swap(a[x], a[son]);
        x = son; // 继续往下检查
    }
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int op;
        LL x;
        cin >> op;

        if(op == 1){
            cin >> x;
            a[++cnt] = x;
            up(cnt);
        }
        else if(op == 2){
            cout << a[1] << '\n';
        }
        else if(op == 3){
            a[1] = a[cnt];
            cnt--;
            down(1);
        }
    }
}
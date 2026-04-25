#include<bits/stdc++.h>
using namespace std;

const int N = 10000;

int sum[N];   
int len;      

void MUL(int x){
    int carry = 0;
    for(int i = 0; i < len; i++){
        int t = sum[i] * x + carry;
        sum[i] = t % 10;
        carry = t / 10;
    }

    while(carry){
        sum[len] = carry % 10;
        carry /= 10;
        len++;
    }
}

void DIV(int x){
    int r = 0;
    for(int i = len - 1; i >= 0; i--){
        int t = r * 10 + sum[i];
        sum[i] = t / x;
        r = t % x;
    }

    while(len > 1 && sum[len - 1] == 0){
        len--;
    }
}

void FAC(int n){
    len = 1;
    sum[0] = 1;

    for(int i = 2; i <= n; i++){
        MUL(i);
    }
}

void print(){
    for(int i = len - 1; i >= 0; i--){
        cout << sum[i];
    }
}

int main(){
    int n;
    string x;
    cin >> n >> x;

    int wrd[30] = {0};

    for(int i = 0; i < n; i++){
        wrd[x[i] - 'A']++;
    }

    FAC(n);

    for(int i = 0; i < 26; i++){
        for(int j = 2; j <= wrd[i]; j++){
            DIV(j);
        }
    }

    cout << "1/";
    print();

    return 0;
}
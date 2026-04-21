#include<bits/stdc++.h>
using namespace std;

typedef struct No{
    int NO;
    int score;
}No;

int main(){
    int n,m;
    cin>>n>>m;
    No hum[n+1];
    int pass=m*1.5;
    for(int i=1;i<=n;i++)
        cin>>hum[i].NO>>hum[i].score;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(hum[i].score<hum[j].score ||
            (hum[i].score == hum[j].score && hum[i].NO > hum[j].NO)){
                swap(hum[i],hum[j]);
            }
        }
    }
    while(pass < n && hum[pass].score == hum[pass+1].score){
        pass++;
    }
    cout<<hum[pass].score<<' '<<pass<<'\n';
    for(int i=1;i<=pass;i++)
        cout<<hum[i].NO<<' '<<hum[i].score<<'\n';
}
//用结构体去处理交换两个高度绑定的数



/*
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5010;
int n, m, bar;
struct student {
    int id, score;
} s[maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i].id >> s[i].score;
    for(int i = 1; i <= n - 1; i++)
        for(int j = i + 1; j <= n; j++) {
            if(   s[i].score < s[j].score // 条件 1
                    || (s[i].score == s[j].score && s[i].id > s[j].id) ) // 条件2
                swap(s[i], s[j]);
        }
    bar = s[int(m * 1.5)].score; //算分数线

    int num = 0;
    while(s[num + 1].score >= bar)
        num ++;

    cout << bar << " " << num << endl;
    for (int i = 1; i <= num; i++)
        cout << s[i].id << ' ' << s[i].score << endl;
    return 0;
}


*/
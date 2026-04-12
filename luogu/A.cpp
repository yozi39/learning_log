#include<bits/stdc++.h>
using namespace std;

const long long MOD=999999999;
const int MAXN=100000+5;
int good[MAXN],bad[MAXN],keypos[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int g=0,b=0;
    for(int i=1;i<n+1;i++){
        if(std::gcd(i,MOD)!=1){
            good[++g]=i;
        }
        else{
            bad[++b]=i;
        }
    }
    int need=0;
    int cur=1;
    int k=0;
    while(cur<=n){
        keypos[++k]=min(cur+1,n);
        need++;
        cur=min(cur+1,n)+2;
    }
    k=1;
    int totalBad=b;
    int pg=1,pb=1;
    if(need>g){cout<<"Baka!";}
    else{
        for(int i=1;i<n+1;i++){
            if(i == keypos[pg]){
                cout<<good[pg]<<' ';
                k++;
                pg++;
            }
            else{
                if(pb<=totalBad){
                    cout<<bad[pb]<<' ';
                    pb++;
                }
                else{
                    cout<<good[pg]<<' ';
                    pg++;
                }
            }
        }
    }
}
//多变量维护,用keypos标记哪里未覆盖,之后用good配pg去定位
//为了防止一个bad不够问题需要在之后if判断多的地方用good补上
//维护good[]bad[]keypos[]vector可能更好用?
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
int a[N];

int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    LL sum=0,max=INT_MIN;
    LL val,ansv;
    sort(a+1,a+1+m,greater<int>());
    for(int i=1;i<=m;i++){
        val=a[i];
        if(n>=i){
            sum=val*i;
        }
        else{
            val=a[n];
            sum=n*val;
        }

        if(sum>=max){
            max=sum;
            ansv=val;
        }
    }
    cout<<ansv<<' '<<max;
}
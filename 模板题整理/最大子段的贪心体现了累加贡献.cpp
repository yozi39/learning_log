#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long max=-1e7;
    long long sum=0;
    for(int i=1;i<=n;i){
        if(sum>=0){
            sum+=a[i];
            i++;
        }
        if(sum>max)max=sum;
        if(sum<0)sum=0;
    }
    cout<<max;
}
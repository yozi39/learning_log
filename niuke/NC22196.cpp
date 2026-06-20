#include<bits/stdc++.h>
using namespace std;

int n,sum;

int main(){
    cin>>n;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            sum+=i;
            if(i!=n/i)sum+=n/i;
        }
    }
    cout<<sum;
}
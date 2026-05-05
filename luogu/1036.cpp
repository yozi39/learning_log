#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> a,num;
long long ans=0;
int sum=0;

bool is(int sum){//质数O(n)会超时所以用sqrt解决
    if(n<2)return false;
    for(int i=2;1LL*i*i<sum;i++){
        if(sum%i==0){
            return false;
        }
    }
    return true;
}

void dfs(int start){
    if(a.size()==k){
        // for(auto x:a){
        //     sum+=x;
        // }
        if(is(sum)){
            ans++;
        }
        return;
    }
    else{
        for(int i=start;i<n;i++){
            a.push_back(num[i]);
            sum+=num[i];
            dfs(i+1);
            a.pop_back();
            sum-=num[i];
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    dfs(0);
    cout<<ans;
}
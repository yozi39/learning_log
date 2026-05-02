#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
priority_queue<LL,vector<LL>,greater<LL>> heap;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        LL x;cin>>x;
        heap.push(x);
    }
    LL ans=0;

    while(heap.size()>1){
        LL x=heap.top();heap.pop();
        LL y=heap.top();heap.pop();
        ans+=x+y;
        heap.push(x+y);
    }
                        //差点忘记退回去ans了不然少加一次
                        //草了我把ans推进去了,emm.. += 愣是想成=了
    cout<<ans;
}
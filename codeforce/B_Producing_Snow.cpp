#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
LL v[N],t[N],pre[N];
vector<LL> day[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++){
        cin>>t[i];
        pre[i] = pre[i-1]+t[i];
    }

    for(int i=1;i<=n;i++){
        int l = i,r = n+1;
        while(l<r){
            int mid = (l+r)/2;
            if(pre[mid]-pre[i-1] >= v[i]){
                r = mid;
            } else {
                l = mid+1;
            }   
        }
        day[l].push_back(i);
    }

    LL skip = 0;
    for(int i=1;i<=n;i++){
        LL sum = 0;
        if(day[i].size()){
            for(auto y:day[i]){
                sum += v[y]-(pre[i-1]-pre[y-1]);
                skip++;
            }
        }
        sum+=t[i]*(i-skip);

        cout<<sum<<' ';
    }
}
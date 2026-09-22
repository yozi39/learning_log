#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,m,v;

int main(){
    cin>>n>>m>>v;

    if(m<n-1 || m>1LL*(n-1)*(n-2)/2+1){
        cout<<-1;
    } else {
        int leaf = (v == 1 ? 2 : 1);
        int need=m-(n-1);

        for(int i=1;i<=n;i++){
            if(i==v){
                continue;
            }

            cout<<i<<' '<<v<<'\n';
        }

        for(int i=1;i<=n && need>0;i++){
            if(i==leaf || i==v){
                continue;
            }

            for(int j=i+1;j<=n && need>0;j++){
                if(j==leaf || j==v){
                    continue;
                }

                cout<<i<<' '<<j<<'\n';
                need--;
            }
        }
    }
}
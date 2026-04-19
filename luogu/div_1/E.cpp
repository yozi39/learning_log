#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,m,c,d,k;
    cin>>a>>b>>m>>c>>d>>k;
    int start=a*60+b;
    int cross=c*60+d;
    if(cross<start) cross += 24*60;
    for(int i=k;i<=m;i+=k){
        int now=start+i,show;
        show =now;
        if(now >= cross){
            show -= 60;
        }
        show %= (24*60);
        if(show<0)show+=24*60;
        cout<<show/60<<' '<<show%60<<'\n';
    }
}
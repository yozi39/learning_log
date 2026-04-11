#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int zfx = 0, cfx = 0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int a=i;a<n+1;a++){
                for(int b=j;b<m+1;b++){
                    if((a-i)==(b-j) && !(a==i && b==j) &&(a-i)>=1&&(b-j)>=1){
                        zfx++;
                    }
                    if((a-i)!=(b-j) && !(a==i && b==j)&&(a-i)>=1&&(b-j)>=1){
                        cfx++;
                    }
                }
            }
        }
    }
    cout<<zfx<<' '<<cfx;
    return 0;
}

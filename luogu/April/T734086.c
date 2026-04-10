#include<stdio.h>
#define MOD 998244353LL

long long two[1000005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char a[n+1];
    char b[n+1];
    long long num_a=0;
    long long num_b=0;
    scanf(" %s",a);
    scanf(" %s",b);
    two[0] = 1;
    for(int i=1;i<n;i++){
        two[i]=(two[i-1]*2)%MOD;
    }
    for(int i=0;i<n;i++){
        if(a[n-1-i]=='1') num_a = (num_a + two[i])%MOD;
        if(b[n-1-i]=='1') num_b = (num_b + two[i])%MOD;
    }
    long long result=0;
    for(int i=0;i<m;i++){
        int change,where;
        scanf("%d %d",&change,&where);
        if(change==1){
            if(a[n-where-1]=='0'){
                num_a = (num_a + two[where])%MOD;
                a[n-where-1] = '1';
            }
            else {
                num_a = (num_a - two[where] + MOD)%MOD;
                a[n-where-1] = '0';
            }
        }
        else {
            if(b[n-where-1]=='0'){
                num_b = (num_b + two[where])%MOD;
                b[n-where-1] = '1';
            }
            else {
                num_b = (num_b - two[where] + MOD)%MOD;
                b[n-where-1] = '0';
            }
        }
        result = (num_a + num_b)%MOD;
        printf("%lld\n",result);
    }
}
//洛谷四月月赛第一题
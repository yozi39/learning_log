#include<stdio.h>
int main(){
    int x,y,z;
    int n,m;
    long long result=0;
    scanf("%d %d",&n,&m);
    int num[n+1];
    int color[n+1];
    for(int i=1;i<n+1;i++)scanf("%d",&num[i]);
    for(int i=1;i<n+1;i++)scanf("%d",&color[i]);
    for(int i=1;i<n+1;i++){
        x=i;
        for(int j=i+1;j<n;j++){
            y=j;
            if(2*j-i<=n)z=2*y-x;
            else break;
            if(color[x] == color[z]){
                result+=(long long)((x+z)*(num[x]+num[z]));
            }
        }
    }
    printf("%d",(int)result%10007);
}
//当然这个是初步思路,开始前就看到了10^5意味着大概用O(n)的复杂度所以我即将改进;
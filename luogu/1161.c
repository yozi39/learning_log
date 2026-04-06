#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int t[n];
    double a[n];

    for(int i=0;i<n;i++){
        scanf("%lf %d",&a[i],&t[i]);
    }
    int max=0;
    for(int i=0;i<n;i++){
        int compare=(int)(a[i]*t[i]);
        if(max<compare)max=compare;
    }
    int status[max+5];
    memset(status,0,sizeof(status));
    for(int i=0;i<n;i++){
        for(int j=1;j<t[i]+1;j++){
            status[(int)(j*a[i])]++;
        }
    }

    for(int i=1;i<max+1;i++){
        if(status[i]%2 == 1){
            printf("%d",i);
        }
    }
}

//debug printf 里面用n+1当成了上界来扫描,但是灯比登记次数要多
//tip 用max的值来防止数组开的过大
#include<stdio.h>
#include<math.h>

// int main(){
//     double r=8,c,s;
//     s = 3.14 * pow(r,2);
//     c = 2 * 3.14 * r ;
//     printf("面积是：%.2lf\n",s);
//     printf("周长是：%.2lf",c);
//     return 0;
// }



int main(){
    double x_1=2.0,y_1=8.0,x_2=6,y_2=5;
    double dist = sqrt(pow(fabs(x_1 - x_2) , 2) + pow(fabs(y_2 - y_1) , 2));
    printf("两个点之间的距离是：%lf",dist);
}
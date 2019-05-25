#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

double a[N];

int main(){
    int n;
    double lim;
    double ans=-1;
    scanf("%d%lf",&n,&lim);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    for(int i=1;i<=n-2;i++){
        int pos=lower_bound(a+i+2,a+n+1,a[i]+lim)-a;
        if(pos==n+1){
            if(a[i]+lim>=a[n])
                pos=n;
            else continue;
        }
        if(a[pos]>a[i]+lim) pos--;
        if(pos==i+1) continue;
        ans=max(ans,(a[pos]-a[i+1])/(a[pos]-a[i]));
    }
    printf("%.12f\n",ans);
}

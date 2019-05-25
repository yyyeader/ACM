#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2e5+5;

struct node{
    int a,t,id;
}arr[N];

bool cmp(node a,node b){
    return a.t<b.t;
}

int main(){
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&arr[i].a,&arr[i].t);
        arr[i].id=i;
    }
    sort(arr+1,arr+1+n,cmp);
    int l=1,r=n;
    int mmax=0,idx=-1;
    //二分枚举a的值
    while(l<=r){
        int mid=(l+r)/2;
        int t=0,k=0;
        for(int i=1;i<=n;i++){
            if(arr[i].a>=mid){
                t+=arr[i].t;
                if(t>T)
                    break;
                k++;
            }
        }
        if(min(k,mid)>mmax){
            mmax=min(k,mid);
            idx=mid;
        }
        if(k>=mid)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n%d\n",mmax,mmax);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt==mmax)
            break;
        if(arr[i].a>=idx){
            printf("%d ",arr[i].id);
            cnt++;
        }

    }
    printf("\n");
    return 0;
}

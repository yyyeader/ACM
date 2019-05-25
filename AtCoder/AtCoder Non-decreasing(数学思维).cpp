#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e3+5;

int a[N];

int main(){
    int n,ma=1,mi=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<a[mi]) 
			mi=i;
        if(a[i]>a[ma]) 
			ma=i;
    }
	printf("%d\n",2*n-1);
    if(abs(a[ma])>=abs(a[mi])){
        for(int i=1;i<=n;i++){
            printf("%d %d\n",ma,i);
        }
        for(int i=2;i<=n;i++){
            printf("%d %d\n",i-1,i);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            printf("%d %d\n",mi,i);
        }
        for(int i=n-1;i>=1;i--){
            printf("%d %d\n",i+1,i);
        }
    }
	return 0;
}

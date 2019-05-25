#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int a[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",a[(n+1)/2]);
	}
}

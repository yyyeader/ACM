#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+5;
int a[N];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		//nΪ�����ͽ���������൱��һ������ 
		if(n%2==1)
			a[++n]=0; 
		sort(a+1,a+1+n);
		int sum=0;
		for(int i=2;i<=n;i+=2){
			sum^=(a[i]-a[i-1]-1);
		}
		if(sum!=0)
			puts("Georgia will win");
		else
			puts("Bob will win");
	}
} 

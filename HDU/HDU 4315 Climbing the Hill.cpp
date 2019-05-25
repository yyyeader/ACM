#include<cstdio>
const int N=1e3+5;

int a[N];

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		if(k==1){
			puts("Alice");
			continue;
		}
		int sum=0;
		//n为奇数，让第一个棋子与最顶上形成第一个区间 
		if(n%2==1){
			//k==2时,第一个区间距离-1 
			a[0]=-1+(k==2);
			for(int i=1;i<=n;i+=2)
				sum^=(a[i]-a[i-1]-1);
		}
		else{
			for(int i=2;i<=n;i+=2)
				sum^=(a[i]-a[i-1]-1);
		}
		if(sum!=0)
			puts("Alice");
		else
			puts("Bob");
	}
} 

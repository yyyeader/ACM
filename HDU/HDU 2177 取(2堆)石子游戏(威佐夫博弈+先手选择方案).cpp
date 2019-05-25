#include<cstdio>
#include<cmath> 
#include<algorithm>
using namespace std;

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)&&(a||b)){
		if(a>b) swap(a,b);
		int k=b-a;
		int tmp=(int)(k*(sqrt(5)+1)/2.0);
		if(tmp==a)
			puts("0");
		else{
			puts("1");
			//两堆同时取，k不变，判断ak是否小于a 
			if(a>tmp){
				printf("%d %d\n",tmp,b-(a-tmp));
			}
			//取一堆，枚举0~b所有的差值 
			for(int i=0;i<=b;i++){
				int tmp2=(int)(i*(sqrt(5)+1)/2.0);
				//防止重复,例如7 10取两堆或一堆都会有4 7 
				if(tmp2==tmp)
					continue;
				if(tmp2==a&&b>tmp2+i||tmp2+i==a||tmp2+i==b&&a>tmp2){
					printf("%d %d\n",tmp2,tmp2+i);
				}		
			}	
		} 
	}
	return 0; 
} 

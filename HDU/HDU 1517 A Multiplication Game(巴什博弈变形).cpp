#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		int x=0;
		while(n>1){
			x++;
			if(x&1)
				n=ceil((double)n/9);
			else
				n=ceil((double)n/2);
		}
		if(x&1)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
}
 

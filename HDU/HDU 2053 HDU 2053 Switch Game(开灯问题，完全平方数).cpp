#include<cstdio>
#include<cmath> 
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int b=sqrt(n);
		if(b*b==n)
			puts("1");
		else
			puts("0");
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)&&(a||b)){
		int cnt=0;
		while(1){
			cnt++;
			if(a>b) 
				swap(a,b);
			if(b%a==0)	
				break;
			if(b-a>a) 
				break;
			b-=a;	
		}
		if(cnt&1)	puts("Stan wins");
		else	puts("Ollie wins");
	}
}

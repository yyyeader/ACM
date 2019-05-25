#include<cstdio>
#include<cmath> 

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int year,month,day;
		scanf("%d%d%d",&year,&month,&day);
		if(month==9&&day==30||month==11&&day==30)
			printf("YES\n");
		else{
			if((month+day)&1)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
}

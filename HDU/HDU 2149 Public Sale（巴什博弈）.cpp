#include<cstdio>
int main(){
	int m,n;
	while(~scanf("%d%d",&m,&n)){
		bool flag=false;
		if(m%(n+1)==0)
			printf("none");
		else{
			printf("%d",m%(n+1));
			//n>mµÄÇé¿ö
			for(int i=m+1;i<=n;i++)
				printf(" %d",i);
		}
		printf("\n");
	} 
	return 0;
} 

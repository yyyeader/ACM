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
			//����ͬʱȡ��k���䣬�ж�ak�Ƿ�С��a 
			if(a>tmp){
				printf("%d %d\n",tmp,b-(a-tmp));
			}
			//ȡһ�ѣ�ö��0~b���еĲ�ֵ 
			for(int i=0;i<=b;i++){
				int tmp2=(int)(i*(sqrt(5)+1)/2.0);
				//��ֹ�ظ�,����7 10ȡ���ѻ�һ�Ѷ�����4 7 
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

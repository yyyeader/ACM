#include<stdio.h>
#include<string.h>
int main(){
	int count[205]; 
	int q,n,end,start,area1,area2,max;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		memset(count,0,sizeof(count));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&start,&end);
			if(start>end){//可能出现大号房间往小号房间搬桌子 
				int temp=start;
				start=end;
				end=temp;
			}
			area1=(start+1)/2;
			area2=(end+1)/2;
			/*利用count数组记录下重叠区段，
			   房间是这样的：2,4,6,8,10，……
                             1,3,5,7,9，……
                1、2属于第一区段，4、3属于第二区段。。。 
			*/ 
			for(int j=area1;j<=area2;j++){
				count[j]++;
			}
		}
		max=0;
		for(int i=1;i<=200;i++){//重叠数最大的，就是必须经过的区段，答案即为最大重叠数*10 
			if(count[i]>max)
				max=count[i];
		}
		printf("%d\n",max*10);
	}
}

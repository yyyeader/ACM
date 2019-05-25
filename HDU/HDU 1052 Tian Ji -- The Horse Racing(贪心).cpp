#include<stdio.h>
#include<algorithm>
using namespace std;
struct Horse{
	int val;
	bool flag;
}a[1005],b[1005];
int cmp1(struct Horse a,struct Horse b){
	return a.val<b.val;
}
int cmp2(struct Horse a,struct Horse b){
	return a.val>b.val;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,sum,count,sign;
	
	while(~scanf("%d",&n)&&n!=0){
		sum=count=0;
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
			a[i].flag=true;
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i].flag=true;
		}
		sort(a,a+n,cmp2);//国王马匹速度从大到小 
		sort(b,b+n,cmp1);//田忌马匹速度从小到大 
		//尽可能用田忌马里比较慢的来赢国王，并且把能赢的先赢了 
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				//printf("a[%d]=%d b[%d]=%d\n",i,a[i].val,j,b[j].val);
				if(a[i].val<b[j].val&&b[j].flag&&a[i].flag){
					sum++;
					b[j].flag=false;
					a[i].flag=false;
					break;
					//printf("1 %d %d\n",a[i].val,b[i].val);
				}
			}
		}
		//再看看有哪些马可以打平手 
		for(i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i].val==b[j].val&&b[j].flag&&a[i].flag){
					b[j].flag=false;
					a[i].flag=false;
					//printf("0 %d %d\n",a[i].val,b[i].val);
					count++;
					break;
				}
			}
		}
		printf("%d\n",(sum-(n-sum-count))*200);
	} 
} 

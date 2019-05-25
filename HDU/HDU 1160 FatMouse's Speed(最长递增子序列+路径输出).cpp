#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e3+5;

struct node{
	int weight,speed,num;
}a[N];

struct node2{
	int len,pre,now;
}dp[N];

bool cmp(node a,node b){
	return a.weight==b.weight?a.speed<b.speed:a.weight<b.weight;
}

void print(int x){
	if(x==-1)
		return;
	print(dp[x].pre);
	printf("%d\n",dp[x].now);
}

int main(){
	int count=1; 
	while(~scanf("%d %d",&a[count].weight,&a[count].speed)){
		a[count].num=count;
		count++;
	}
	
	sort(a+1,a+count,cmp);
	int ans=0,idx;
	for(int i=1;i<=count-1;i++){
		dp[i].len=1;
		dp[i].now=a[i].num;
		dp[i].pre=-1;
		for(int j=1;j<=i;j++){
			if(a[i].speed<a[j].speed){
				if(dp[i].len<dp[j].len+1){
					dp[i].len=dp[j].len+1;
					dp[i].pre=j;
				}
			}
		}
		if(dp[i].len>ans){
			ans=dp[i].len;
			idx=i;
		}
	}
	printf("%d\n",ans);
	print(idx);
	return 0;
}

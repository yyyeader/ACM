#include<cstdio>
#include<cstring>

const int N=1<<16;
const int inf=1<<30;

struct node{
	int cost,deadl;
	char name[15];
}a[30];

//pre代表前一个二进制状态，now表示这个状态下对应的课程序号（如3就是第三节课），time代表总花费时间，score表示扣掉的分数
struct node2{
	int score,pre,now,time;
}dp[N];

void Output(int x){
	if(x==0) return;
	if(x!=0)
		Output(dp[x].pre);
	printf("%s\n",a[dp[x].now].name);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s%d%d",a[i].name,&a[i].deadl,&a[i].cost);
			
		int lim=1<<n;
		for(int i=1;i<lim;i++){
			dp[i].score=inf;
			//根据递归输出科目名的方式,j从n-1~1可以使得相同条件先上前面的科目 
			for(int j=n-1;j>=0;j--){
				int tmp=1<<j;
				if(tmp&i){
					int past=i-tmp;
					int add=dp[past].time+a[j].cost-a[j].deadl;
					if(add<0)
						add=0;
					//找到最小扣分情况，状态转移，选取最优解
					if(add+dp[past].score<dp[i].score){
						dp[i].score=add+dp[past].score;
						dp[i].time=dp[past].time+a[j].cost;
						dp[i].pre=past;
						dp[i].now=j;
					}
				}
			}
		}
		printf("%d\n",dp[lim-1].score);
		//打印科目名字 
		Output(lim-1);
	}
	return 0;
}

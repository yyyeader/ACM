#include<cstdio>
#include<cstring>

const int N=1<<16;
const int inf=1<<30;

struct node{
	int cost,deadl;
	char name[15];
}a[30];

//pre����ǰһ��������״̬��now��ʾ���״̬�¶�Ӧ�Ŀγ���ţ���3���ǵ����ڿΣ���time�����ܻ���ʱ�䣬score��ʾ�۵��ķ���
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
			//���ݵݹ������Ŀ���ķ�ʽ,j��n-1~1����ʹ����ͬ��������ǰ��Ŀ�Ŀ 
			for(int j=n-1;j>=0;j--){
				int tmp=1<<j;
				if(tmp&i){
					int past=i-tmp;
					int add=dp[past].time+a[j].cost-a[j].deadl;
					if(add<0)
						add=0;
					//�ҵ���С�۷������״̬ת�ƣ�ѡȡ���Ž�
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
		//��ӡ��Ŀ���� 
		Output(lim-1);
	}
	return 0;
}

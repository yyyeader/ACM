#include<cstdio>
const int N=5e4+5;

int root[N],val[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%3;//为了保证偏移量，比如有"x吃y"信息,root[y]=x,val[x]=0,val[y]=1偏移量为1。 
	return root[x]=tmp;			//若出现"z吃x"信息 ,则val[x]=1,此时val[y]=val[x]+val[y]=2,保证了原来的偏移量。 
}

int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	while(k--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(x>n||y>n){
			ans++;
			continue;
		}
		int t1=find(x),t2=find(y);
		//检查x和y是否已经存在关系 
		if(t1==t2){
			if(t==1&&val[x]!=val[y]) 
				ans++;
			if(t==2&&(val[x]+1)%3!=val[y])
				ans++;
			continue;
		}
		if(t==1){
			root[t2]=t1;				//合并 
			val[t2]=(val[x]-val[y]+3)%3;//val[t2]为x->y的偏移量，利用val[t2]使得val[y]+val[t2]=val[x]+1,以满足"x吃y "。 
		}
		else{
			root[t2]=t1;				//同理 
			val[t2]=(val[x]-val[y]+1+3)%3;
		}
	}
	printf("%d\n",ans);
	return 0;
}

#include<cstdio>
const int N=5e4+5;

int root[N],val[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%3;//Ϊ�˱�֤ƫ������������"x��y"��Ϣ,root[y]=x,val[x]=0,val[y]=1ƫ����Ϊ1�� 
	return root[x]=tmp;			//������"z��x"��Ϣ ,��val[x]=1,��ʱval[y]=val[x]+val[y]=2,��֤��ԭ����ƫ������ 
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
		//���x��y�Ƿ��Ѿ����ڹ�ϵ 
		if(t1==t2){
			if(t==1&&val[x]!=val[y]) 
				ans++;
			if(t==2&&(val[x]+1)%3!=val[y])
				ans++;
			continue;
		}
		if(t==1){
			root[t2]=t1;				//�ϲ� 
			val[t2]=(val[x]-val[y]+3)%3;//val[t2]Ϊx->y��ƫ����������val[t2]ʹ��val[y]+val[t2]=val[x]+1,������"x��y "�� 
		}
		else{
			root[t2]=t1;				//ͬ�� 
			val[t2]=(val[x]-val[y]+1+3)%3;
		}
	}
	printf("%d\n",ans);
	return 0;
}

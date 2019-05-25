#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std; 
typedef long long LL;
const int inf=0x3f3f3f3f;

int n,deep,ans;
char DNA[5]="ACGT";
char str[10][10];

int Max(int a,int b){
	return a>b?a:b;
}

void dfs(int index,int len[]){
	if(ans!=-1)
		return;
	int h=0;//���������ٻ�Ҫ���ӵ��ַ����� 
	for(int i=1;i<=n;i++)
		h=Max(h,strlen(str[i])-len[i]);
	if(h==0){
		ans=deep;
		return; 
	}
	if(h+index>deep)//��ǰ���+Ԥ����С���>������� 
		return;
	int pos[10]={0};
	for(int i=0;i<4;i++){	
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(str[j][len[j]]==DNA[i]){
				flag=true;
				pos[j]=len[j]+1;
			}
			else
				pos[j]=len[j];
		}
		if(flag&&index+1<=deep)//��֦����flag˵�����ۼ�ʲô���޷�ʹn���ַ�����Ϊ�Ӵ�
			dfs(index+1,pos);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int mlen=0;//����Ӵ����� 
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			mlen=Max(strlen(str[i]),mlen);
		}
		
		int pos[10]={0};//n���ַ�����ǰƥ�䵽��λ�� 
		deep=mlen;
		ans=-1;
		while(1){
			dfs(0,pos);
			if(ans!=-1)
				break;
			deep++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 

#include<stdio.h>
int main(){
	//freopen("in.txt","r",stdin);
	long long n,ans,q;//����̫����long long 
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&n);
		long long temp=1;
		ans=n;
		ans%=10;// ȡ�಻Ӱ�����ս�� 
		while(n!=1){
			if(n%2==1){//���n%2==1������3*3*3,��ans=(3*3), ����һ��3�ճ����ˣ���temp���� 
				temp*=ans;
				temp%=10;
			}
			ans*=ans;//ans*ans�������Խ�����Ϊn�εĹ���,����Ϊn/2��,����4*4*4*4=��4*4��*��4*4��,��4�α�Ϊ2�Σ�    
			ans%=10;
			n/=2;
		}
		ans*=temp;
		ans%=10;
		printf("%lld\n",ans);
	}
}

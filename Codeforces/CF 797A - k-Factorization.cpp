#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
vector<int>v;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int d=2;
	while(k&&n>=d){//n>=d��ΪҪ��֤n�ǹ����ģ�����˵�����ֽܷ��k������ 
		if(k==1){//k=1ʱ�����һ���������ǳ�ʣ�µ��Ǹ� 
			v.push_back(n);
			k--;
			break;
		}
		if(n%d==0){//n�ܱ�d���� 
			n/=d;
			k--;
			v.push_back(d);
		}
		else//���n���ܱ�d����,˵��n������d���Ѿ������ˣ���d��ֵ��Ҫ���� 
			d++;
	}
	if(k)//�ղ���k�� 
		printf("-1\n");
	else{
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
	} 
} 

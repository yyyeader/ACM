#include<stdio.h>
int count=0,line[10],n;
void search(int x){	//�ݹ��������н� 
	int i,j,ok;
	if(x==n+1) {//��x=nʱ��˵��ÿһ�еĻʺ󶼲���ͻ����Ϊ���н� 
	  	for(i=1;i<n+1;i++){
	  		if(i!=n)
			  printf("%d ",line[i]);
			 else
			  printf("%d\n",line[i]);
		}
		count++;
		return;
	}
		for(i=1;i<=n;i++)
		{
			ok=1;
			line[x]=i;//���԰ѵ�x�еĻʺ����i����
			for(j=1;j<x;j++)//�����Ƿ������ѷźó�ͻǰ�Ļʺ�
			{
				if(line[x]==line[j]||x-line[x]==j-line[j]||x+line[x]==j+line[j])
				{
					ok=0;
					break;//�������ڲ�ѭ�������ͻ��ֹͣ������������һ���ݹ���ݡ�
				}
			}
			if(ok==1)
				search(x+1);
		}
}
int main(){
	scanf("%d",&n);
	search(1);
	printf("%d\n",count);
}

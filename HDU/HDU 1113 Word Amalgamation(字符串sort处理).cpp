#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct node{
	char s[10];
	char st[10];
}r[1005];
bool cmp(node a,node b){
	return strcmp(a.s,b.s)<0;
}
int main(){
	int cnt=0;
	char temp[10];
	while(~scanf("%s",temp)){
		if(strcmp(temp,"XXXXXX")==0)
			break;
		strcpy(r[cnt].s,temp);//*��������ʰ���ĸ��С�����������У������������ʱȽ�ʱ����֪���Ƿ������ĸ��ͬ��  
		sort(temp,temp+strlen(temp));
		strcpy(r[cnt].st,temp);
		cnt++;
	}
	sort(r,r+cnt,cmp);//*���ֵ��еĵ��ʰ���ĸ��С˳���źã�������ĿҪ�� 
	int flag=0;//��ʾ�Ƿ��ܴ��ֵ����ҵ���Ӧ���� 
	while(~scanf("%s",temp)){
		if(strcmp(temp,"XXXXXX")==0)
			break;
		flag=0;
		sort(temp,temp+strlen(temp));//ͬ�ϰѸõ��ʴ��Ұ���С�����ź� 
		for(int i=0;i<cnt;i++){
			if(strcmp(r[i].st,temp)==0){
				printf("%s\n",r[i].s);
				flag=1;
			}
		}
		if(flag==0)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
}

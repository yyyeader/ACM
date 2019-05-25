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
		strcpy(r[cnt].s,temp);//*把这个单词按字母从小到大重新排列，这样两个单词比较时可以知道是否组成字母相同；  
		sort(temp,temp+strlen(temp));
		strcpy(r[cnt].st,temp);
		cnt++;
	}
	sort(r,r+cnt,cmp);//*把字典中的单词按字母大小顺序排好（符合题目要求） 
	int flag=0;//表示是否能从字典中找到对应单词 
	while(~scanf("%s",temp)){
		if(strcmp(temp,"XXXXXX")==0)
			break;
		flag=0;
		sort(temp,temp+strlen(temp));//同上把该单词打乱按从小到大排好 
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

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;

map<string,int>mp;
int main(){
	char s[30];
	while(gets(s)){
		if(strlen(s)==0)//�õ�����ʱ������Ϊ0 
			break;
		for(int i=strlen(s);i>0;i--){
			s[i]='\0';
			mp[s]++;
		}//������һ��һ��ֿ��������ص����ֵĴ��� 
	}
	while(gets(s)){
		printf("%d\n",mp[s]);
	}	
}

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;

map<string,int>mp;
int main(){
	char s[30];
	while(gets(s)){
		if(strlen(s)==0)//得到空行时，长度为0 
			break;
		for(int i=strlen(s);i>0;i--){
			s[i]='\0';
			mp[s]++;
		}//将单词一点一点分开，计算重叠部分的次数 
	}
	while(gets(s)){
		printf("%d\n",mp[s]);
	}	
}

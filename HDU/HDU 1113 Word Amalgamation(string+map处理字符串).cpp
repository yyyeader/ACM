#include<stdio.h>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

map<string,string>mp;
int main(){
	string s,temp;
	while(cin>>s&&s!="XXXXXX"){//ע��string����Ҫ��cin>>���룬string���Ϳ���ֱ�ӱȽϲ���strcmp() 
		temp=s;
		sort(temp.begin(),temp.end());
		mp.insert(pair<string,string>(s,temp));//ע�����ﲻ��map[s]=temp���ַ�ʽ���Ժ����������� 
	}
	int flag;
	while(cin>>s&&s!="XXXXXX"){
		flag=0;
		map<string,string>::iterator it;//��������������it 
		sort(s.begin(),s.end());
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second==s){//���ڶ����ּ�����С����������������ĸ��� 
				flag=1;
				cout<<it->first<<endl;//�����һ���ּ��ֵ��е����� 
			}
		}
		if(flag==0)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
}

#include<stdio.h>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

map<string,string>mp;
int main(){
	string s,temp;
	while(cin>>s&&s!="XXXXXX"){//注意string类型要用cin>>输入，string类型可以直接比较不用strcmp() 
		temp=s;
		sort(temp.begin(),temp.end());
		mp.insert(pair<string,string>(s,temp));//注意这里不用map[s]=temp这种方式，以后都用这种类型 
	}
	int flag;
	while(cin>>s&&s!="XXXXXX"){
		flag=0;
		map<string,string>::iterator it;//迭代器类型声明it 
		sort(s.begin(),s.end());
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second==s){//若第二部分即按从小到大打乱排序过的字母相等 
				flag=1;
				cout<<it->first<<endl;//输出第一部分即字典中的内容 
			}
		}
		if(flag==0)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
}

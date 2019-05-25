#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

int main(){
	char eng[12],mar[12],temp[12],ch;
	map<string,string>mp;
	gets(temp);
	while(scanf("%s %s",eng,mar)){
		if(strcmp(eng,"END")==0) break;
		mp[mar]=eng;
	}
	getchar();
	int k=0;
	while(~scanf("%c",&ch)){
		if(isalpha(ch)) temp[k++]=ch;
		else{
			temp[k]='\0';k=0; 
			if(strcmp(temp,"END")==0) break;
			else{
				if(mp.find(temp)!=mp.end())
					cout<<mp[temp];
				else
					printf("%s",temp);
				putchar(ch);
			}
		}
	}
}

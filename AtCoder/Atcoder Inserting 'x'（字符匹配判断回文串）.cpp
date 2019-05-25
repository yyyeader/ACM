#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int cnt[30];
char s[N];

int main(){
	scanf("%s",s);
	bool sign=false;
	for(int i=0;s[i]!='\0';i++){
		cnt[s[i]-'a']++;
		if(s[i]!='x')
			sign=true;
	}
	//可能全为x 
	if(!sign){
		puts("0");
		return 0;
	}
	int count=0;
	char ch;
	for(int i=0;i<26;i++){
		if(cnt[i]&&cnt[i]%2==1&&i!='x'-'a'){
			count++;
		}			
	}
	if(count>1)
		puts("-1");
	else{
		int sum=0,ans=0;
		int i=0,j=strlen(s)-1;
		bool flag;
		if(count==0){
			while(i<j){
				flag=false;
				while(i<j&&s[i]=='x'){
					sum++;
					i++;
				}
				while(i<j&&s[j]=='x'){
					sum--;
					j--;
				}
				if(s[i]==s[j]){
					flag=true;
					//注意如xxabxxbax的情况特判 
					if(s[i]!='x')
						ans+=abs(sum);
					i++,j--;
					sum=0;
				}		
				else
					break;
			}
		}
		else{
			while(i<=j){
				flag=false;
				while(i<=j&&s[i]=='x'){
					sum++;
					i++;
				}
				while(i<=j&&s[j]=='x'){
					sum--;
					j--;
				}
				if(s[i]==s[j]){
					flag=true;
					ans+=abs(sum);
					i++,j--;
					sum=0;
				}
				else
					break;
			}
		}
		if(!flag)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}

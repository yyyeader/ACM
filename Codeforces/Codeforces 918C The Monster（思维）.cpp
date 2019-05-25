#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int low,high,size;
	string str;
	cin>>str;
	size=str.size();
	int ans=0;
	for(int i=0;i<size;i++){
		low=high=0;
		for(int j=i;j<size;j++){
			if(str[j]=='(') high++,low++;
			if(str[j]==')') high--,low--;
			if(str[j]=='?') high++,low--;
			if(high<0)
				break;
			if(low<0) low=0;
			if((j-i)%2&&low==0)
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0; 
}

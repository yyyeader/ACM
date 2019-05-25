#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	int a,b,x;
	cin>>a>>b>>x;
	string str="";
	if(x%2==0){
		int d=x/2;
		if(a>b){
			while(d--) str+="01",a--,b--;
			while(b--) str+="1";
			while(a--) str+="0";
		}
		else{
			while(d--) str+="10",a--,b--;
			while(a--) str+="0";
			while(b--) str+="1";
		}
	}
	else{
		int d=x/2+1;
		while(d--)	str+="10",a--,b--;
		while(a--)
			str=str+"0";
		while(b--)
			str="1"+str;
	}
	cout<<str<<endl;
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int N=105;

struct node{
	string name;
	int qgd;
	int bgd;
	string ifxg;
	string ifxb;
	int lws;
}a[N];

int main(){
	int n;
	while(cin>>n){
		string name;
		int mmax=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].name>>a[i].qgd>>a[i].bgd>>a[i].ifxg>>a[i].ifxb>>a[i].lws;
			int sum=0;
			if(a[i].qgd>80&&a[i].lws>0)
				sum+=8000;
			if(a[i].qgd>85&&a[i].bgd>80)
				sum+=4000;
			if(a[i].qgd>90)
				sum+=2000;
			if(a[i].qgd>85&&a[i].ifxb=="Y")
				sum+=1000;
			if(a[i].bgd>80&&a[i].ifxg=="Y")
				sum+=850;
			if(sum>mmax){
				mmax=sum;
				name=a[i].name;
			}
			ans+=sum;
		}
		cout<<name<<endl;
		cout<<mmax<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

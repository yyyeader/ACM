#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int N=2e5+5;
string p,t;
int a[N];

bool binary_search(const string& t,const string &p,int index){
	string tp=t;
	for(int i=1;i<=index;i++){
		tp[a[i]]='#';
	}
	int j=0;
	bool sign=false;
	for(int i=1;i<t.size();i++){
		if(tp[i]==p[j])
			j++;
		if(j==p.size()){
			sign=true;
			break;
		}
	}
	return sign; 
}

int main(){
	cin>>t>>p;
	t=' '+t; 
	for(int i=1;i<t.size();i++)
		cin>>a[i];
	int l=1,r=t.size()-1;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(binary_search(t,p,mid)){
			l=mid+1;
		}	
		else
			r=mid-1;
	}
	cout<<r<<endl;
}

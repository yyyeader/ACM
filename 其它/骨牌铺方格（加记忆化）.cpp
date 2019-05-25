#include<iostream>
#include<cstring>
using namespace std;

long long f[105];

long long fib(int x){
	if(f[x]!=-1)
		return f[x];
	if(x==1)
		return 1;
	if(x==2)
		return 2;
	f[x]=fib(x-1)+fib(x-2);
	return f[x];
}

int main(){
	memset(f,-1,sizeof(f));
	int n;
	while(cin>>n)
		cout<<fib(n)<<endl;
	return 0;
}

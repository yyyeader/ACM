#include<iostream>
using namespace std;

long long fib(int x){
	if(x==1) 
		return 1;
	if(x==2)
		return 2;
	return fib(x-1)+fib(x-2);
}

int main(){
	int n;
	while(cin>>n)
		cout<<fib(n)<<endl;
	return 0;
}

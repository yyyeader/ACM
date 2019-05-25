#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	while(cin>>n)
		cout<<(n*n*n+5*n)/6+1<<endl;
	return 0;
}

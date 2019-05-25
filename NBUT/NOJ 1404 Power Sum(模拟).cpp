#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<math.h>
#define LL long long
using namespace std;

int main(){
	LL n,m;
	while(cin>>m>>n){
		LL sum=0;
		for(int i=0;i<=n;i++){
			sum+=pow(m*1.0,i);
		}
		cout<<sum<<endl;
	}
	return 0;
}

#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;

int main(){
	int x,y,z;
	while(cin>>x>>y>>z){
		int ans=x+y+z-__gcd(x,y)-__gcd(x,z)-__gcd(y,z)+__gcd(__gcd(x,y),z);
		printf("%d\n",ans);
	}
}

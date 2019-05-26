#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int n,x;
	int a[105]={0},b[105]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}		
	for(int i=1;i<=n;i++){
		cin>>x;
		b[x]++;
	}
	int acount=0,bcount=0;
	bool sign=true;
	for(int i=1;i<=5;i++){
		if(abs(a[i]-b[i])%2==1){//出现奇数个差，无论怎么交换都不可能相等 
			sign=false;
		}
		else{
			if(a[i]>b[i])
				acount+=a[i]-b[i];
			else
				bcount+=b[i]-a[i];	
		}
	}
	if(sign&&acount==bcount)//两者不同数的差数相同则刚好可以交换 	
		cout<<acount/2<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}

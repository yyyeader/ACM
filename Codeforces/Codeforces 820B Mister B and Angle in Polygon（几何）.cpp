#include<iostream>
#include<cstring>
using namespace std;

double abs(double a){
	return a>0?a:-a;
}

int main(){
	int n,a;
	cin>>n>>a;
	double ave=180.0/n;
	double min=1<<30;
	int index;
	for(int i=1;i<=n-2;i++){
		double num=ave*i;
		if(abs(a-num)<min){
			index=i;
			min=abs(a-num);
		}
	}
	cout<<1<<" "<<n<<" "<<1+index<<endl;
}

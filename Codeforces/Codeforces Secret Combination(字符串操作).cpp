#include<iostream>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
const int N=1e3+5;

char swap(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}

int main(){
	//freopen("in.txt","r",stdin);
	long long n;
	char a[N]=" -1",temp[N];
	cin>>n;
	cin>>temp+1;
	//�������С�����������һ��ͺ��ˣ���10�λ���ԭ���ģ����Լ�9�Σ�������n+1�λ���ԭ���ģ�����������n��
	//����ÿ�μ�һ������n��; 
	for(int i=0;i<=9;i++){
		for(int j=1;j<=n;j++){
			if(i!=0)
				temp[j]+=1;
			if(temp[j]>'9')
				temp[j]='0';
		}
		for(int k=1;k<=n;k++){
			for(int j=n;j>=2;j--){
				swap(temp[j-1],temp[j]);
			}	
			if(strcmp(a+1,"-1")==0){
				for(int j=1;j<=n;j++){
					a[j]=temp[j];
				}
			}
			else{
				if(strcmp(a+1,temp+1)>0){
					for(int j=1;j<=n;j++){
						a[j]=temp[j];
					}
				}
			}
		}	
	}
	for(int j=1;j<=n;j++){
		cout<<a[j];
	}
	cout<<endl;
} 

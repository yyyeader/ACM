#include<iostream>
#include<cstdio>
using namespace std;
const int M=3e7+3e6;
unsigned long long a[M],l,r,ans=0,count=0;

void dfs(unsigned long long n){
	//�����Ѿ���¼���ģ�����l��ߵģ�����ֱ������ 
	if(n<M){
		if(a[n]&&count+a[n]<l){
			count+=a[n];
			return;
		}		
	}
	//����r�Ͳ��������� 
	if(count>r)
		return;
	if(n==0||n==1){
		count++;
		if(count<=r&&count>=l){
			ans+=n;
		}
			return;
	}
	dfs(n/2);	
	dfs(n%2);
	dfs(n/2);
	//������һ����¼����Ȼ�ᳬʱ��a[n]����n��ȫ�ֽ���Էֳɶ��ٸ�����1��0�� 
	if(n<M){
		if(!a[n]){
			a[n]=count;
		}	
	}	
}

int main(){
	unsigned long long x;
	cin>>x>>l>>r;
	//ֱ�Ӹ������ⱬ�� 
	dfs(x);
	cout<<ans<<endl;
	cout<<count<<endl;
}

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<string>v;
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		v.push_back(t);
	}
	//**�Ե����ϱȽϣ��������Ա�֤��һ�αȽϲ���Ӱ��֮ǰ�Ľ����Ҳ�����ַ���ֻ�ø�һ�Ρ�������ϵ��±Ƚϣ��ַ������ĺ��ֵ�����ܻ��Ǳȸ�����Ĵ򣬻ᷴ������ 
	for(int i=n-1;i>=1;i--){
		string t1=v[i];
		string t2=v[i-1];
		if(t1>=t2)
			continue;
		else{
				int l=min(t1.size(),t2.size());
				int pos=0;
				for(int j=1;j<l;j++){
					if(t1[j]<t2[j]){
						pos=j;
						break;
					}						
				}
				if(pos==0)
					t2=t2.substr(0,t1.size());
				else
					t2=t2.substr(0,pos);
				v[i-1]=t2;
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<v[i]<<endl;
	}
} 

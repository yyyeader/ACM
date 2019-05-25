#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=5e5+5;

int dp[N][28];

int main(){
	FAST_IO;
	int n,k;
	string str,s1,s2;
	cin>>n>>k;
	cin>>str;
	s1=str,s2=str;
	int ans=0,sum=0;
	if(k==2){
		for(int i=0;i<n;i++){
			if(i%2&&s1[i]!='A')
				sum++,s1[i]='A';
			else if(i%2==0&&s1[i]!='B')
				sum++,s1[i]='B';
		}
		ans=sum;
		sum=0;
		for(int i=0;i<n;i++){
			if(i%2&&s2[i]!='B')
				sum++,s2[i]='B';
			else if(i%2==0&&s2[i]!='A')
				sum++,s2[i]='A';
		}
		ans=min(ans,sum);
		cout<<ans<<endl;
		if(ans==sum)
			cout<<s2<<endl;
		else
			cout<<s1<<endl;
	}
	else{
		for(int i=1;i<n;i++){
			if(str[i]==str[i-1]){
				ans++;
				for(int j=0;j<k;j++){
					if(i!=n-1){
						if('A'+j!=str[i-1]&&'A'+j!=str[i+1]){
							str[i]='A'+j;
							break;
						}
					}
					else{
						if('A'+j!=str[i-1]){
							str[i]='A'+j;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		cout<<str<<endl;
	}
	return 0;
}

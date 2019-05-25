#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;

int cnt;
int a[N],b[N];
char c[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	scanf("%s",c+1);
	int size=strlen(c+1);
	int l=-1,r=-1;
	for(int i=1;i<=size;i++){
		if(c[i]=='1'){
			if(l==-1)
				l=r=i;
			else
				r=i;
		}
		else{
			if(l!=-1)
				sort(a+l,a+r+2);
			l=r=-1;
		}
	}
	if(l!=-1)
		sort(a+l,a+r+2);
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])
			flag=false;
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}

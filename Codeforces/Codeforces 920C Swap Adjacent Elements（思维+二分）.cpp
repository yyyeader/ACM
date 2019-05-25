#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;

struct node{
	int l,r;
}fw[N];

int cnt;
int a[N],b[N],idx[N];
char c[N];

int bin_search(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(x>=fw[mid].l&&x<=fw[mid].r)
			return mid;
		else if(x<fw[mid].l)		
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		idx[a[i]]=i;
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
				fw[++cnt].l=l,fw[cnt].r=r+1;
			l=r=-1;
		}
	}
	if(l!=-1)
		fw[++cnt].l=l,fw[cnt].r=r+1;
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			int idx1=idx[b[i]];
			int idx2=idx[a[i]];
			int t1=bin_search(idx1),t2=bin_search(idx2);
			if(t1==-1&&t2==-1||t1!=t2){
				flag=false;
				break;
			}
		}
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}

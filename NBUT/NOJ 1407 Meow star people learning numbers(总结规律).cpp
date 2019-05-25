#include<iostream>
#include<cstring>
#include<string>
#define LL long long
using namespace std;

LL f[15];

LL pw(LL x,LL n){
	if(n==0) return 1;
	LL res=1;
	for(int i=1;i<=n;i++) res*=x;
	return res;
}

LL s_to_num(char *x,int l){
	LL num=0;
	int len=strlen(x);
	for(int i=l;i<len;i++) 
		num=num*10+x[i]-'0';
	return num;
}

LL cal(char *x,int l,int len){
	if(len==1) return 1;
	LL sum=0;
	sum+=f[len-1];
	if(x[l]=='1') sum+=s_to_num(x,l+1)+1;
	else sum+=pw(10,len-1)+f[len-1];
	if(x[l]-'0'>1)
		sum+=(x[l]-'0'-2)*f[len-1];
	return sum;
}

//AACBDE
int main(){
	for(int i=1;i<=9;i++) f[i]=pw(10,i-1)+10*f[i-1];
	char s[15],num[15];
	while(~scanf("%s",s)){
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='J')
				num[i]='0';
			else
				num[i]=s[i]-'A'+1+'0';
		}
		num[len]='\0';
		LL ans=0;
		for(int i=0;i<len;i++){
			if(num[i]!='0')
				ans+=cal(num,i,len-i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

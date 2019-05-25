#include<cstdio>
#include<cstring>
char s1[1005],s2[1005];

int main() {
	while(~scanf("%s%s",s1,s2)){
		int len1=strlen(s1)-1;
		int len2=strlen(s2)-1;
		int t1=s1[len1]-'0';
		int t2=s2[len2]-'0';
		if(t1%5==1||t1%5==4||t1%5==0||t2%5==1||t2%5==4||t2%5==0)
			puts("Izetta");
		else
			puts("Zofi");
	}
}

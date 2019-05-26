#include<stdio.h>
#include<string.h>
char s[120];
int main(){
	char s1[100][100];
	int count=0;
	int sign=1;
	int num=0;
	gets(s);
	int l=strlen(s);
	for(int i=l-1;i>=0;i--){
		s[i+50]=s[i];
	}
	for(int j=50;j<=50+l-1;j++){
		s1[0][j-50]=s[j];
	}
	num++;
	for(int i=l-1+50;i>0+50;i--){
		sign=0;
		s[i-l]=s[i];
		/*for(int j=i-l;j<i;j++){
			printf("%c",s[j]);
		}
		printf("\n");*/
		for(int k=0;k<num;k++){
			int cnt1=0;
			for(int j=i-l;j<i;j++,cnt1++){
				if(s1[k][cnt1]!=s[j]){
					sign++;
					break;
				}
			}
		}
		if(sign==num){
			int cnt1=0;
			for(int j=i-l;j<i;j++,cnt1++){
				s1[num][cnt1]=s[j];
			}
			num++;
		}
	}
	printf("%d\n",num);
}

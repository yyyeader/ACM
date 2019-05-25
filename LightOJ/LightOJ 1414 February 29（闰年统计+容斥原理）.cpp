#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[20][20]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
char tmp[20];

int jg_month(void){
	for(int i=1;i<=12;i++){
		if(!strcmp(tmp,s[i])){
			return i;
		}
	}
}

bool is_leap(int year){
	if(year%4==0&&year%100!=0||year%400==0)
		return true;
	else
		return false;
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int day1,year1,month1,day2,year2,month2;
		scanf("%s%d,%d",tmp,&day1,&year1);		
		month1=jg_month();
		scanf("%s%d,%d",tmp,&day2,&year2);
		month2=jg_month();
		//根据容斥原理 
		int ans=(year2/4-year1/4)-(year2/100-year1/100)+(year2/400-year1/400);
		//根据year1,year2的月份进行特判 
		if(month1<=2&&is_leap(year1))
			ans++; 
		if(is_leap(year2)&&!(month2>=3||month2==2&&day2==29))
			ans--;
		printf("Case %d: %d\n",++cas,ans);		
	}
	return 0;
} 

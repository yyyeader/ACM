#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
const int M=3005;
char bra[N];
char map[M][M];
int rec[N];
int pow[N];
int main(){
	int n;
	int count=0;
	cin>>n;
	memset(map,' ',sizeof(map));
	int mpower=1;//mpowerΪ���Ƕ�ײ��� 
	for(int i=1;i<=n;i++){	
		cin>>bra[i];
		if(bra[i]=='['){
			count++;
			rec[i]=count;
			if(count>mpower)
				mpower=count;
		}	
		else {
			rec[i]=count;
			count--;
		}
	}
	
	int mh=mpower*2+1;//mhΪ���߶� 
	int cur=0;//cur��ʾ��ǰ����ַ���λ�� 
	int mlevel=0;//mlevel��ʾ 
	for(int i=1;i<=n;i++){
		cur++;
		if(bra[i]=='['){	
			mlevel=rec[i];
			for(int j=i+1;;j++){
				if(bra[j]==']')
					break;
				mlevel=rec[j];
			}
			int power=mpower+1-rec[i];				
			int start=mpower-power+1;
			map[start][cur]='+';
			map[start][cur+1]='-';
			for(int j=start+1;j<=start+power*2-1;j++){
				map[j][cur]='|';
			}
			start=start+power*2;
			map[start][cur]='+';
			map[start][cur+1]='-';
		}
		else if(bra[i]==']'){
			int power=mpower+1-rec[i];
			if(rec[i]==mlevel)//********
				cur+=3;
			int start=mpower-power+1;
			map[start][cur-1]='-';
			map[start][cur]='+';
			for(int j=start+1;j<=start+power*2-1;j++){
				map[j][cur]='|';
			}
			start=start+power*2;
			map[start][cur-1]='-';
			map[start][cur]='+';
		}
	}
	
	for(int i=1;i<=mh;i++){
		for(int j=1;j<=cur;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

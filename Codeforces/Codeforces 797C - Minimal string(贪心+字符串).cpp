#include<iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
int main(){
	string s,u;
	stack<char>t;
	int a[300]={0};//����a��¼s�и�����ĸ������ 
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	int cur=0;
	char c='a';//c��ʾ��ǰҪ��s�в��ҵ��ַ� 
	//̰�ģ������Ƚ��ֵ���С����ĸ��� 
	while(s[cur]!='\0'){
		while(!t.empty()){//�ж��Ѿ�����t�е���ĸ�����һ���Ƿ��cС���ǵĻ������һֱ��ǰ�ҵ���c��Ϊֹ 
			char ch=t.top();
			if(ch>c)
				break;
			t.pop();
			cout<<ch;
		}
		//printf("\ncur=%d %c %d\n",cur,c,t.size()); 
		if(a[c]){
			if(s[cur]==c){//����ҵ�c����� 
				//u+=c;
				cout<<c;
				a[c]--;
			}
			else{//û�ҵ��ȴ���t�� 
				t.push(s[cur]);
				a[s[cur]]--;
			}
				
			cur++;//����һ�� 
		}
		else//��a[c]==0˵����ǰ��ĸ�����ˣ�����һ����ĸ 
			c++;
		}	
		while(!t.empty()){
			//printf("1\n");
			char ch=t.top();
			t.pop();
			cout<<ch;	
		}
		cout<<endl;
} 

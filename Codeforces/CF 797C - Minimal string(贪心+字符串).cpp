#include<iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
int main(){
	string s,u;
	stack<char>t;
	int a[300]={0};//数组a记录s中各个字母的数量 
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	int cur=0;
	char c='a';//c表示当前要在s中查找的字符 
	//贪心：尽量先将字典序小的字母输出 
	while(s[cur]!='\0'){
		while(!t.empty()){//判断已经存在t中的字母的最后一个是否比c小，是的话输出并一直往前找到比c大为止 
			char ch=t.top();
			if(ch>c)
				break;
			t.pop();
			cout<<ch;
		}
		//printf("\ncur=%d %c %d\n",cur,c,t.size()); 
		if(a[c]){
			if(s[cur]==c){//如果找到c就输出 
				//u+=c;
				cout<<c;
				a[c]--;
			}
			else{//没找到先存入t中 
				t.push(s[cur]);
				a[s[cur]]--;
			}
				
			cur++;//找下一个 
		}
		else//当a[c]==0说明当前字母找完了，找下一个字母 
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

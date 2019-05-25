#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int power[256];

//ÖÐ×º×ªºó×º 
string infix_to_suffix(string infix){
	stack<char>sk;
	string suffix="";
	int i=0;
	while(i<infix.length()){
		char ch=infix[i];
		if(!power[ch]){
			suffix+=ch;
			while(++i<infix.length()&&!power[infix[i]]) suffix+=infix[i];
			suffix+=" ";
			continue;
		}
		if(power[ch]!=-1){
			while(!sk.empty()){
				char t=sk.top();
				if(power[t]>=power[ch]){
					suffix=suffix+t+" ";
					sk.pop();
				}
				else break;
			}
			sk.push(ch);
		}
		else{
			if(ch=='(')
				sk.push(ch);
			else{
				while(!sk.empty()){
					char t=sk.top();
					sk.pop();
					if(t=='(') break;
					suffix=suffix+t+" ";
				}
			}
		}
		i++;
	}
	while(!sk.empty()){
		char t=sk.top();
		sk.pop();
		suffix=suffix+t+" ";
	}
	return suffix;
} 

double cal_suffix(string suffix){
	stack<double>sk;
	int i=0;
	while(i<suffix.length()){
		char ch=suffix[i];
		if(ch==' '){
			i++;
			continue;
		}
		if(!power[ch]){
			double num=0;
			int sign=1;
			if(ch=='-') sign=-1;
			else if(ch=='+') sign=1;
			else num=num*10+ch-'0';
			double p=0;
			while(++i<suffix.length()&&!power[suffix[i]]&&suffix[i]!=' '){
				ch=suffix[i];
				if(ch=='.'){
					p=0.1;
					continue;
				}
				if(p!=0){
					num=num+(ch-'0')*p;
					p*=0.1;
				}
				else num=num*10+ch-'0';
			}
			sk.push(num);
		}
		else{
			double l,r,res;
			r=sk.top();sk.pop();
			l=sk.top();sk.pop(); 
			if(ch=='+') res=l+r;
			if(ch=='-') res=l-r;
			if(ch=='*') res=l*r;
			if(ch=='/') res=l/r;
			sk.push(res);
		}
		i++;
	}
	return sk.top();
}

int main(){
	power['-']=power['+']=1;
	power['*']=power['/']=2;
	power['(']=power[')']=-1;
	string infix,suffix;
	while(cin>>infix){
		suffix=infix_to_suffix(infix);
		double ans=cal_suffix(suffix);
		printf("%.4f\n",ans);
	}
	return 0;
}


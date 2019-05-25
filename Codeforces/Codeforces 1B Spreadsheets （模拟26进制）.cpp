#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;

int main(){
    FAST_IO;
    string str;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        bool flag=false;
        for(int j=0;j<str.size()-1;j++){
            if(isdigit(str[j])&&!isdigit(str[j+1]))
                flag=true;
        }
        int idx=0,num1=0,num2=0;
        if(flag){
            idx++;
            while(isdigit(str[idx])){
                num1=num1*10+str[idx]-'0';
                idx++;
            }
            idx++;
            while(idx<str.size()){
                num2=num2*10+str[idx]-'0';
                idx++;
            }
            stack<char>sk;
            while(num2){
                //这里注意分类讨论,错了好久
                if(num2%26==0){
                    sk.push('Z');
                    num2=num2/26-1;
                }
                else{
                    sk.push(num2%26+'A'-1);
                    num2/=26;
                }
            }
            while(!sk.empty()){
                cout<<sk.top();
                sk.pop();
            }
            cout<<num1<<endl;
        }
        else{
            while(!isdigit(str[idx])){
                num1=num1*26+str[idx]-'A'+1;
                idx++;
            }
            while(isdigit(str[idx])&&idx<str.size()){
                num2=num2*10+str[idx]-'0';
                idx++;
            }
            cout<<"R"<<num2<<"C"<<num1<<endl;
        }
    }
	return 0;
}

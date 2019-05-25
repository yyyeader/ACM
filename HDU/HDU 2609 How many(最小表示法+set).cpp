#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N=1e6+5;

int len;
char p[N];

//求最大/最小表示
int min_max_express(int flag){
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=p[(i+k)%len]-p[(j+k)%len];
        if(t==0) k++;
        else{
            if(flag){
                if(t<0) j+=k+1;
                else i+=k+1;
            }
            else{
                if(t>0) j+=k+1;
                else i+=k+1;
            }
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j);
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        set<string>st;
        for(int i=0;i<n;i++){
            scanf("%s",p);
            len=strlen(p);
            char tmp[105];
            int cnt=0,min_idx;
            min_idx=min_max_express(1);
            for(int j=0;j<len;j++){
                int idx=(min_idx+j)%len;
                tmp[cnt++]=p[idx];
            }
            tmp[cnt]='\0';
            st.insert(tmp);
        }
        printf("%d\n",st.size());
    }
    return 0;
}

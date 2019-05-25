#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int n,m;
int nxt[N],p[N],s[N];

void getnext(){
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int kmp(){
    getnext();
    int i=0,j=0;
    while(i<n){
        while(j!=-1&&s[i]!=p[j])
            j=nxt[j];
        i++,j++;
        if(j==m)
            return i-m+1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        cout<<kmp()<<endl;
    }
    return 0;
}

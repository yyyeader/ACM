#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using  namespace std;
typedef long long LL;
const int N=1e6+5;
map<int,int>mp;
set<int>st;
int a[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st.insert(a[i]);
        mp[a[i]]++;
    }
    //根据数字个数分类讨论一下就行了，注意size==2时，最大值比最小值大2要额外讨论
    auto it=st.begin();
    if(st.size()==1||st.size()==2&&*(it)+1==*(++it)){
        printf("%d\n",n);
        for(int i=1;i<=n;i++){
            printf("%d%c",a[i],i==n?'\n':' ');
        }
    }
    else{
        int t1,t2,t3;
        it=st.begin();
        if(st.size()==2)
            t1=*it,t3=*(++it),t2=t1+1;
        else
            t1=*it,t2=*(++it),t3=*(++it);
        int cnt1=mp[t1],cnt2=mp[t2],cnt3=mp[t3];
        int a1,a2,b1,b2,c1,c2,ans1,ans2;
        int tmp=cnt2/2;
        a1=cnt1+tmp;
        b1=cnt2%2;
        c1=cnt3+tmp;
        ans1=min(a1,cnt1)+min(b1,cnt2)+min(c1,cnt3);
        if(cnt1>cnt3){
            a2=cnt1-cnt3;
            b2=cnt2+2*cnt3;
            c2=0;
        }
        else{
            a2=0;
            b2=cnt2+2*cnt1;
            c2=cnt3-cnt1;
        }
        ans2=min(a2,cnt1)+min(b2,cnt2)+min(c2,cnt3);
        if(ans1<ans2){
            printf("%d\n",ans1);
            while(a1--)
                printf("%d ",t1);
            while(b1--)
                printf("%d ",t2);
            while(c1--)
                printf("%d ",t3);
        }
        else{
            printf("%d\n",ans2);
            while(a2--)
                printf("%d ",t1);
            while(b2--)
                printf("%d ",t2);
            while(c2--)
                printf("%d ",t3);
        }
    }
    return 0;
}

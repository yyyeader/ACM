#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int inf = 1<<30;

struct node{
    string name;
    int dead,cost;
} a[50];

struct kode{
    int time,score,pre,now;
} dp[1<<15];

void print(int n){
	if(n){
		print(dp[n].pre);
		cout<<a[dp[n].now].name<<endl;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	
    int t,i,j,s,n,end;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(i = 0; i<n; i++)
            cin >> a[i].name >> a[i].dead >> a[i].cost;
        end = 1<<n;
        for(s = 1; s<end; s++)//s从1到2^15
        {
            dp[s].score = inf;//这个状态下扣掉的分数初始化为无穷大 
            for(i = n-1; i>=0; i--)
            {
                int tem = 1<<i;
                if(s & tem)
                {
                    int past = s-tem;//上一个状态下这个位置为0，即s-tem使得这个位置为0 
                    int st = dp[past].time+a[i].cost-a[i].dead;//计算一下要扣掉的分数 
                    if(st<0)//小于0说明没有到达期限即不扣分 
                        st = 0;
                    //如果这个状态下要扣掉的分数较小，那就把这个上次这个位置的状态更新为现在的状态 
                    if(st+dp[past].score<dp[s].score)
                    {
                        dp[s].score = st+dp[past].score;
                        dp[s].now = i;
                        dp[s].pre = past;
                        dp[s].time = dp[past].time+a[i].cost;
                    }
                }
            }
        }
        int tem=end-1;
        cout << dp[tem].score << endl;
        print(tem);
    }
    return 0;
}


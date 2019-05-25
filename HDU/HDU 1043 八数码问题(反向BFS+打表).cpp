#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
const int N =370000;
typedef long long ll;//long long
int vis[N];
string path[N];
ll fac[9] = { 1,1,2,6,24,120,720,5040,40320 };//0~8阶乘
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//上右左下
char index[5] = "durl";//因为是反向搜索所以要反一下

struct node {
	char status[10];//当前组成的数字串
	string path;//路径
	int x_position;//x的位置
}start;

ll get_hash(char* s)//求康托展开值
{
	ll sum = 0;
	for (int i = 0; i < 9; i++)
	{
		ll num = 0;
		for (int j = i + 1; j < 9; j++)
			if (s[j] < s[i])num++;
		sum += (num*fac[8 - i]);
	}
	return sum;
}
//反向BFS打表
bool bfs() {
	queue<node>q;
	memset(vis, 0, sizeof(vis));
	node pre, now;
	//开始点，即“12345678x”的初始化
	for (int i = 0; i <= 7; i++) {
		start.status[i] = i + '1';
	}
	start.status[8] = '0';
	start.status[9] = '\0';
	start.x_position = 8;
	start.path = "";

	q.push(start);
	while (!q.empty()) {
		pre = q.front();
		q.pop();
		int x = pre.x_position / 3;
		int y = pre.x_position % 3;
		for (int i = 0; i < 4; i++) {
			int tx = x + d[i][0];
			int ty = y + d[i][1];
			if (tx < 0 || tx>2 || ty < 0 || ty>2)
				continue;
			int new_position = tx * 3 + ty;
			now = pre;
			now.status[pre.x_position] = pre.status[new_position];
			now.status[new_position] = pre.status[pre.x_position];
			ll tmp = get_hash(now.status); 
			if (!vis[tmp]) {
				now.path = index[i]+now.path;
				now.x_position = new_position;
				path[tmp] = now.path;
				vis[tmp] = 1;
				q.push(now);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	char s[15]="123456780";
	cout<<get_hash(s)<<endl;
	char ch;
	bfs();//打表
	while (cin >> ch) {
		char s[10];
		if (ch == 'x') s[0] = '0';
		else s[0] = ch;
		for (int i = 1; i <= 8; i++) {
			cin >> ch;
			if (ch == 'x') s[i] = '0';
			else s[i] = ch;
		}
		s[9] = '\0';
		ll aim = get_hash(s);
		if (vis[aim]) {
			cout << path[aim] << endl;
		}
		else {
			cout << "unsolvable" << endl;
		}
	}
	return 0;
}


#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;
int p[107];

int dp[107][10007];

set<int> sum;

//_i番目で総和が_sum
int dfs(int _i,int _sum)
{
	//printf("[debug]:%d,%d %d\n",_i,_sum,dp[_i][_sum]);
	if(dp[_i][_sum]!=-1) return dp[_i][_sum];
	int res=0;
	if(_i == n-1)
	{
		int sum1 = _sum + p[_i];
		if(sum.find(_sum)==sum.end())
		{
			//printf("[debug]:%d\n",_sum);
			sum.insert(_sum);
			return 1;
		}
		else return 0;

		if(sum.find(sum1)==sum.end())
		{
			//printf("[debug]:%d\n",sum1);
			sum.insert(sum1);
			return 1;
		}
		else return 0;

	}

	res+=dfs(_i+1,_sum);
	res+=dfs(_i+1,_sum+p[_i+1]);

	return dp[_i][_sum]=res;

	

}


int main()
{
	rep(i,107) rep(j,10007) dp[i][j]=-1;
	cin>>n;
	rep(i,n) cin>>p[i];

	dfs(0,0);
	dfs(0,p[0]);
/*
	set<int>::iterator it = sum.begin();
	while(it!=sum.end())
	{
		cout<<*it<<endl;
		it++;
	}
*/
	cout<<sum.size()<<endl;
	return 0;
}



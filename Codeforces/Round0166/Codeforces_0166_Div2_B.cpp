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

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long ull;
typedef long long ll;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

bool is_prime[100007];
vector<int> vec;

int n,m;
int mat[505][505];
int col[505];
int row[505];

int main()
{
	fill(is_prime,is_prime+100007,true);
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<100007;i++)
	{
		if(is_prime[i])
		{
			for(int j=i+i;j<100007;j+=i) is_prime[j]=false;
		}
	}
	rep(i,100007) if(is_prime[i]) vec.pb(i);

	cin>>n>>m;
	rep(i,n) rep(j,m) cin>>mat[i][j];

	rep(i,n) rep(j,m)
	{
		int index=lower_bound(all(vec),mat[i][j])-vec.begin();
		col[i]+=(vec[index]-mat[i][j]);

	}
	rep(i,m) rep(j,n)
	{
		int index=lower_bound(all(vec),mat[j][i])-vec.begin();
		row[i]+=(vec[index]-mat[j][i]);
	}
	int ans=INF;

	rep(i,m)
		ans=min(ans,row[i]);
	rep(i,n)
		ans=min(ans,col[i]);
	cout<<ans<<endl;



	


	return 0;
}



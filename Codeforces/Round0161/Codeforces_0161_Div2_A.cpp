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

int ans=0;
int mat[5][5];

int main()
{
	rep(i,5) rep(j,5) cin>>mat[i][j];

	int x,y;
	rep(i,5) rep(j,5) if(mat[i][j]==1) x=i,y=j;
	
	ans=abs(x-2)+abs(y-2);
	cout<<ans<<endl;


	return 0;
}



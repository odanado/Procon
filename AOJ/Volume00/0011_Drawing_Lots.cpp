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

int n,m;
vector<int> vec;
int main()
{
	cin>>n;
	rep(i,n+1)
	{
		vec.pb(i);
	}

	cin>>m;

	rep(i,m)
	{
		int a,b;
		scanf("%d,%d",&a,&b);
		swap(vec[a],vec[b]);
	}
	rep(i,n+1)
	{
		if(!i) continue;
		cout<<vec[i]<<endl;
	}
	


	return 0;
}



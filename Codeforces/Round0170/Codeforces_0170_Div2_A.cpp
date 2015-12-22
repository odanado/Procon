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

int n;
int a[107];
int s,t;
int ans;

int main()
{
	cin>>n;
	rep(i,n) cin>>a[i];

	cin>>s>>t;
	s--;
	t--;
	if(s>t) swap(s,t);
	for(int i=s;i<t;i++)
		ans+=a[i];
	int temp=0;
	for(int i=s-1;i>=0;i--)
		temp+=a[i];
	for(int i=n-1;i>=t;i--)
		temp+=a[i];
	ans=min(temp,ans);
	cout<<ans<<endl;

	return 0;
}



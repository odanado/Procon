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
int A,G;
vector<P> vec;
multimap<int,int> map1;
bool flag=false;
int main()
{
	int suma=0,sumb=0;
	cin>>n;
	vector<string> ans(n,"A");
	rep(i,n)
	{
		int a,b;
		cin>>a>>b;
		map1.insert(mp(a-b,i));
		vec.pb(mp(a,b));
		suma+=a;
		sumb+=b;
	}
	if(suma>=sumb)
	{
		sumb=0;
	}
	else
	{
		suma=0;
		ans.clear();
		rep(i,n) ans.pb("G");
	}
	multimap<int,int>::iterator it=map1.begin();
	while(abs(suma-sumb)>500)
	{
		if(it==map1.end())
		{
			puts("-1");
			return 0;
		}
		int index=it->sc;
		if(ans[index]=="A")
		{
			ans[index]="G";
			suma-=vec[index].fr;
			sumb+=vec[index].sc;
		}
		else
		{
			ans[index]="A";
			suma+=vec[index].fr;
			sumb-=vec[index].sc;

		}
		++it;

	}
	rep(i,n) cout<<ans[i];
	cout<<endl;
	
	return 0;
}



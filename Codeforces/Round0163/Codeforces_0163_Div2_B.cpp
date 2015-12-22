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

int n,t;
string str;

int main()
{
	cin>>n>>t;
	cin>>str;
	str+=" ";
	
	rep(i,t)
	{
		rep(j,n)
		{
			if(str[j]=='B'&&str[j+1]=='G')
				swap(str[j],str[j+1]),j++;

		}
	}
	cout<<str<<endl;

	return 0;
}



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


class ShoutterDiv2
{
public:
	
	int count(vector <int> s, vector <int> t)
	{
		int ans=0;
		int n=s.size();

		rep(i,n)
		{
			for(int j=i;j<n;j++)
			{
				if(t[i]<=s[j])
				{
					ans++;
					cout<<t[i]<<","<<s[j]<<endl;
				}
			}
		}
		return ans;


	};

};

int main()
{
	


	return 0;
}



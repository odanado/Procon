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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
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
int S[30007],E[30007];

int a[487];

int main()
{
	cin>>n;
	rep(i,n) scanf("%d-%d",S+i,E+i);

	rep(i,n)
	{
		while(S[i]%5!=0) S[i]--;
		while(E[i]%5!=0) E[i]++;
		ostringstream os;
		os<<E[i];
		string tmp=os.str();
		if(tmp[tmp.size()-2]=='6') E[i]+=40;
	}

	rep(i,n)
	{
		for(int j=S[i]/5;j<E[i]/5;j++) a[j]++;
		//cout<<S[i]<<","<<E[i]<<endl;
	}

	bool f=false;
	for(int i=0;i<=481;i++)
	{
		if(!f && a[i]!=0)
		{
			printf("%04d-",i*5);
			f=true;
		}
		if(f && a[i]==0)
		{
			printf("%04d\n",(i)*5);
			f=false;
		}

	}

	//rep(i,480) cout<<a[i]<<endl;

	
		return 0;
}



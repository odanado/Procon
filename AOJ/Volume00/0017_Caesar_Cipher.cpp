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

char ss[1024];
int n;

bool check()
{
	//the, this, that
	rep(i,n-4)
	{
		if(ss[i]=='t'&&ss[i+1]=='h'&&ss[i+2]=='i'&&ss[i+3]=='s') return true;
		if(ss[i]=='t'&&ss[i+1]=='h'&&ss[i+2]=='a'&&ss[i+3]=='t') return true;
		if(ss[i]=='t'&&ss[i+1]=='h'&&ss[i+2]=='e') return true;

	}
	return false;

}

void f()
{

	rep(i,n)
	{
		if(ss[i]=='\n') break;
		if(ss[i]==' '||ss[i]=='.') continue;
		char c=ss[i];
		c++;
		c-=19;
		c=c%26;
		ss[i]=(c+'a');
	}

}
int main()
{
	while(fgets(ss,sizeof(ss),stdin)!=NULL)
	{
		n=strlen(ss);
		//[97,122]
		//%97
	
		rep(i,26)
		{
			if(check())
			{
				printf("%s",ss);
				goto go;
			}
			f();
			//cout<<ss;
		}
go:;
	}
	
	return 0;
}


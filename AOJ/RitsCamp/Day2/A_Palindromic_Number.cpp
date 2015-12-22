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

bool check(int a)
{
	ostringstream os;
	os<<a;
	string str=os.str(),str1,str2;

	int b=str.size();
	str1=str.substr(0,b/2);
	str2=str.substr(b/2+b%2,b);
	reverse(all(str2));

	return (str1==str2);

}

int main()
{
	cin>>n;
	int ans;
	int temp;
	for(int i=n;i<=10001;i++)
	{
		if(check(i))
		{
			temp=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		//if(abs(n-i)<abs(temp-i)) break;
		if(check(i))
		{
			ans=i;
			break;
		}
	}
	if(abs(ans-n)>abs(temp-n)) ans=temp;
	cout<<ans<<endl;
	
	


	return 0;
}



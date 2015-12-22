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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

map<string,int> strs;
int n;

/*
vector<string> split(string _str)
{
	vector<string> res;
	string tmp="";
	rep(i,_str.size())
	{
		if(_str[i]==' ')
		{
		//	cout<<tmp<<endl;
			res.pb(tmp);	
			tmp="";
			continue;
		}
		else if('a'<=_str[i] && _str[i]<='z')
		{
			tmp +=_str[i];
			
		}
	}
	res.pb(tmp);
	//cout<<res<<endl;
	return res;
}

void inputs()
{
	getchar();
	rep(i,n)
	{
		string str;
		getline(cin,str);

	//	cout<<"[debug]"<<str<<endl;
		//cout<<"[debug]"<<tmp<<endl;
		vector<string> tmp;
		tmp=split(str);


		rep(i,tmp.size())
		{
			cout<<"[debug]"<<tmp[i]<<endl;
			strs[tmp[i]]++;
		}

		
	}

}
//*/

void inputs()
{
	getchar();
	rep(i,n)
	{
		string str;
		getline(cin,str);
		stringstream ss(str);
		while(ss>>str)
			strs[str]--;
	
	}

}
int main()
{
	while(cin>>n)
	{
		if(!n) return 0;
		inputs();

		//cout<<"Hoge"<<endl;
		string c;cin>>c;

		vector<pair<int,string> > vec;
		vector<string> ans;
		
		FOR(it,strs)
		{
			if(c[0] == it->fr[0])
				vec.pb(mp(it->sc,it->fr));
		}

		sort(all(vec));

		int cnt=0;
		FOR(it,vec)
		{
			if(cnt==5) break;
			if(cnt) cout<<" "<<it->sc;
			else cout<<it->sc;
			cnt++;
		}

		if(!cnt) cout<<"NA";
		cout<<endl;

		
		strs.clear();

	}


		return 0;
}



#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<math.h>
#include<string>
#include<stack>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string str;

void solve() {
	stack<char> sta;
	rep(i,str.size()) {
		if(str[i]=='('||str[i]=='[') sta.push(str[i]);
		if(str[i]==')') {
			if(sta.empty()) {
				cout<<"no"<<endl;
				return;
			}
			if(sta.top()!='(') {
				cout<<"no"<<endl;
				//cout<<i<<endl;
				return;
			}
			else {
				sta.pop();
			}
		}
		if(str[i]==']') {
			if(sta.empty()) {
				cout<<"no"<<endl;
				return;
			}
			if(sta.top()!='[') {
				cout<<"no"<<endl;
				//cout<<i<<endl;
				return;
			}
			else {
				sta.pop();
			}
		}
	}
	if(sta.empty()) {
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

}

int main() {
	while(getline(cin,str)) {
		if(str==".") return 0;
		solve();
	}

	return 0;
}

/* 2014/05/07 AC */
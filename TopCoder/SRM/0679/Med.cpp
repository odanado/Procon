#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

template <typename List>
void split(const std::string& s, const std::string& delim, List& result)
{
    result.clear();

    using string = std::string;
    string::size_type pos = 0;

    while(pos != string::npos )
    {
        string::size_type p = s.find(delim, pos);

        if(p == string::npos)
        {
            result.push_back(s.substr(pos));
            break;
        }
        else {
            result.push_back(s.substr(pos, p - pos));
        }

        pos = p + delim.size();
    }
}

struct Team {
    string name;
    int score;
    Team(string name="",int score=0) :
         name(name), score(score){}
    bool operator<(const Team &rhs) const {
        if(score != rhs.score) return score > rhs.score;
        return name < rhs.name;
    }
};
struct Submission {
    int score;
    int time;
    Submission(int score=0, int time=0) :
        score(score), time(time) {}
};

class ContestScoreboard {
public:
    int to_i(const string &s) {
        stringstream ss;
        int n;
        ss << s;
        ss >> n;
        return n;
    }
    Submission toSub(const string &s) {
        vector<string> vec;
        split(s,"/",vec);
        return Submission(to_i(vec[0]), to_i(vec[1]));
    }
    
    vector<Submission> parse(string s, string &name) {
        vector<Submission> subs;
        vector<string> vec;
        split(s, " ", vec);
        name=vec[0];
        rep(i,vec.size()) if(i) {
            subs.pb(toSub(vec[i]));
        }
        /*
        cout<<name<<": ";
        for(auto &sub:subs) {
            cout<<sub.score<<"/"<<sub.time<<" ";
        }
        cout<<endl;
        */
        return subs;
    }
    map<string, Team> teams;
    map<string, vector<Submission> > teamSubs;
    vector<string> names;
    map<string, int> ids;
    vector <int> findWinner(vector <string> scores) {
        rep(i,scores.size()) {
            string name;
            auto tmp = parse(scores[i], name);
            ids[name]=names.size();
            names.pb(name);
            teams[name] = Team(name, 0);
            teamSubs[name] = tmp;
        }
        set<int> checkPoint;
        checkPoint.insert(0);
        for(auto &name : names) {
            for(auto &sub : teamSubs[name]) {
                checkPoint.insert(sub.time);
            }
        }
        vector<int> ans(scores.size());
        for(auto time : checkPoint) {
            vector<Team> t;
            for(auto &name : names) {
                int s=getScore(name, time);
                t.pb(Team(name,s));
            }
            sort(all(t));
            auto name = t.front().name;
            ans[ids[name]]=1;

            /*
            cout<<"time: "<<time<<endl;
            for(auto team : t) {
                cout<<team.name<<", "<<team.score<<endl;
            }
            cout<<endl;
            //*/
        }

        return ans;
    }
    int getScore(const string &name, int t) {
        int s=0;
        for(auto sub : teamSubs[name]) {
            if(t>=sub.time) s += sub.score;
        }

        return s;
    }
};

int main() {
    ContestScoreboard obj;
    vector<string> vec;
    /*
    vec.pb("TVG 10/7 1/4 1/5");
    vec.pb("AJI 1/4 1/5 1/6");
    */
    vec={"GCAAW 893/291 84/682 285/257 48/228 665/834", 
        "RYRO 718/783 103/153", 
        "MPFI 436/662 724/3 218/652 587/660", 
        "VHGOPCD 318/769 729/683 440/681 2/302 317/598", 
        "MMHKM 652/81 997/901 632/90 669/752 567/960 264/698 449/459 967/54 821/885 658/272 356/207 976/528", 
        "HVKWAE 983/758 289/319"};
    auto ans=obj.findWinner(vec);
    for(auto e:ans) cout<<e<<endl;
    return 0;
}


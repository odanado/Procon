#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<string> split(const string &s, char d) {
    vector<string> ret;
    string s2;
    for (auto e : s) {
        if (d == e) {
            ret.push_back(s2);
            s2 = "";
        } else {
            s2 += e;
        }
    }
    if (s2.size()) ret.push_back(s2);
    return ret;
}

int N;
vector<string> words;
char query;

void solve() {
    map<string, int> cnt;
    for (auto word : words) {
        cnt[word]++;
    }
    vector<pair<int, string>> vec;
    for (auto e : cnt) {
        if (e.first[0] == query) {
            vec.push_back(make_pair(-e.second, e.first));
        }
    }
    sort(vec.begin(), vec.end());
    int M = min(5, (int)vec.size());
    if (vec.size()) {
        rep(i, M) {
            cout << vec[i].second;
            if (i + 1 != M) cout << " ";
        }
    } else {
        cout << "NA";
    }
    cout << endl;
}
int main() {
    while (cin >> N, N) {
        words.clear();
        cin.ignore();
        rep(i, N) {
            string s;
            getline(cin, s);
            auto vec = split(s, ' ');
            for (auto e : vec) words.push_back(e);
        }
        cin >> query;
        solve();
    }
}

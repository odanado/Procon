// 構文解析の練習
// https://gist.github.com/draftcode/1357281
#include <cctype>
#include <string>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef string::const_iterator State;
class ParseError{};
int number(State&);
int term(State&);
int expression(State&);
int factor(State&);

int number(State& begin) {
    int ret = 0;
    while(isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}
int term(State& begin) {
    int ret = factor(begin);

    while(1) {
        if(*begin == '*') {
            begin++;
            ret *= factor(begin);
        }
        else if(*begin == '/') {
            begin++;
            ret /= factor(begin);
        }
        else {
            break;
        }
    }

    return ret;

}
int expression(State& begin) {
    int ret = term(begin);

    while(1) {
        if(*begin == '+') {
            begin++;
            ret += term(begin);
        }
        else if(*begin == '-') {
            begin++;
            ret -= term(begin);
        }
        else {
            break;
        }
    }
    return ret;

}
int factor(State& begin) {
    int ret = 0;
    if(*begin == '(') {
        begin++; // ( を飛ばす
        ret = expression(begin);
        begin++; // ) を飛ばす
    }
    else {
        ret = number(begin);
    }

    return ret;
}

int main() {
    int N;
    cin>>N;
    cin.ignore();
    rep(i,N) {
        string s;
        getline(cin,s);
        State begin = s.begin();
        int ans = expression(begin);
        cout<<ans<<endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

string compressStr(string s) {
    if(s.size() < 2) return s;
    string str;
    int i = 0;
    while(i < s.size()) {
        int start = i;
        str += s[start];
        int count = 0;
        while(start < s.size() && s[i] == s[start]) {
            start++;
            count++;
        }
        str += count + '0';
        i = start;
    }
    if(str.size() > s.size()) return s;
    return str;
}


int main() {
    vector<string> s = {"", "a", "aa", "aaa", "aabbbbbcd","hsgala", "ssssggjjssswbca", "ssssggjjssswbc"};
    clock_t t;
    t = clock();
    for(int i = 0; i < s.size(); i++) {
        string str = compressStr(s[i]);
        cout << str << endl;
    }
    t = clock() - t;
    cout << "Time is " << t << " ms." << endl;
    return 1;
}


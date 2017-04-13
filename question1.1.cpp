#include <iostream>
#include <string>
#include <ctime>

using namespace std;
/*
bool isUnique(string s) {
    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(i != j && s[i] == s[j]) return false;
        }
    }
    return true;
}
*/

bool isUnique(string s) {
    int count[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        count[s[i]-'0']++;
        if(count[s[i]-'0'] > 1) return false;
    }
    return true;
}


int main() {
    string input = "abcdefaghi";
    clock_t t;
    t = clock();
    bool index = isUnique(input);
    if(index == true) cout << "True" << endl;
    else cout << "False" << endl;
    t = clock() - t;
    cout << "Time is " << t << " ms." << endl;
    return 1;
}


#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void reverseStr(string &s) {
    int n = s.size();
    for(int i = 0; i < n/2; i++) {
        swap(s[i], s[n-i-1]);
    }
    return;
}


int main() {
    string s = "abcdefaghi";
    clock_t t;
    t = clock();
    reverseStr(s);
    cout << s << endl;
    t = clock() - t;
    cout << "Time is " << t << " ms." << endl;
    return 1;
}


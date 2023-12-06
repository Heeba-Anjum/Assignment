
#include<bits/stdc++.h>
using namespace std;


int lengthOfLastWord(const string& s) {
    int length = 0;
    int i = s.length() - 1;


    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    string a;


    cout << "Enter a string: ";
    getline(cin, a);

  
    int result = lengthOfLastWord(a);
    cout  << result << endl;

    return 0;
}

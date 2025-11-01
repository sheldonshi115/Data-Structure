#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeNext(const string &pattern) {
    int m = pattern.length();        //Length of pattern
    vector<int> next(m, 0);          //Next[0] is always 0
    int j = 0;  //Length of previous longest prefix suffix
    for (int i = 1; i < m; i++) {    //Next[0] is always 0
        while (j > 0 && pattern[i] != pattern[j]) {  //Mismatched
            j = next[j - 1];         //Fall back
        }
        if (pattern[i] == pattern[j]) {  //Matched
            j++;                        //Advance
        }
        next[i] = j;              //Set Next[i]
    }
    for(int i = 0; i < m; i++){
        cout << next[i] << " ";
    }
    cout << endl;
    return next;                  //Return Next array
}

void KMPSearch(const string &text, const string &pattern) {
    int n = text.length();         //Length of text
    int m = pattern.length();      //Length of pattern
    vector<int> next = computeNext(pattern); //Compute Next array
    int j = 0;  //Index for pattern[]
    for (int i = 0; i < n; i++) {  //Scan text from left to right
        while (j > 0 && text[i] != pattern[j]) { //Mismatched
            j = next[j - 1];         //Fall back
        }
        if (text[i] == pattern[j]) {  //Matched
            j++;                        //Advance
        }
        if (j == m) {                 //Found pattern at index (i - m + 1)
            std::cout << "Pattern found at index " << (i - m + 1) << std::endl;
            j = next[j - 1];          //Look for next match
        }
    }
}


int main() {
    string text = "ababcabcacbab";  //test string
    string pattern = "abcac";         //test pattern
    KMPSearch(text, pattern);
    return 0;
}
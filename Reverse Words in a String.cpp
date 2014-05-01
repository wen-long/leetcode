//============================================================================
// Reverse Words in a String
// Given an input string, reverse the string word by word.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//
// click to show clarification.
//
// Clarification:
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing 
// spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.
//============================================================================

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "sstream"
#include "iterator"
using namespace std;

class Solution {
public:
    void reverseWords(string & s) {
        reverseWords2(s);
    }

    void reverseWords1(string &s) {
        int i = 0;
        string re;
        while (i != s.length()) {
            while (i != s.length() && s[i] == ' ') {
                ++i;
            }
            string temp;
            while (i != s.length() && s[i] != ' ') {
                temp += s[i];
                ++i;
            }
            if (temp.length() && re.length()) {
                re = temp + " " + re;
            } else if(temp.length()){
                re = temp;
            }
        }
        s = re;
    }

    void reverseWords2(string &s) {
        istringstream iss(s);
        ostringstream oss;
        vector<string> vs;
        string temp;
        while(iss >> temp) vs.push_back(temp);
        reverse(begin(vs), end(vs));
        ostream_iterator<string> out_it (oss," ");
        copy (vs.begin(), vs.end() -1, out_it);
        oss << *(vs.end() -1);
        
        // for (int i = 0; i < vs.size(); i++) {
        //     if (i != 0) oss << " ";
        //     oss << vs[i];
        // }
        s = oss.str();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "a b c  ";
    s.reverseWords(str);
    cout << "|" << str << "|";
    return 0;
}
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        map<char, char> charMap {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (int i = 0; i < s.size(); i++) {
            auto itr = charMap.find(s[i]);
            if (itr != charMap.end()) {
               if (charStack.empty() || charStack.top() != itr->second) {
                    return false;
                } else {
                    charStack.pop();
                }
            } else {
                charStack.push(s[i]);   
            }
        }
        if (!charStack.empty()) {
            return false;
        }
        return true;
    }
};
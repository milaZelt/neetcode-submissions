#include <iostream>
#include <string>
#include <unordered_set>
using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> seen;
        int answer=0;
        int left=0; 

        for(int right=0; right<s.length(); right++){
            while (seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            answer= max(answer, right-left+1);
        }
        return answer;
    }
};

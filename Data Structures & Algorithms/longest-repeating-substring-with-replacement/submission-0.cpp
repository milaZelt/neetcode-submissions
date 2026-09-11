#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer=0; //longerst
        int left=0; 
        int maxFrequancy=0; 

        vector<int> count(26, 0);

        for(int right=0; right<s.length(); right++){
            count[s[right]-'A']++;
            maxFrequancy= max(maxFrequancy, count[s[right] - 'A']);

            while( (right-left+1-maxFrequancy) >k){
                count[s[left]-'A']--;
                left++;
            }
          answer=max(answer,right-left+1);
        }
        return answer;
    }
};

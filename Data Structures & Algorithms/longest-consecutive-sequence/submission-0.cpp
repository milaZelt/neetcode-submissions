#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set <int> exist (nums.begin(), nums.end() );

        int longest=0; 

        for (int num:exist){

            if(!exist.count(num-1)){
                int length=1;
                int current=num;

                while(exist.count(current+1)){
                length++;
                current++;
            }
            longest=max(longest, length);
            }

        }
        return longest;
    }
};

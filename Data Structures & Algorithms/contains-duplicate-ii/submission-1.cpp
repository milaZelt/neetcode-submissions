#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0;
        unordered_set <int> window;

        for(int right=0; right<nums.size(); right++){
            if(abs(right - left)> k){
                window.erase( nums[left] );
                left++;
            }

            if(abs(right - left) <= k){
                if(window.count(nums[right])){
                    return true;
                }   
            }

            window.insert( nums[right] );
        }
        return false;
        
    }
};
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check;

        for (int i=0; i<nums.size(); i++){
            cout<< "num: " << nums[i] <<" check: " <<check.contains(nums[i])<<endl;
            if(check.contains(nums[i])){
                return true;
            }else{
                check.insert(nums[i]);
            }
        }
        return false;
    }
};
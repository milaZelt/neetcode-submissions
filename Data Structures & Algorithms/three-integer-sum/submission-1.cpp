#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector< vector<int> > answer;

        // Two pointers requires sorted array
        sort(nums.begin(), nums.end());

        for(int i=0;i< nums.size()-2; i++){
            
            // Skip duplicate first numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target= -nums[i];
            int left=i+1;
            int right=nums.size()-1;

            while(left<right ){
                int sum= nums[left]+nums[right];
                
                if(sum==target){
                    answer.push_back({nums[i],nums[left],nums[right]});
                    right--;
                    left++;

                    //need to skip duplicates;

                    //check left duplicates since its sorted, we check next to it;
                    while( (left< right) && (nums[left]==nums[left-1]) ){
                        left++;
                    }

                    //check right duplicates since its sorted;
                    while( (left< right) && (nums[right]==nums[right+1]) ){
                        right--;
                    }

                } else if (sum<target){
                    left++;
                } else{
                  right--;
                }
            }  
        } 
        return answer;
    }
};
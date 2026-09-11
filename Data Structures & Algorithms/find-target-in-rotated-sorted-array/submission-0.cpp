#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            int mid= left+(right-left)/2;

            if(nums[mid]==target){
                return mid;
            }
            //is left half is sorted
            if(nums[left]<=nums[mid]){
                //is target inside?
                if(nums[left]<=target && target<nums[mid]){
                    right=mid-1;
                }else{
                    left = mid + 1;
                }
            }else{
                // target is inside the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
        
    }
};

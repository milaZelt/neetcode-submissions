#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0; 

        for(int num: nums){
            if(num!=val){
                nums[k]=num;
                k++;
            }
        }
        return k;
        
    }
};
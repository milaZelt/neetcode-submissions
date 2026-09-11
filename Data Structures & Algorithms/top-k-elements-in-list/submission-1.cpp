#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        
        //we get frequancy of each number which is <key(number), freq>
        for(const int& n: nums){
            freq[n]++;
        }

        // here we just reverse that to be frequnacy first than key 
        vector <vector <int> > freqReversed(nums.size()+1);
        for(const auto& p: freq){
           freqReversed[p.second].push_back(p.first);
        }
        
        vector<int> result;
        for (int i=freqReversed.size()-1; i>0; i--){
            for (int n: freqReversed[i]){
                result.push_back(n);
                if (result.size()==k){
                    return result;
                }
            }

        }
        return result;
    }
};

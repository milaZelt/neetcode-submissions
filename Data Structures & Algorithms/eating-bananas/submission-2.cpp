#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    //helper function
    bool canEat(vector<int>& piles, int mid, int h){
        double sum=0;
        for(int i=0; i<piles.size(); i++){
            sum += ceil((double)piles[i] / mid);
        }
        if (sum<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right= *std::max_element(piles.begin(), piles.end());
        int answer=right; 

        while(left<=right){
            int mid= left+ (right-left)/2;  //k speed
            if(canEat(piles,mid, h) ){
                answer=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return answer; 
    }
};

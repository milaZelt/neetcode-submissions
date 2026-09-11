#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right=heights.size()-1; 
        int left=0;

        int answer=0;

        while(left<right){
            int width=right-left;
            int height= min(heights[left], heights[right]);
            int area= width*height;

            if(area>answer){
                answer=area;
            }

            if(heights[left]< heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return answer;
        
    }
};

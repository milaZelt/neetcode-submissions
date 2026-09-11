#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();

        vector <int> left(n);
        vector <int> right(n);

        left[0]=1;
        for(int i=1; i<n; i++){
            left[i]=left[i-1]*nums[i-1]; //Left product
        }

        right[n-1]=1;
        for(int i=n-2; 0<=i; i--){
            right[i]=right[i+1]*nums[i+1]; //Right product
        }
        // for (int x : left) {
        //     cout << x << " ";
        //     }
        // cout << endl;

        // for (int y : right) {
        //     cout << y << " ";
        //     }
        // cout << endl;

        for(int i=0; i<n; i++){
            left[i]*=right[i];
        }
        // for (int x : left) {
        //     cout << x << " ";
        //     }
        // cout << endl;

        return left;
    }
};

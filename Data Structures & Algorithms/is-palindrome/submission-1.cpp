#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //loop trought, add to a string all alphemtic charcters
        string answer="";
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            if( isalnum(c) ){
                answer+=tolower(c);
            }
        }

        //left and righ pointer
        int left=0;
        int right=answer.length()-1;

        while(left<right){
            if(answer[left]!=answer[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

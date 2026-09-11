#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> letter;
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        if (s.length()%2 != 0){return false;}

        for(char c:s ){
           if(c=='(' || c=='[' || c=='{'){
            letter.push(c);
           }
           else{
            if (letter.empty()) return false;
            char top= letter.top();
            letter.pop();
            if (top!=matching[c]){
                return false;
            }
           
           }
        }
        return letter.empty();
    }
};

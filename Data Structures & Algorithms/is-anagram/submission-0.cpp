#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false; 
        }
        unordered_multiset <char> chars;
        for(int i=0; i<s.length();i++){
            chars.insert(s[i]);
        }

        for(int j=0; j<t.length(); j++){
            auto it=chars.find( t[j] );
            if (it!=chars.end()){
                chars.erase(it); 
            }else{
                return false;
            }
        }
        return true;
    }
};

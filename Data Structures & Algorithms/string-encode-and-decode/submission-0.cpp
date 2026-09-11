#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string addApp="";

        for (const auto& word : strs){
            addApp+= to_string(word.length());
            addApp+= '#';
            addApp+= word;
        }
        return addApp; 
    }

    vector<string> decode(string s) {
        vector <string> result; 

        int i=0;
        while ( i<s.length() ) {
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length= stoi(s.substr(i, j-i)); //get number 
            string word= s.substr(j+1,length);

            result.push_back(word);

            i= j+length+1;
        }
        return result; 

    }
};

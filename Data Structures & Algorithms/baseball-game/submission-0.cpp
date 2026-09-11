#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> scores;
        
        for(int i=0; i<operations.size(); i++){
            if (operations[i]=="+"){
                int top1=scores.top();
                scores.pop();
                int top2=scores.top();
                scores.push(top1);
                scores.push(top1+top2);

            } else if (operations[i]=="D"){
                int top=scores.top();
                scores.push(2*top);
                
            }else if (operations[i]=="C"){
                scores.pop();
                
            }else{
                int num=stoi(operations[i]);
                scores.push(num);
            }
        }

        int total=0;
        int n=scores.size();
        for(int i=0; i<n; i++){
            total+=scores.top();
            scores.pop();
        }
        return total;
    }
};
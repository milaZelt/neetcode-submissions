#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        // edge case
        if (t.size() > s.size()) {
            return "";
        }

        vector<int> freqT(128, 0);
        vector<int> window(128, 0);

        int needed = 0; // number of different characters we need
        int have = 0;   // number of requirements currently satisfied

        // Count characters in t
        for (char c : t) {
            if (freqT[c] == 0) {
                needed++;
            }

            freqT[c]++;
        }

        int left = 0;

        int minLength = INT_MAX;
        int answerStart = 0;

        for (int right = 0; right < s.size(); right++) {

            // add s[right] into current window
            char c = s[right];
            window[c]++;

            // check if we JUST satisfied this character requirement
            if (freqT[c] > 0 && window[c] == freqT[c]) {
                have++;
            }

            // window contains everything from t
            while (have == needed) {

                // check if this is the smallest window
                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    answerStart = left;
                }

                // remove s[left] from the window
                char remove = s[left];
                window[remove]--;

                // check if removing it made window invalid
                if (freqT[remove] > 0 &&
                    window[remove] < freqT[remove]) {

                    have--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(answerStart, minLength);
    }
};


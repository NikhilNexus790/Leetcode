
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // Include the current character
            freq[s[right]]++;

            // Maximum frequency of a character seen so far
            maxFreq = max(maxFreq, freq[s[right]]);

            // Check if replacements required exceed k
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

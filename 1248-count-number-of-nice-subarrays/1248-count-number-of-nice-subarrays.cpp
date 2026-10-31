
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {

            // Count odd numbers
            if (num % 2 != 0) {
                sum++;
            }

            // Check for previous prefix sum
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};

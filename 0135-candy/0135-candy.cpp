
class Solution {
public:
    int candy(vector<int>& ratings) {

        // Get number of children
        int n = ratings.size();

        // Initially give 1 candy to each child
        int candies = n;

        // Start from second child
        int i = 1;

        while (i < n) {

            // Skip equal ratings, no need to change candy count
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            // Initialize increasing slope counter
            int peak = 0;

            // Traverse strictly increasing ratings
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            // Initialize decreasing slope counter
            int valley = 0;

            // Traverse strictly decreasing ratings
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }

            // Remove extra candy given to peak (overlap of increasing and decreasing)
            candies -= min(peak, valley);
        }

        // Return total minimum candies required
        return candies;
    }
};


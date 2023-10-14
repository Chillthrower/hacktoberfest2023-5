#include <iostream>
#include <vector>

// Finding the Longest Consecutive Ones in a program using sliding window method Eg: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int max_count = 0;
        int start = 0;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[start] == 0) {
                    zeroCount--;
                }
                start++;
            }

            int window = i - start + 1;
            max_count = std::max(max_count, window);
        }    

        return max_count;    
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int longestOnesCount = solution.longestOnes(nums, k);

    std::cout << "Longest sequence of 1's with at most " << k << " flips: " << longestOnesCount << std::endl;

    return 0;
}

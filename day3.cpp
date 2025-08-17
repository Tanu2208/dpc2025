#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Detect cycle using Floyd’s Tortoise and Hare
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Step 2: Find the entrance to the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(test1) << endl; // 2

    vector<int> test2 = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(test2) << endl; // 3

    vector<int> test3 = {1, 1};
    cout << sol.findDuplicate(test3) << endl; // 1

    vector<int> test4 = {1, 4, 4, 2, 3};
    cout << sol.findDuplicate(test4) << endl; // 4

    // Large test case
    vector<int> test5;
    for (int i = 1; i <= 99999; i++) test5.push_back(i);
    test5.push_back(50000);

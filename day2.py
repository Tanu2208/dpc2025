class Solution:
    def missingNumber(self, arr):
        n = len(arr) + 1  # since one number is missing
        total_sum = n * (n + 1) // 2
        actual_sum = sum(arr)
        return total_sum - actual_sum

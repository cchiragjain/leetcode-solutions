class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def calculate_sum(x: int, length: int) -> int:
            if x > length:
                # decreasing from x-1 to x-length
                return length * x - (length * (length + 1)) // 2
            else:
                # decreasing from x-1 to 1, then fill rest with 1s
                return (x * (x - 1)) // 2 + (length - (x - 1))

        left, right = 1, maxSum
        result = 1

        while left <= right:
            mid = (left + right) // 2
            total = mid + calculate_sum(mid, index) + calculate_sum(mid, n - index - 1)

            if total <= maxSum:
                result = mid
                left = mid + 1  # try higher
            else:
                right = mid - 1  # too much, try lower

        return result

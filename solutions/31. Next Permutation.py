class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        if(i < 1):
            return nums
        while(i >= 1):
            if(nums[i-1] < nums[i]):
                break
            i -= 1
        if(i != 0):
            j = len(nums) - 1
            while j >= i and nums[j] <= nums[i-1]:
                j -= 1
            nums[i-1], nums[j] = nums[j], nums[i-1]
        j = 0
        while(i + j < len(nums) - 1 - j):
            nums[i + j], nums[len(nums) - 1 - j] = nums[len(nums) - 1 - j], nums[i + j]
            j += 1
        
        
        

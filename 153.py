class Solution:
    def findMin(self, nums: list[int]) -> int:
        ans = nums[0]
        l = 0
        r = len(nums) - 1


        while(l <= r):
            

            if(nums[l] < nums[r]):
                ans = min(ans,nums[l])
                break

            mid = l + (r - l) // 2

            ans = min(ans,nums[mid])
            if nums[mid] >= nums[l]:
                l = mid + 1
            else:
                r = mid - 1


        

        return  ans




test = [2,1]

t = Solution()

ans = t.findMin(test)


print(ans)
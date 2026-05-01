
class Solution:
    def characterReplacement(self,s :str, k : int)-> int :
        
        ans = 0

        l = 0
        r = 0
        h = {}
        maxF = 0

        for r in range(len(s)):

            h[s[r]] = 1 + h.get(s[r] , 0)
            maxF = max(maxF, h[s[r]])

            while (r - l + 1) - maxF > k:
                h[s[l]] -= 1
                l += 1  
            ans = max(ans, r - l + 1)
            
        return ans







s  = Solution()


testcase = "abab"

ans = s.characterReplacement(testcase, 2)

print(ans)

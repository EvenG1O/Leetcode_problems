

class  Solution:
    def lengthOfLongestSubstring(self, s :str) -> int:
        
        l = 0
        r = 0
        ans = 0
        hm = {}
        
        for r in range(0,len(s)):
            hm[s[r]] = hm.get(s[r] , 0) + 1
            

            while hm[s[r]] > 1:
                hm[s[l]] -= 1
                l += 1
                
            ans = max(ans, r - l + 1)
                
                
            
        
        return ans
                
                
            
                
                
            
            
            
        
s = Solution()

ans = s.lengthOfLongestSubstring("abcabcbb")

print(ans)
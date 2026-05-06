


class Solution:
    
     
    def checkInclusion(self, s1 : str, s2 : str) -> bool:
        hs : dict[str,int] = {}
        current : dict[str,int] = {}
        
        if len(s1) > len(s2) : return False
        
        for char in s1:
            
            hs[char] = hs.get(char,0) + 1
        
        l = 0
        
        for r, char in enumerate(s2):
            
            current[char]  = current.get(char,0) + 1
            
            if (r - l + 1) > len(s1):
                charL = s2[l]
                current[charL] -= 1
                if current[charL] == 0:
                    del current[charL]
                
                l += 1
                
            if hs == current : return True
            
        return False
                
                
            


s = Solution()


s1 = "ab"
s2 = "eidbaooo"

ans = s.checkInclusion(s1,s2)

if(ans == True):
    print("working")

   
        
            
        
        
        
        

        
            
        
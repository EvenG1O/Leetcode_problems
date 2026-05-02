import heapq
import heapq

from typing import List


class MinStack:
    def __init__(self):
        self.sta = []
        self.staMinVal = []
        
    def push(self, val : int)-> None:
        self.sta.append(val)
        
        if not self.staMinVal:
            self.staMinVal.append(val)
        else:
            self.staMinVal.append(min(self.staMinVal[-1] , val))
            
    def pop(self) -> None:
        self.staMinVal.pop(-1)
        self.sta.pop(-1)
        
    
    
    def top(self) -> int:
        return self.sta[-1]
    
    def getMin(self) -> int:
        return self.staMinVal[-1]
    
    
    


MinS = MinStack()

MinS.push(-2)
MinS.push(0)
MinS.push(-3)
print(MinS.getMin()) # return -3
MinS.pop()
print(MinS.top())    # return 0
print(MinS.getMin()) # return -2

        
        
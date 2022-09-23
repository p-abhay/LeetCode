class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ""
        for i in range(1,n+1):
            s += bin(i).replace("0b","")
        #print(s)
            
        ans = 0
        ans = int(s,2) % (10**9+7)
        return ans
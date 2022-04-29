class Solution:
    def isHappy(self, n: int) -> bool:
        s = set();
        while n != 1:
            new_n = 0
            while n:
                rem = n % 10
                new_n += rem * rem
                n //= 10
            n = new_n
            print(new_n)
            if new_n in s:
                return False
            s.add(new_n)
        return True
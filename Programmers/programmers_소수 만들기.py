import math
def isPrime(num):
    for i in range(2,int(math.sqrt(num)+1)):
        if num%i == 0 :
            return False
    return True

def solution(nums):
    answer = 0
    for first in range(0,len(nums)):
        for second in range(first+1,len(nums)):
            for third in range(second+1,len(nums)):
                if isPrime(nums[first] + nums[second] + nums[third]) :
                    answer+=1
    return answer

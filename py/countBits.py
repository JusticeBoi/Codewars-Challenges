def findMaxBit(n):
    i = 0
    while(pow(2,i) <= n):
        i += 1
    print("max bit : ",i-1)
    return  i -1


def countBits(n):
    max = findMaxBit(n)
    bits_with_1 = 0
    while( max >= 0 and n >= 0 ):
        if(n / pow(2,max) >= 1  ):
            bits_with_1 = bits_with_1 +  1
            n = n - pow(2,max)
        max = max -1
    return bits_with_1
         
        
    



n = 18
n >>=1
n >>=1
print(n)


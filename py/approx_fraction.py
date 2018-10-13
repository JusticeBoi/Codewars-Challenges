import math
def approx_fraction(float_, rel_error):
    is_negative = False
    if(float_ < 0):
        is_negative = True
        float_ = - float_
    print(float_ % 1)
    if(float_ % 1 == 0 ):
        return "There is no need to have a fraction for {:d}".format(int(float_))
    if( abs(math.ceil(float_)) == abs(math.floor(float_ + 1e-10 ))):
        return "There is no need to have a fraction for {:d}".format(math.ceil(float_))
    if( abs(math.floor(float_)) == abs(math.ceil(float_ - 1e-10 ))):
        return "There is no need to have a fraction for {:d}".format(math.floor(float_))
    num = 1
    denum = 1
    number_of_steps = 0
    
    while(abs(float_ - (num/denum)) >= abs(rel_error * 0.01 * float_)  ):
        if(abs(float_) > abs(num/denum)):
            number_of_steps += 1
            num += 1
        elif (abs(float_) < abs(num/denum)):
            number_of_steps += 1
            denum += 1
    if(is_negative):
        num = - num
    return ['{}/{}'.format(num,denum), number_of_steps]



# float_ = cos(pi*130/180.0)      
# float_ = sqrt(361)c
# degrees = 45
# float_ = tan(pi*degrees/180) # (= 0.9999999999999999)
float_ = -0.0001
print(float_)
print(1e-5)

print(approx_fraction(float_,0.1))


##best solution
# from itertools import count
# import math
# 
# 
# def approx_fraction(target, rel_error):
#     
#     if abs(target-round(target)) < 1e-10:
#         return f"There is no need to have a fraction for {round(target)}"
#     
#     n, d, isNeg   = 1,1, target < 0
#     target, limit = abs(target), rel_error/100 * abs(target)
#     
#     for rnd in count(0):
#         if abs(target-n/d) < limit: return [f'{"-"*isNeg}{n}/{d}', rnd]
#         elif n/d > target:          d += 1
#         else:                       n += 1

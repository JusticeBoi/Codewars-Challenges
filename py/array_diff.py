def array_diff(a, b):
    print(a,b)
    if (len(a) == 0):
        return []
    if (len(b)==0):
        return a
    for it_b in range(len(b)):
        for it_a in range(len(a)):
            if (a[it_a] == b[it_b]):
                a[it_a] = ''

    a = [i  for i in a if i != '']  
#     print(a)         
    return a
print(array_diff([9, 2, -19, -4, -4, -5, -4, 14, 19, 0, -19, 20, 2, -2],[4, -8, -2, 15, 9, 0, -3, 4, 4]))


##best solution
# def array_diff(a, b):
#     return [x for x in a if x not in b]
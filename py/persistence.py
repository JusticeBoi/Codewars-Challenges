def persistance(a_num):
    assert(isinstance(a_num,int))
    if (a_num < 10):
        return 0
    

    str_rep = str(a_num)
    n_of_digits = len(str_rep)

    multip = 1
    counter = 0

    while True :
        for digit in range(n_of_digits):
            multip = multip * int(str_rep[digit])
        counter=counter+1
        if(multip < 10):
            return counter
        str_rep = str(multip)
        n_of_digits = len(str_rep) 
        multip = 1
        if(counter > 100):
            print("took too long")
            break        

    return 0



num = 39

print(persistance(num)) 

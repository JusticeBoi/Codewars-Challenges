

def find_missing(sequence):
    assert(isinstance(sequence,list))

    size = len(sequence)
    increase = (sequence[-1]-sequence[0])/size
    expected_sum = 0
    
    for i in range(size+1):
        expected_sum = expected_sum +(i*increase + sequence[0])
    
    real_sum = sum(sequence)


    return expected_sum - real_sum



a_list = [3,6,12]


print(find_missing(a_list))
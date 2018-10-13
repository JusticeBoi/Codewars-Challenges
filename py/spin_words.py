def spin_words(sentence):
    split_list = sentence.split()
    if(len(split_list) == 1 and len(split_list[0]) >= 5):
        return split_list[0][::-1]
    
    reversed_sentence = split_list[0] if len(split_list[0]) < 5 else split_list[0][::-1]

    for word in sentence.split()[1:]:
        if(len(word) >= 5):
            reversed_sentence += ' ' + word[::-1]
        else:
            reversed_sentence += ' ' + word
    return reversed_sentence




print(spin_words("Welcome"))

##best solution

# def spin_words(sentence):
#     # Your code goes here
#     return " ".join([x[::-1] if len(x) >= 5 else x for x in sentence.split(" ")])
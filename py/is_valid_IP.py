def is_valid_IP(strng):
    
    
    ip_list = strng.split('.')
    print(ip_list)
    if(len(ip_list) != 4):
        return False
    for word in ip_list:
        for char in word:
            if (char.isalpha()):
                return False
            if(char == ' '):
                return False
        if (len(word) > 1 and word[0] == '0'):
            return False
        
        if( int(word) > 255 or int(word) < 0):
            return False
        
    
    return True


# is_valid_IP("1.2.3.4")





print(is_valid_IP("12.34.56 .1"))




def to_camel_case(text):
    while(text.find("_") != -1 or text.find("-") != -1 ):
        pos_ = text.find("_")
        if(pos_ != -1):
            if(not text[pos_+1].isupper()):
                text = text[:pos_] +text[pos_+1].upper()+ text[(pos_+2):]
            else:
                text = text[:pos_] +text[(pos_+1):]
        pos = text.find("-")
        if(pos != -1):
            if(not text[pos+1].isupper()):
                text = text[:pos] + text[pos+1].upper()+ text[(pos+2):]
            else:
                text = text[:pos] +text[(pos+1):]
    
    return text
        
    
    
    
    


print(to_camel_case("the_stealth_warrior"))



# lis = list(s)
# print(lis)
# 
# for i in range(len(lis)):
#     print(isinstance(i, str))
#     if(lis[i] == "_" or lis[i] == "-"):
#         lis[i] =""
#         if(not lis[i+1].isupper()):
#              lis[i+1].upper()
#         
# print(lis)
# print(s[0].isupper())
# x="Alpha_beta_Gamma"
# 
# print(x.split('_'))

# print(s.find("_"))
# 


        
        
    
            
        
    
      
# print(s)
     
    
    
    




    
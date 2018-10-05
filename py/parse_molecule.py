


def parse_molecule (formula):
    ans_dict = {}
    for i in [0,len(formula)]:
        if(i+1 != len(formula) and formula[i].isupper() and formula[i+1].islower()):
            ans_dict[formula[i]+ formula[i+1]]=  1
        
    return ans_dict

def minimum(a_list):#
    min = 999
    for i in a_list:
        if (i < min and i != -1):
            min = i
    return min
        
        
    
def firstBracketIs(formula):
    return minimum([formula.find('('),formula.find('['),formula.find('{')])

def getOutsideParanthesis(formula):
    inside_parant = []
    index_open = 0
    index_close = 0
    cont = True;
    while(cont):
        if(formula.find('[')!=-1 and formula[firstBracketIs(formula)] == '[' ):
            index = formula.find('[')
            index_close = formula.find(']')
            i = 1
            while(index_close+i < len(formula) and formula[index_close+i].isdigit()):
                print('in')
                index_close+=1
            inside_parant.append(formula[index:index_close+1])
            formula=formula[:index] + formula[index_close+1:]
        elif(formula.find('{')!=-1 and formula[firstBracketIs(formula)] == '{' ):
            index = formula.find('{')
            index_close = formula.find('}')
            i = 1
            while(index_close+i < len(formula) and formula[index_close+i].isdigit()):
                index_close+=1
            inside_parant.append(formula[index:index_close+1])
            formula=formula[:index] + formula[index_close+1:]
        elif(formula.find('(')!=-1 and formula[firstBracketIs(formula)] == '('):
            index = formula.find('(')
            index_close = formula.find(')')
            i = 1
            while(index_close+i < len(formula) and formula[index_close+i].isdigit()):
                index_close+=1
            inside_parant.append(formula[index:index_close+1])
            formula=formula[:index] + formula[index_close+1:]
        if(formula.find('{') == -1 and formula.find('[')==-1 and formula.find('(')==-1 ):
            cont = False
#     print(inside_parant)
    return [formula,inside_parant]
            
che = 'K4[ON(SO3)2]23'
print(che[1:])
a = getOutsideParanthesis(che)[1]
print(a[0])
print(a[0][firstBracketIs(a[0][1:])+1])
            
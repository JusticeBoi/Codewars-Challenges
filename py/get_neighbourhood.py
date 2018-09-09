

  
def get_neighbourhood(n_type, mat, coordinates):
    assert(isinstance(n_type, str) and isinstance(mat, list) and isinstance(coordinates, tuple) )
    ans = [] 
    x = coordinates[0]
    y = coordinates[1]
    z = mat[x][y]
    if(n_type == "moore"):
        if ( x-1 >= 0 and y-1 >= 0 ):
            ans.append(mat[x-1][y-1])
            
        if ( x-1 >= 0 ):
            ans.append(mat[x-1][y])
            
        if ( x-1 >= 0 and y+1 <= len(mat)):
            ans.append(mat[x-1][y+1])
            
        if ( y-1 >= 0 ):
            ans.append(mat[x][y-1])
            
        if ( y+1 <= len(mat) ):
            ans.append(mat[x][y+1])
            
        if ( x+1 <= len(mat[0]) and y-1 >= 0 ):
            ans.append(mat[x+1][y-1])
            
        if ( x+1 <= len(mat[0])):
            ans.append(mat[x+1][y])
            
        if ( x+1 <= len(mat[0]) and y+1 <= len(mat)):
            ans.append(mat[x+1][y+1])
        return ans
    
    elif (n_type=="von_neumann"):
        
        if ( x-1 >= 0 ):
            ans.append(mat[x-1][y])
            
        if (  y-1 >= 0 ):
            ans.append(mat[x][y-1])
            
        if ( y+1 <= len(mat) ):
            ans.append(mat[x][y+1])
            
        if ( x+1 <= len(mat[0])):
            ans.append(mat[x+1][y])
        return ans
            
    
    pass

N = 5
M = 5
mat = [[j+i*N for j in range (N)] for i in range(M)]

# for line in mat:
#     print(line)
indexes1=(1,1)
indexes2=(0,0)
expected_moore_1=[1,0,2,5,7,10,11,12] 
moore = "moore"
von_neumann = "von_neumann"


print(get_neighbourhood(moore,mat,indexes1))
print(get_neighbourhood(moore,mat,indexes2))

print(get_neighbourhood(von_neumann,mat,indexes1))
print(get_neighbourhood(von_neumann,mat,indexes2))

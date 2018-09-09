def race(v1, v2, g):
    if(v1 < 0 or v2 < 0 or v1 > v2):
        return None
    dif = v2 - v1 
    time_in_h = g / dif
    
    time_in_sec = time_in_h * 3600
    
    hour = int( time_in_sec / 3600)
    
    min = int ((time_in_sec - (3600 * hour) ) / 60)
    
    sec = time_in_sec -(3600 * hour) -(60 * min)
    
    
    return [int(hour),int(min),int(sec)]




    

print(race(0,-44,-39))
    

def sqInRect(lng, wdth):
    if wdth == lng:
        return None
    ans_list = []
    while wdth != 1 or lng != 1:
        if lng > wdth:
            ans_list.append(wdth)
            lng -= wdth
        elif wdth > lng:
            ans_list.append(lng)
            wdth -= lng
        elif wdth == lng:
            ans_list.append(lng)
            break
    if wdth == 1:
        ans_list += [1] * lng
    elif lng == 1:
        ans_list += [1] * wdth
    return ans_list



print(sqInRect(610, 78))

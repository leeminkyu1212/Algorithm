def one_correct(idx,n):
    sub_list=[1,2,3,4,5]
    return sub_list[idx%5]==n

def two_correct(idx,n):
    sub_list=[2,1,2,3,2,4,2,5]    
    return sub_list[idx%8]==n

def three_correct(idx,n):    
    sub_list=[3,3,1,1,2,2,4,4,5,5]
    return sub_list[idx%10]==n

def solution(answers):
    supoza=[0,0,0]
    for idx,n in enumerate(answers):
        if one_correct(idx,n)==True:
            supoza[0]+=1
        if two_correct(idx,n)==True:
            supoza[1]+=1
        if three_correct(idx,n)==True:
            supoza[2]+=1
    max_count=max(supoza)
    answer=[]
    for idx,i in enumerate(supoza):
        if max_count==i:
            answer.append(idx+1)            
    
    return answer
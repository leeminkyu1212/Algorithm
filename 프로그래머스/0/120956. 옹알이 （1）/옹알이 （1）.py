

def solution(babbling):
    
    words=['aya','ye','woo','ma']
    new_words=[]
    def func(string):
        nonlocal new_words
        if len(string)>0:
            new_words.append(string)
        
        if len(string)>15:
            return
        for word in words:
            new_string=string+word
            func(new_string)
    
    func('')
    answer = 0
    
    for bab in babbling:
        if bab in new_words:
            answer+=1
                    
    return answer
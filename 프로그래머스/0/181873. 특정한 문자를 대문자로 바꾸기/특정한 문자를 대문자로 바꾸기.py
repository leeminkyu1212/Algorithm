def solution(my_string, alp):

    my_string=my_string.replace(alp,chr(ord(alp)-ord('a')+ord('A')))
            
    return my_string
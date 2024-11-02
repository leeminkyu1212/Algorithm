def solution(bandage, health, attacks):
    max_health=health
    attack_dict={x[0]:x[1] for x in attacks}
    
    continue_success=0
    print(0,health,continue_success)
    for i in range(1,attacks[-1][0]+1):

        
        if i in attack_dict:
            health-=attack_dict[i]
            continue_success=0
            print(i,health,continue_success)
            continue
        continue_success+=1
        if continue_success==bandage[0]:
            health+=bandage[2]
            continue_success=0
        health+=bandage[1]
        
        health=min(max_health,health)
        if health<=0:
            return -1
        print(i,health,continue_success)
        
    if(health<=0):
        return -1
    
    answer = health
    return answer
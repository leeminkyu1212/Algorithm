def solution(participant, completion):
    completion_dict=dict()
    
    participant_dict=dict()
    
    for part in participant:
        if part not in participant_dict:
            participant_dict[part]=1
        else:
            participant_dict[part]+=1
    
    for comp in completion:
        participant_dict[comp]-=1
    for key,value in participant_dict.items():
        if value !=0:
            print(key)
            return key
        
    

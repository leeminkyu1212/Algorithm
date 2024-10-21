
def solution(record):
    user={}
    histories=[]
    answer = []
    for string in record:
        action_list=list(string.split())
        if action_list[0]=="Enter":
            user[action_list[1]]=action_list[2]
            histories.append([action_list[0],action_list[1]])
        elif action_list[0]=="Change":
            user[action_list[1]]=action_list[2]
        elif action_list[0]=="Leave":
            histories.append([action_list[0],action_list[1]])
    for history in histories:
        if history[0]=="Enter":
            answer.append(f"{user[history[1]]}님이 들어왔습니다.")
        else:
            answer.append(f"{user[history[1]]}님이 나갔습니다.")
    
    return answer
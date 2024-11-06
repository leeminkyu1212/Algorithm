def solution(friends, gifts):
    friends_dict = {name: idx for idx, name in enumerate(friends)}
    num_friend = len(friends)
    
    friend_matrix = [[0] * num_friend for _ in range(num_friend)]
    
    for gift in gifts:
        gift_from, gift_to = gift.split()
        friend_matrix[friends_dict[gift_from]][friends_dict[gift_to]] += 1
    
    to_receive = {friend: 0 for friend in friends}
    
    gift_sent = [sum(friend_matrix[i]) for i in range(num_friend)]
    gift_received = [sum(friend_matrix[j][i] for j in range(num_friend)) for i in range(num_friend)]
    
    gift_index = {friends[i]: gift_sent[i] - gift_received[i] for i in range(num_friend)}
    
    for i in range(num_friend):
        for j in range(i + 1, num_friend):
            friend_a = friends[i]
            friend_b = friends[j]
            a_to_b = friend_matrix[i][j]
            b_to_a = friend_matrix[j][i]
        
            if a_to_b > b_to_a:
                to_receive[friend_a] += 1
            elif b_to_a > a_to_b:
                to_receive[friend_b] += 1
            else:
                if gift_index[friend_a] > gift_index[friend_b]:
                    to_receive[friend_a] += 1
                elif gift_index[friend_b] > gift_index[friend_a]:
                    to_receive[friend_b] += 1
    max_gifts = max(to_receive.values())
    return max_gifts

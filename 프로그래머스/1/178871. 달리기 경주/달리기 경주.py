def solution(players, callings):
    player_index = {name: idx for idx, name in enumerate(players)}

    for calling in callings:
        idx = player_index[calling]
        
        if idx > 0:
            front_player = players[idx - 1]
            
            players[idx - 1], players[idx] = players[idx], players[idx - 1]
            
            player_index[calling] -= 1
            player_index[front_player] += 1
    
    return players

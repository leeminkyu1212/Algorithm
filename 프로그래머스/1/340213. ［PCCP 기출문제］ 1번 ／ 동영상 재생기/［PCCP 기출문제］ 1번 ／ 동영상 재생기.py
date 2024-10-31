



def solution(video_len, pos, op_start, op_end, commands):
    def make_seconds(video_list):
        video_list=list(map(int,video_list.split(':')))
        return video_list[0]*60+video_list[1]

    video_len=make_seconds(video_len)
    pos=make_seconds(pos)
    op_start=make_seconds(op_start)
    op_end=make_seconds(op_end)
    
    def user_command(command,pos):
        if op_start<=pos<op_end:
            pos=op_end
        if command=='prev':
            pos-=10
            if pos<0:
                pos=0
        if command=='next':
            pos+=10
            if pos>video_len:
                pos=video_len
        if op_start<=pos<op_end:
            pos=op_end
        return pos
    for command in commands:
        pos=user_command(command,pos)
    
    
    
    
    
    answer = f'{pos//60:0>2}:{pos%60:0>2}'
    return answer
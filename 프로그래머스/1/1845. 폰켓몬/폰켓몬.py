def solution(nums):
    pocket_dict=dict()
    n=len(nums)
    for num in nums:
        if num in pocket_dict:
            pocket_dict[num]+=1
        else:
            pocket_dict[num]=1
    
    if len(pocket_dict)>=(n//2):
        return n//2
    else:
        return len(pocket_dict)

        
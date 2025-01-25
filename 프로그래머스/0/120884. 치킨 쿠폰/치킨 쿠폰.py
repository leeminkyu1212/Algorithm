def solution(chicken):
    service_chicken = 0
    coupons = chicken
            
    while coupons >= 10:
        new_chicken = coupons // 10
        service_chicken += new_chicken
        coupons = coupons % 10 + new_chicken
                                
    return service_chicken
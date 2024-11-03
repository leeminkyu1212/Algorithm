def solution(h1, m1, s1, h2, m2, s2):
    def get_times(h, m, s):
        seconds = h * 60 * 60 + m * 60 + s

        second_angle = (s * 6) % 360
        minuate_angle = (m * 6 + s * 0.1) % 360
        hour_angle = (h * 30 + m * 0.5 + s * 0.5 / 60) % 360

        ret = (h * 60 + m) * 2 - h

        if second_angle >= minuate_angle:
            ret += 1
        if second_angle >= hour_angle:
            ret += 1

        if h >= 12:
            ret -= 2

        return ret

    ret = get_times(h2, m2, s2) - get_times(h1, m1, s1)

    if h1 in [0, 12] and m1 == 0 and s1 == 0:
        ret += 1

    return ret

def solution(s, n):
    def shift_char(c):
        if 'a' <= c <= 'z':
            return chr((ord(c) - ord('a') + n) % 26 + ord('a'))
        elif 'A' <= c <= 'Z':
            return chr((ord(c) - ord('A') + n) % 26 + ord('A'))
        else: 
            return c

    return ''.join(shift_char(c) for c in s)


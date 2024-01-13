# Longest Common Subarray

s = "SPANDANAYZ"

def longest_sub_string_with_distint_characters(s):
    if len(s) in [0, 1]: return len(s)
    
    visited_set = set()
    
    max_len = 0
    left, right = 0, 0
    
    # SPANDANA
    # left = 0, right = 0, max_len = 0, visited_set = {S} => max_len = 1, right = 1
    # left = 0, right = 1, max_len = 1, visited_set = {S, P} => max_len = 2, right = 2
    # left = 0, right = 2, max_len = 2, visited_set = {S, P, A} => max_len = 3, right = 3
    # left = 0, right = 3, max_len = 3, visited_set = {S, P, A, N} => max_len = 4, right = 4
    # left = 0, right = 4, max_len = 4, visited_set = {S, P, A, N, D} => max_len = 5, right = 5
    
    # left = 3, right = 5, max_len = 5, visited_set = {S, P, A, N, D, A}
    
    while (right<len(s)):
        
        if s[right] in visited_set:
            # move the left until we remove the char from the visited set
            while(s[right] in visited_set):
                visited_set.remove(s[left])
                left += 1
        
        visited_set.add(s[right])
           
        # calc the max length
        max_len = max(max_len, (right-left+1))
        right += 1
        print(f'visited_set: {visited_set} left: {left} right: {right} max_len: {max_len}')
    
    return max_len
    
print('Longest Sub-String with distinct characters : ', longest_sub_string_with_distint_characters(s))


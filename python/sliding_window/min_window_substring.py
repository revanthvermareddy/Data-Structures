"""
76: https://leetcode.com/problems/minimum-window-substring/

description:

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
"""


def min_window_substring(s: str, t: str):
    m = len(s)
    n = len(t)
    
    required = dict()
    
    # T.C: O(n)
    for ch in t:
        if ch not in required:
            required[ch] = 0
        required[ch] += 1
    
    l = 0
    r = 0
    
    while(r < len(s)):
        ch = s[r]
        if ch not in required:
            l += 1
        else:
            required[ch] -= 1
        r += 1
        
    
    


if __name__ == "__main__":
    s = "ADOBECODEBANC"
    t = "ABC"
    print(min_window_substring(s, t))
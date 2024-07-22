def majorityElement(v: [int]) -> [int]:
    # Write your code here

    """
    # Brute Force Approach
    # T.C: O(n*n) ~ O(n^2)
    # S.C: O(1)

    results = []

    n = len(v)
    if n == 0: return results

    for i in range(n):
        element = v[i]
        if len(results) == 0 or element != results[0]:
            count = 0
            for j in range(n):
                if v[j] == element:
                    count += 1
            if count > (n/3):
                results.append(element)
        if len(results) == 2:
            break

    return results
    """

    """
    # Better Approach
    # T.C: O(n)
    # S.C: O(n)

    n = len(v)
    if n == 0: return []

    counts = {}
    for i in range(n): # T.C: O(n)
        if v[i] not in counts:
            counts[v[i]] = 0
        counts[v[i]] += 1
    
    result = []  # at most 2 elements so S.C can be considered constant here
    for key, count in counts.items():
        if count > (n/3):
            result.append(key)
        if len(result) == 2:
            break
    
    return result
    """

    """
    # Optimal Approach
    # T.C: O(n)
    # S.C: O(1)
    """

    n = len(v)
    if n == 0:
        return []

    # initialization
    cnt1 = 0
    cnt2 = 0
    el1 = float("-inf")
    el2 = float("-inf")

    for i in range(n):  # T.C: O(n)
        if cnt1 == 0 and el2 != v[i]:
            cnt1 = 1
            el1 = v[i]
        elif cnt2 == 0 and el1 != v[i]:
            cnt2 = 1
            el2 = v[i]
        elif el1 == v[i]:
            cnt1 += 1
        elif el2 == v[i]:
            cnt2 += 1
        else:
            cnt1 -= 1
            cnt2 -= 1

    # manually verifying if the elements are the required
    cnt1, cnt2 = 0, 0
    for i in range(n):
        if el1 == v[i]:
            cnt1 += 1
        elif el2 == v[i]:
            cnt2 += 1

    result = []  # at most 2 elements so S.C can be considered constant here
    mini = int(n / 3) + 1
    if cnt1 >= mini:
        result.append(el1)
    if cnt2 >= mini:
        result.append(el2)

    result.sort()
    return result


if __name__ == "__main__":
    test_case = [2, 2, 1, 3, 1, 1, 3, 1, 1]
    result = majorityElement(test_case)
    print("The element(s) with greater than n/3 occurrences are:", result)

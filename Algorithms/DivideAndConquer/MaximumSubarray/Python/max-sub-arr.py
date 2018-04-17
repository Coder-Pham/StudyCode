"""
@author Nhat M. Nguyen
@date   17-04-18
"""


"""
    Maximum subarray problem using Divide-and-Conquer
    Time complexity: O(nlog(n))
"""


INF = 1e9


"""
@param low  the start of the subarray, inclusive
@param mid  the midpoint of the subarray
@param high the end of the subarray, exclusive
"""
def max_crossing_array(a, low, mid, high):
    left_sum = -INF
    sum = 0
    for i in range(mid - 1, low - 1, -1):
        sum += a[i]
        if left_sum < sum:
            left_sum = sum
            max_left = i

    right_sum = -INF
    sum = 0
    for i in range(mid, high):
        sum += a[i]
        if right_sum < sum:
            right_sum = sum
            max_right = i + 1

    cross_arr = []

    for i in range(max_left, max_right):
        cross_arr.append(a[i])

    return cross_arr, left_sum + right_sum


"""
@param low  the start of the subarray, inclusive
@param high the end of the subarray, exclusive
"""
def max_sub_array(a, low, high):
    if (low + 1 == high):
        return a, a[low]

    mid = (low + high) // 2

    left_sub_array,  left_sum  = max_sub_array(a, low, mid)
    right_sub_array, right_sum = max_sub_array(a, mid, high)
    cross_sub_array, cross_sum = max_crossing_array(a, low, mid, high)

    if (left_sum > right_sum):
        if (left_sum > cross_sum):
            return left_sub_array, left_sum
        else:
            return cross_sub_array, cross_sum
    else:
        if (right_sum > cross_sum):
            return right_sub_array, right_sum
        else:
            return cross_sub_array, cross_sum


if __name__ == "__main__":
    a = [-2, -3, 4, -1, -2, 1, 5, -3]
    max_sub_arr, max_sum = max_sub_array(a, 0, len(a))
    print(max_sub_arr)
    print("max sum: {0}".format(max_sum))

# result: [4, -1, -2, 1, 5]; sum = 7

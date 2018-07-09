"""
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
"""

def mul(array):
    """
    Return the product of all element of the array
    """
    res = 1    
    for ele in array:
        res *= ele
    return res

def product_array(array):
    """
    Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
    """
    return [mul(array) / ele for ele in array]

def main():
    print "Starting script"

    tests = [
	([1, 2, 3, 4, 5], [120, 60, 40, 30, 24]),
	([3, 2, 1], [2, 3, 6])
    ]

    for instance, expected in tests:
	assert product_array(instance), expected

    print "Success !"

if __name__ == "__main__":
    main()

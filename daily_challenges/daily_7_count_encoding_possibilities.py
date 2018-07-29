"""
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
"""

def is_possible_pair(first_char, next_char):
    if int(first_char + next_char) < 27:
	return True
    return False

def count_decoded_possibilities(string, count):
    if not string:
	return count + 1
	
    if len(string) > 1 and is_possible_pair(string[0], string[1]):
	count = count_decoded_possibilities(string[2:], count)
    
    return count_decoded_possibilities(string[1:], count)


def main():
    print "Starting script"

    for example, expected_result in [('111', 3), ('12', 3), ('34', 2)]:
	assert count_decoded_possibilities(example, 0), expected_result

    print "Success !"

if __name__ == "__main__":
    main()

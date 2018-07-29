"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

Implement car and cdr.
"""

def to_tuple(*args):
    """
    Return parameters as a tuple.
    """
    return args

def car(pair_fn):
    """
    Return the first element of the pair.
    """
    return pair_fn(to_tuple)[0]

def cdr(pair_fn):
    """
    Return the last element of the pair.
    """
    return pair_fn(to_tuple)[1]


def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair


def main():
    print "Starting script"

    assert car(cons(3, 4)), 3 
    assert cdr(cons(3, 4)), 4 

    print "Success !"

if __name__ == "__main__":
    main()

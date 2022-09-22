#!/usr/bin/python3

"""
Module add-integer
Adds two integer together
"""

def add_integer(a, b=98):
    """
    Return the addition of two numbers
    The numbers can be integers or floats
    If they are floats they get casted to integers first
    >>> add_integer(1, 2)
    3
    >>> add_integer(100, -2)
    98
    >>> add_integer(100.3, -2)
    98
    >>> add_integer(4, "test")
    b must be an integer
    """

 if type(a) is not int and type(a) is not float:
        raise TypeError("a must be an integer")
    if type(b) is not int and type(b) is not float:
        raise TypeError("b must be an integer")

    if type(a) is float:
        a = int(a)
    if type(b) is float:
        b = int(b)

    return a + b

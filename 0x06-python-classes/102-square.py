#!/usr/bin/python3

class Square:

    def __init__(self, size=0):
        if (type(size) is not int):
            raise (TypeError("size must be an integer"))
        elif (size < 0):
            raise (ValueError("size must be >= 0"))
        else:
            self.__size = size

    def __lt__(self, other):
        return (self.area() < other.area())

    def __le__(self, other):
        return (self.area() <= other.area())

    def __gt__(self, other):
        return (self.area() > other.area())

    def __ge__(self, other):
        return (self.area() >= other.area())

    def __eq__(self, other):
        return (self.area() == other.area())

    def __ne__(self, other):
        return (self.area() != other.area())

    def area(self):
        return (self.__size ** 2)

    @property
    def size(self):
        return (self.__size)

    @size.setter
    def size(self, value):
        if ((type(value) is int) or (type(value) is float)):
            if (value < 0):
                raise (ValueError("size must be >= 0"))
            else:
                self.__size = value
        else:
            raise (TypeError("size must be a number"))

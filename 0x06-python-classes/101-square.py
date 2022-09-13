#!/usr/bin/python3

class Square:
    def __init__(self, size=0, position=(0, 0)):
        if (type(size) is not int):
            raise (TypeError("size must be an integer"))
        elif (size < 0):
            raise (ValueError("size must be >= 0"))
        else:
            self.__size = size

        if (len(position) != 2) or (type(position) is not tuple)\
                or (type(position[0]) is not int)\
                or (type(position[1]) is not int)\
                or (position[0] < 0) or (position[1] < 0):
            raise TypeError("position must be a tuple of 2 positive integers")
        else:
            self.__position = position

    def area(self):
        return (self.__size ** 2)

    def my_print(self):
        if (self.__size == 0):
            print()
        else:
            for blank in range(self.position[1]):
                print()
            for rows in range(self.__size):
                print(" " * self.position[0], end='')
                print("#" * self.__size)

    def __str__(self):
        str = ""
        if (self.__size == 0):
            return str
        else:
            for blank in range(self.position[1]):
                str += "\n"
            for rows in range(self.__size):
                str += (" " * self.position[0])
                str += ("#" * self.__size)
                if (rows != self.__size - 1):
                    str += "\n"
        return (str)

    @property
    def size(self):
        return (self.__size)

    @size.setter
    def size(self, value):
        if (type(value) is not int):
            raise (TypeError("size must be an integer"))
        elif (value < 0):
            raise (ValueError("size must be >= 0"))
        else:
            self.__size = value

    @property
    def position(self):
        return (self.__position)

    @position.setter
    def position(self, value):
        if (len(value) != 2) or (type(value) is not tuple) \
                or (type(value[0]) is not int) \
                or (type(value[1]) is not int) \
                or (value[0] < 0) or (value[1] < 0):
            raise TypeError("position must be a tuple of 2 positive integers")
        else:
            self.__position = value

#!/usr/bin/python3
'''
This is "5-text_indentation" module
It supplies one function, text_indentation(text)
For example:
>>> text_indentation("Dynamo: Diesel? Lee.")
'''


def text_indentation(text):
    """
    Prints a text with 2 new lines after each of those characters: ., ? and :
    Text must be a string
    There should be no space at the beginning or end of each printed line
    """

    if type(text) is not str:
        raise TypeError("text must be a string")

    for delim in ".:?":
        text = (delim + "\n\n").join(
            [line.strip(" ") for line in text.split(delim)])

    print("{}".format(text), end="")

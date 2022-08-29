#!/usr/bin/python3
if __name__ == "__main__":
    from sys import argv
    num_args = len(argv)
    x = 0
    for i in range(1, num_args):
        x += int(argv[i])
    print("{:d}".format(x))

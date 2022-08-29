#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    x = len(sys.argv)
    if x <= 1:
        print("0 arguments.")
    else:
        if x == 2:
            print("{:d} argument:".format(x - 1))
        else:
            print("{:d} arguments:".format(x - 1))
        for i in range(1, x):
            print("{:d}: {}".format(i, sys.argv[i]))

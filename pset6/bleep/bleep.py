from cs50 import get_string
from sys import argv


def main():
    wordList = []

    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    f = open(argv[1], "r")
    for line in f:
        wordList.append(line.strip("\n"))

    uncensored = input("What message would you like to censor?\n")
    uncensored = uncensored.split()

    for i in range(0, len(uncensored)):
        if(uncensored[i].lower() in wordList):
            uncensored[i] = "*"*len(uncensored[i])

    print(' '.join(uncensored))


if __name__ == "__main__":
    main()

from nltk.tokenize import sent_tokenize
from textwrap import wrap

def lines(a, b):
    """Return lines in both a and b"""
    aList = a.split("\n")
    bList = b.split("\n")
    identical = []

    for line in aList:
        if line in bList:
            identical.append(line)

    return identical


def sentences(a, b):
    """Return sentences in both a and b"""

    aList = set(sent_tokenize(a))
    bList = set(sent_tokenize(b))
    identical = []

    for sentence in aList:
        if sentence in bList:
            identical.append(sentence)

    return identical


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    identical = []

    for i in range(len(a)):
        substring = ""
        for x in range(n):
            if((i+x)<(len(a)) and a[i+x] != " " and a[i+x] != "\n"):
                substring += a[i+x]
        if(len(substring)==n):
            if(substring in b):
                identical.append(substring)

    return set(identical)

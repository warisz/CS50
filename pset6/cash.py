from cs50 import *

minNum = 0

while True:
    changeOwed = get_float("Change owed: ")*100
    if(changeOwed >= 0):
        break;


minNum += changeOwed//25
changeOwed %= 25

minNum += changeOwed//10
changeOwed %= 10

minNum += changeOwed//5
changeOwed %= 5

minNum += changeOwed//1
changeOwed %= 1

print(int(minNum))
import math
testCase, total = map(int, input().split())
coinTypeArry = []
for i in range(testCase):
    coinTypeArry.append(int(input()))
coinCount = 0
for coin in reversed(coinTypeArry):
    dividedRes = math.trunc(total/coin)
    if dividedRes >= 1:
        total = total % coin
        coinCount += dividedRes
print(coinCount)

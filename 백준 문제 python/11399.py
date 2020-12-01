import sys

# 최소의 시간이 걸리는 사람을 앞에 놓는다.
# ADDED에 자신을 더하고 그 결과를 답에 더한다.

# 변수
# testCase
# inputArray
# added
# result

testCase = int(sys.stdin.readline())

inputArray = map(int, sys.stdin.readline().split())

added = 0
result = 0
for waitingTime in sorted(inputArray):
    added += waitingTime
    result += added

print(result)

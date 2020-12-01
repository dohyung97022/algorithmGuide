import sys
caseNum = int(sys.stdin.readline())
meetingArry = []
for i in range(caseNum):
    start, end = map(int, input().split())
    meetingArry.append((start, end))

# 이부분을 미스....
meetingArry = sorted(meetingArry, key=lambda x: x[0])


meetingArry = sorted(meetingArry, key=lambda x: x[1])

end = 0
count = 0
for meeting in meetingArry:
    if end == 0:
        end = meeting[1]
        count += 1
    elif end <= meeting[0]:
        end = meeting[1]
        count += 1

print(count)

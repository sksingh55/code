import sys

def fast_count_segments(starts, ends, points):
    cnt = {}
    segments_num = 0

    listpoints = [(x, 'l') for x in starts]
    listpoints += [(x, 'p') for x in points]
    listpoints += [(x, 'r') for x in ends]

    listpoints.sort()

    for p in listpoints:
        if p[1] == 'l':
            segments_num += 1
        elif p[1] == 'r':
            segments_num -= 1
        else:
            cnt[p[0]] = segments_num

    return [cnt[x] for x in points]

if __name__ == '__main__':
    x = input().split()
    n = int(x[0])
    m = int(x[1])
    starts=[]
    ends=[]
    for i in range(n):
        x = input().split()
        starts.append(int(x[0]))
        ends.append(int(x[1]))

    x = input().split()
    points = [int(i) for i in x]

    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
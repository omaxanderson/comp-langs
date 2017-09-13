import sys

def DoubleIt(x):
    return 2*x

def SecsToMinSecs(sec):
    return (sec//60, sec%60)

def MinSecsToSecs(time):
    return time[0] * 60 + time[1]

def Quadrant(pt):
    q = 0
    if pt[0] > 0 and pt[1] > 0:
        q = 1
    elif pt[0] < 0 and pt[1] > 0:
        q = 2
    elif pt[0] < 0 and pt[1] < 0:
        q = 3
    elif pt[0] > 0 and pt[1] < 0:
        q = 4
    return q
        
print(DoubleIt(3))
print(SecsToMinSecs(123))
hr = (4, 59)
print(MinSecsToSecs(hr))
pt = (3, -2)
print("The quadrant is %3d" % Quadrant(pt))
print(sys.version)

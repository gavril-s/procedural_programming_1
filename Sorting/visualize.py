import math
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('TkAgg')

def log(x):
    if x <= 0: 
        return 0
    return math.log(x) / math.log(2)

FILENAME = 'data/results.txt'

data = []

f = open(FILENAME)
for line in f:
    if line[0] == '#':
        continue
    data.append(list(map(float, line.split())))
f.close()

k1 = 10**(-7)
k2 = 10**(-8)

plt.plot([i[0] for i in data], [i[1] for i in data], 'r')
plt.plot([i[0] for i in data], [i[2] for i in data], 'b')
plt.plot([i[0] for i in data], [i[3] for i in data], 'g')
plt.plot([i[0] for i in data], [k1 * i[0] * log(i[0]) for i in data], 'k')
plt.plot([i[0] for i in data], [k2 * i[0] * log(i[0]) for i in data], 'k')
plt.xlabel("Red - rb_sort, blue - bin_sort, green - std::sort")
plt.show()  

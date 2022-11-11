import math
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('TkAgg')

def log(x):
    if x <= 0: 
        return 0 # по приколу
    return math.log(x) / math.log(2)

FILENAME = 'data/reshd.txt'

data = []

f = open(FILENAME)
for line in f:
    if line[0] == '#':
        continue
    data.append(list(map(float, line.split())))
f.close()

k1 = -7
k2 = -8

plt.plot([i[0] for i in data], [i[1] for i in data], 'r', label="red-black tree")
plt.plot([i[0] for i in data], [i[2] for i in data], 'b', label="binary tree")
plt.plot([i[0] for i in data], [i[3] for i in data], 'g', label="std::sort()")
#plt.plot([i[0] for i in data], [10**k1 * i[0] * log(i[0]) for i in data], 'k', label=f'n * log(n) * 10^{k1}')
#plt.plot([i[0] for i in data], [10**k2 * i[0] * log(i[0]) for i in data], 'k', label=f'n * log(n) * 10^{k2}')
plt.legend()
plt.show()  

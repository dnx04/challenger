import math

c = 0

for p in range(1, 2012):
    for q in range(p + 1, 2012 - p):
        if 1 > p + q - 2 * math.sqrt(p) * math.sqrt(q) > 0:
            c += int(2011 / - math.log(p + q - 2 * math.sqrt(p) * math.sqrt(q), 10)) + 1

print(c)

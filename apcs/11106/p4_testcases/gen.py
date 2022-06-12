import random

def generate(n, m, filename):
    with open(filename, "w") as f:
        print(str(n) + ' ' + str(m), file=f)
        for i in range(n):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(-100, 100), file=f, end='')
        print('', file=f)
        for i in range(m):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(-100, 100), file=f, end='')
        print('', file=f)

def generate_pos(n, m, filename):
    with open(filename, "w") as f:
        print(str(n) + ' ' + str(m), file=f)
        for i in range(n):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(0, 100), file=f, end='')
        print('', file=f)
        for i in range(m):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(0, 100), file=f, end='')
        print('', file=f)

def generate_neg(n, m, filename):
    sign_a = random.randint(0, 1)
    sign_b = 1 - sign_a
    if sign_a == 0:
        sign_a = -1
    else:
        sign_b = -1
    with open(filename, "w") as f:
        print(str(n) + ' ' + str(m), file=f)
        for i in range(n):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(0, 100) * sign_a, file=f, end='')
        print('', file=f)
        for i in range(m):
            if i > 0:
                print(' ', file=f, end='')
            print(random.randint(0, 100) * sign_b, file=f, end='')
        print('', file=f)


generate(1, 1, "00.in")
generate_pos(random.randint(90, 100), random.randint(90, 100), "01.in")
generate(random.randint(90, 100), random.randint(90, 100), "02.in")
generate_neg(random.randint(90, 100), random.randint(90, 100), "03.in")

for i in range(14):
    idx = 4 + i
    generate(random.randint(990, 1000), random.randint(990, 1000), "%02d.in" % idx)

for i in range(2):
    idx = 18 + i
    generate_neg(random.randint(990, 1000), random.randint(990, 1000), "%02d.in" % idx)


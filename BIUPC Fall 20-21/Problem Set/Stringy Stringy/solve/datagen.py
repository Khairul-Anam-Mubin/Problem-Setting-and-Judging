from random import Random
rnd = Random(12)

def downward(st, len):
    seq = []
    for i in range(len):
        p = st//2
        p = max(p + p//2, 1)
        x = rnd.randint(p, st)
        st = min(st, x)
        seq.append(x)
    return seq


def upward(ed, len):
    return downward(ed, len)[::-1]


if __name__ == "__main__" :
    print(downward(50, 20))
    print()
    print(upward(200, 15))
    print()
    print(downward(50, 20) + upward(200, 15))
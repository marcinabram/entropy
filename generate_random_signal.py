"""Generate random signal."""
import random


if __name__ == '__main__':
    """Generate the signal."""
    random.seed(43)
    signal = [round(random.random()) for _ in range(10**7)]

    with open('signal.dat', 'w') as f:
        f.write(''.join(map(lambda s: str(s), signal)))

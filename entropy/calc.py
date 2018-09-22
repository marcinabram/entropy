"""Calculate entropy of a binary signal."""
import collections
import math


def entropy(signal: list, window: int) -> float:
    """Computes entropy of a signal."""
    n = len(signal)//window
    parts = [tuple(signal[i*window:(i+1)*window]) for i in range(n)]
    counter = list(collections.Counter(parts).values())

    if len(counter) <= 1:
        return 0

    norm = math.log2(len(parts))
    return (-sum([c*math.log2(c) for c in counter])/len(parts) + norm)/window

"""Demo."""
import argparse

import entropy


if __name__ == '__main__':
    """Run demo."""
    parser = argparse.ArgumentParser(description='Set window size.')
    parser.add_argument('-w', '--window', type=int, default=2)
    parser.add_argument('-f', '--file', type=str, default="signal.dat")
    args = parser.parse_args()

    with open(args.file) as f:
        signal = f.readline()

    exact = 0.99999922015194587997155654610165791488976968896093062603
    s = entropy.calc(signal, window=args.window)
    print('Entropy:', s)
    print('Error:', abs(s-exact))

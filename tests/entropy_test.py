"""Test entropy."""
import math
import unittest

import entropy


class EntropyTest(unittest.TestCase):
    """Test input."""

    def setUp(self):
        """Load before every test."""

    def test_zero0(self):
        """Test signal with zero enropy."""
        signal = []
        self.assertEqual(entropy.calc(signal, window=2), 0)

    def test_zero1(self):
        """Test signal with zero enropy."""
        signal = [0, 0, 0, 0, 0, 0, 0, 0]
        self.assertEqual(entropy.calc(signal, window=2), 0)

    def test_zero2(self):
        """Test signal with zero enropy."""
        signal = [0, 1, 0, 1, 0, 1, 0, 1]
        self.assertEqual(entropy.calc(signal, window=2), 0)

    def test_one1(self):
        """Test signal with one enropy."""
        signal = [0, 1, 0, 1, 0, 1, 0, 1]
        self.assertEqual(entropy.calc(signal, window=1), 1)

    def test_one2(self):
        """Test signal with one enropy."""
        signal = [0, 0, 0, 1, 1, 0, 1, 1]
        self.assertEqual(entropy.calc(signal, window=2), 1)

    def test_mixed(self):
        """Test signal with zero enropy."""
        signal = [0, 0, 1, 1, 1]
        expected = -(2*math.log2(2./5.) + 3*math.log2(3./5.))/5
        expected = -(2*math.log2(2) + 3*math.log2(3))/5 + math.log2(5)
        self.assertAlmostEqual(entropy.calc(signal, window=1), expected, 15)


if __name__ == '__main__':
    """Run unittests."""
    unittest.main()

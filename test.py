import statistics
import stats

import random

import pytest

params = [
    (statistics.mean, stats.mean),
    # (statistics.geometric_mean, stats.geometric_mean),  # geometric_mean not available till python 3.8
    (statistics.harmonic_mean, stats.harmonic_mean),
    (statistics.pvariance, stats.pvariance),
    (statistics.variance, stats.variance),
    (statistics.pstdev, stats.pstdev),
    (statistics.stdev, stats.stdev),
    (statistics.mode, stats.mode),
]

# Tests from https://github.com/python/cpython/blob/master/Lib/test/test_statistics.py

@pytest.mark.parametrize("original,mine", params)
def test_ints(original, mine):
    # Test mean with ints.
    data = [0, 1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 7, 7, 7, 8, 9]
    random.shuffle(data)
    assert original(data) == mine(data)
    
@pytest.mark.parametrize("original,mine", params)
def test_floats(original, mine):
    # Test mean with floats.
    data = [17.25, 19.75, 20.0, 21.5, 21.75, 23.25, 25.125, 27.5]
    random.shuffle(data)
    assert original(data) == mine(data)


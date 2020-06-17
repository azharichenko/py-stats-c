import statistics
import stats

import random

import pytest

params = [
    (statistics.mean, stats.mean),
    (statistics.fmean, stats.fmean),
    (statistics.geometric_mean, stats.geometric_mean), 
    (statistics.harmonic_mean, stats.harmonic_mean),
    (statistics.pvariance, stats.pvariance),
    (statistics.variance, stats.variance),
    (statistics.pstdev, stats.pstdev),
    (statistics.stdev, stats.stdev),
    (statistics.median,  stats.median),
    (statistics.median_high,  stats.median_high),
    (statistics.median_low,  stats.median_low),
]

mean_params = [
    (statistics.mean, stats.mean),
    (statistics.fmean, stats.fmean),
    (statistics.geometric_mean, stats.geometric_mean), 
    (statistics.harmonic_mean, stats.harmonic_mean),
]

median_params = [
    (statistics.median,  stats.median),
    (statistics.median_high,  stats.median_high),
    (statistics.median_low,  stats.median_low),
]

mode_params = [
    (stats.mode, statistics.mode),
    (statistics.multimode,  stats.multimode),
]

variance_params = [    
    (statistics.pvariance, stats.pvariance),
    (statistics.variance, stats.variance),
    (statistics.pstdev, stats.pstdev),
    (statistics.stdev, stats.stdev),
]

# Tests from https://github.com/python/cpython/blob/master/Lib/test/test_statistics.py

@pytest.mark.parametrize("original,mine", params)
def test_empty(original, mine):
    data = []
    with pytest.raises(statistics.StatisticsError):
        original(data) 
        
    with pytest.raises(RuntimeError):
        mine(data)

@pytest.mark.parametrize("original,mine", params)
def test_ints(original, mine):
    # Test mean with ints.
    data = [0, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 6, 7, 7, 7, 7, 8, 9]
    random.shuffle(data)
    assert original(data) == mine(data)
    
@pytest.mark.parametrize("original,mine", params)
def test_floats(original, mine):
    # Test mean with floats.
    data = [17.25, 19.75, 20.0, 21.5, 21.75, 23.25, 25.125, 27.5]
    random.shuffle(data)
    assert original(data) == mine(data)


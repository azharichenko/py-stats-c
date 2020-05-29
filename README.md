# py-stats-c
Learning writing extensions for python with C/C++ by recreating the statistics package

This repo is just me exploring extending python using C/C++ to build knowledge for a potential future project involving implementing statistical/machine learning algorithm.

## Goals
- Simple to implement the following functions that exist in the `statistics` package
  - [x] `mean(data)`
  - [ ] `fmean(data)`
  - [x] `geometric_mean(data)`
  - [x] `harmonic_mean(data)`
  - [ ] `median(data)`
  - [ ] `median_low(data)`
  - [ ] `median_high(data)`
  - [ ] `median_grouped(data, interval=1)`
  - [ ] `mode(data)`
  - [ ] `multimode(data)`
  - [x] `pstdev(data, mu=None)`
  - [x] `pvariance(data, mu=None)`
  - [x] `stdev(data, xbar=None)`
  - [x] `variance(data, xbar=None)`
  - [ ] `quantiles(data, *, n=4, method='exclusive')`
  - [ ] `NormalDist(mu=0.0, sigma=1.0)`
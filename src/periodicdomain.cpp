#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

#include "periodicdomain.hpp"

FnWithPeriodicDomain::FnWithPeriodicDomain(
    double bound, const Sampling &samples) : bound_(bound), samples_(samples) {
}

bool FnWithPeriodicDomain::is_in_epigraph(double x, double y) {

  double x_hi, y_hi, x_lo, y_lo;
  auto sample_it = std::upper_bound(
      samples_.begin(), samples_.end(), std::make_pair(x, 0),
      [](const Sample &sample_one, const Sample &sample_two) {
        return sample_one.first < sample_two.first;
      });

  if (sample_it == samples_.end()) {
    sample_it = samples_.begin();
  }
  std::tie(x_hi, y_hi) = *sample_it;

  if (sample_it == samples_.begin()) {
    sample_it = samples_.end();
  }
  std::tie(x_lo, y_lo) = *(--sample_it);

  // Remember, the domain of the function is periodic and is computed 
  // as piecewise linear between sample points. Variable theta is
  // fractionally how far x is along the interval [x_lo, x_hi).
  double theta = (
      std::fmod(x - x_lo + bound_, bound_)
       / std::fmod(x_hi - x_lo + bound_, bound_));
  double yhat = (1 - theta) * y_lo + theta * y_hi;
  return y >= yhat;
}

#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

#include "periodicdomain.hpp"

FnWithPeriodicDomain::FnWithPeriodicDomain(
    double bound, const Sampling &samples) : bound_(bound), samples_(samples) {
}

bool FnWithPeriodicDomain::is_in_epigraph(double x, double y) {
  // Your code here.
  return true;
}

#include <gtest/gtest.h>
#include <utility>

#include "periodicdomain.hpp"

TEST(FnWithPeriodicDomainTest, ConstantFn) {
  Sampling samples;
  samples.push_back(std::make_pair(0.2, 0.0));
  samples.push_back(std::make_pair(0.8, 0.0));
  FnWithPeriodicDomain fn(1.0, samples);
  EXPECT_TRUE(fn.is_in_epigraph(0.5, 1.0));
  EXPECT_FALSE(fn.is_in_epigraph(0.5, -1.0));
}

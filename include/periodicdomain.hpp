#ifndef PERIODICDOMAIN_HPP_NFKG1YLP_
#define PERIODICDOMAIN_HPP_NFKG1YLP_

#include <utility>
#include <vector>

using Sample = std::pair<double, double>;
using Sampling = std::vector<Sample>;

class FnWithPeriodicDomain {

  public:
  
    FnWithPeriodicDomain(double bound, const Sampling &samples);
    virtual ~FnWithPeriodicDomain() = default;

    bool is_in_epigraph(double x, double y);

  private:

    double bound_;
    const Sampling samples_;
};

#endif // PERIODICDOMAIN_HPP_NFKG1YLP_

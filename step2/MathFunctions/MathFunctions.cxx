#include <cmath>
#include "MathFunctions.h"

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

namespace mathfunctions {
  double sqrt(double x) {
    // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
    // Otherwise, use std::sqrt.
    #ifdef USE_MYMATH
      return detail::mysqrt(x);
    #else
      return std::sqrt(x);
    #endif
  }
}

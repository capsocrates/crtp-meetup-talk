
#include <cstdio>

//including both of these is a compiler error, because the compiler can't tell the signatures of "drive" apart
// #include "screw-utilities.h"
// #include "vehicle-utilities.h"

//we can include both of these files since the compiler can tell the signatures of "drive" apart
#include "vehicle-concept.h"
#include "screw-concept.h"

auto main(const int /*argc*/, const char *const []/*argv*/) -> int
{
  auto car{crtp::car{}};

  crtp::drive(car);

  auto screw{crtp::phillips{}};

  crtp::drive(screw);

  return 0;
}

#include <string>

namespace crtp
{
template <class Derived>
struct vehicle
{
};

struct car : vehicle<car>
{
  auto name() const -> std::string { return "car"; }
};

template <class Vehicle>
void drive(vehicle<Vehicle> const& v)
{
    Vehicle const& v_= static_cast<Vehicle const&>(v);
    printf("%s\n", v_.name().c_str());
}

}/*end crtp*/
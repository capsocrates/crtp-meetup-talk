#include <string>

namespace crtp
{
template <class Derived>
struct vehicle
{
};

struct car : vehicle<car>
{
  auto name() -> std::string { return "car"; }
};

template <class Derived>
struct screw
{};

struct phillips : screw<phillips>
{
  auto status() -> std::string { return "phillips"; }
};

template <class Vehicle>
void drive(vehicle<Vehicle> const& v)
{
    Vehicle const& v_= static_cast<Vehicle const&>(v);
    printf("%1", v_.name().c_str());
};

template <class Screw>
void drive(screw<Screw> const& s)
{
    Screw const& s_= static_cast<Screw const&>(s);
    printf("%1", s_.status().c_str());
};
}/*end crtp*/
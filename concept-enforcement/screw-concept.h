#include <string>

namespace crtp
{

template <class Derived>
struct screw
{};

struct phillips : screw<phillips>
{
  auto status() const -> std::string { return "phillips"; }
};

template <class Screw>
void drive(screw<Screw> const& s)
{
    Screw const& s_= static_cast<Screw const&>(s);
    printf("%s\n", s_.status().c_str());
}
}/*end crtp*/

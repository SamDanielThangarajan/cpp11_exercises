#include <boost/hana.hpp>
#include <cassert>
#include <iostream>
#include <string>

namespace hana = boost::hana;

struct fish { std::string name; };
struct cat  { std::string name; };
struct dog  { std::string name; };

int main()
{
   
   auto animals = hana::make_tuple(fish{"nemo"},cat{"tom"},dog{"scooby"});
   
   // Lets apply transform
   auto animal_names = hana::transform(animals, [](/*generic lambda c++14*/auto obj)
         {
            return obj.name;
         });

   assert(animal_names == hana::make_tuple("nemo","tom","scooby"));

}

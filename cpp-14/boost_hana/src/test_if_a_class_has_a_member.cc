#include <iostream>

/*
 * Refer:
 * http://stackoverflow.com/a/257382/627587
 */

struct Hello
{
   int helloworld() {
      std::cout << "Hello World!" << std::endl;
      return 0;
   }
};

struct Generic {};

template <typename T>
class has_helloworld
{
   template <typename C> static char test( decltype(&C::helloworld) ) ;
   template <typename C> static long test(...);

   public:
   enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

int main(int argc, char *argv[])
{
   std::cout << has_helloworld<Hello>::value << std::endl;
   std::cout << has_helloworld<Generic>::value << std::endl;
   return 0;
}

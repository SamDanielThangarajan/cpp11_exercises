#include "timer.hpp"
#include <chrono>


int main()
{

   timer::create_timer(std::chrono::milliseconds(1000), []()
         {
            std::cout << "Timer fired" << std::endl;
         });

   return 0;



}

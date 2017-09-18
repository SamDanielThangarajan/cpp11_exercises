
#include <chrono>
#include "timer_manager.hpp"
//#include <boost/asio/basic_waitable_timer.hpp>
#include <boost/asio/steady_timer.hpp>

namespace timer
{

   /*! \brief String literal to get std::chrono::milliseconds
    *    
    *    Usage:
    *       std::chrono::milliseconds one_sec = 1_s;
    *       std::chrono::milliseconds two_sec = 2_s;
    *          
    *  \param sec, seconds.    
    *  \return std::chrono::milliseconds
    */
   constexpr std::chrono::milliseconds operator "" _s(unsigned long long sec)
   {
      return std::chrono::milliseconds(1000*sec);
   } 

   template<typename F, typename... Args>
   struct timer
   {
      timer(const std::chrono::milliseconds milliseconds, F call, Args&&... args)
         :m_timer(timer_manager::instance().get_io_service(),
               std::chrono::steady_clock::now() + milliseconds)
      {
         //m_timer.async_wait(call, std::forward<Args>(args)...);
         m_timer.async_wait([](const boost::system::error_code& error)
              {
               std::cout << "timer fired..." << std::endl;
              });
      }

      boost::asio::steady_timer m_timer;
      //boost::asio::waitable_timer m_timer;
   };

   /*
    * - Below handlers are not parallel executors
    */
   template<typename F, typename... Args>
   timer<F,Args...> create_timer(const std::chrono::milliseconds milliseconds,
         F callable, Args&& ...args)
   {
      return timer<F,Args...>(milliseconds, callable, std::forward<Args>(args)...);
   }

   
}

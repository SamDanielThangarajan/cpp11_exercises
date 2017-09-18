
#include <chrono>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

// Now this is a singleton, perhaps it should not be a singleton?
class timer_manager
{
 
   public:

      timer_manager& instance()
      {
         static timer_manager manager;
         return manager;
      }

      void stop()
      {
         m_service.stop();
         m_thrd.join_all();
      }
      
      boost::asio::io_service& get_io_service()
      {
         return m_service;
      }

   private:
      timer_manager():
         m_work(m_service)
      {
         m_thrd.create_thread(boost::bind(&boost::asio::io_service::run,&m_service));
      }

   private:
      boost::asio::io_service m_service;
      boost::asio::io_service::work m_work;
      boost::thread_group m_thrd;


};


#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <signal.h>

bool _term_size_changed = false;
int _width = 980;
int _height = 24;

void print_something()
{
   for (int i=0; i<10; i++)
   {
      std::cout << "Hello world" << std::endl;
   }
}

void
get_term_size()
{
   const char* env_col = std::getenv("COLUMNS");
   const char* env_rows = std::getenv("LINES");
   if (env_col && env_rows)
   {
      _width = std::stoi(env_col);
      _height = std::stoi(env_rows);
   }
}


static void
winch_handler(int not_used)
{
   (void) not_used;
   _term_size_changed = true;
}

int main()
{
 
   signal(SIGWINCH, winch_handler);

   initscr();
   nonl();
   noecho(); 
   cbreak();

   for (int i=0; i<20; i++)
   {
      if (_term_size_changed)
      {
         resizeterm(_height, _width);
         _term_size_changed = false;
      }

      print_something();

      refresh();
   }

   endwin();

}

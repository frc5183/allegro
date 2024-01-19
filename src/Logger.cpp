#include <Logger.hpp>
namespace Allegro
{
  void Logger::log(char* level, char* msg) {
     std::cout << "[" << level << "] " << msg << std::endl;
  }
}

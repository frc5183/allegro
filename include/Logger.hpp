#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
namespace Allegro
{
  class Logger {
    private:
      std::filesystem::path logFileLocation;
      std::ofstream* logFile = nullptr;
    public:
      Logger();
      Logger(std::filesystem::path);
      ~Logger();
      void log(std::string&,std::string&);
      void log(char*,char*);
      void log(const char*, const char*);
  };
}

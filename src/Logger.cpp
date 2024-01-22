#include <Logger.hpp>
namespace Allegro
{
  Logger::Logger() {}
  Logger::Logger(std::filesystem::path path) {
    if (std::filesystem::is_directory(path)) {
      logFileLocation=path;
      auto now = std::chrono::system_clock::now();
      auto localTime = std::chrono::system_clock::to_time_t(now);
      std::stringstream ss;
      ss << path.string() << "/allegro_" << std::put_time(std::localtime(&localTime), "%Y_%m_%d_%H_%M_%S") << ".txt";
      std::string filename = std::string(ss.str());
      logFile = new std::ofstream();
      logFile->open(filename, std::ios::trunc);
    }
  }
  Logger::~Logger() {
    if (logFile != NULL) {
      delete logFile;
    }
  }
  void Logger::log(char* level, char* msg) {
    std::stringstream ss;
    ss << "[" << level << "] " << msg << std::endl;
    if (logFile != NULL) {
      *logFile << ss.str();
    }
    std::cout << ss.str();
  }
  void Logger::log(const char* level, const char* msg) {
    std::stringstream ss;
    ss << "[" << level << "] " << msg << std::endl;
    if (logFile != NULL) {
      *logFile << ss.str();
      logFile->flush();
    }
    std::cout << ss.str();
  }
  void Logger::log(std::string& level, std::string& msg) {
    std::cout << "4" << std::endl;
    char* c_level = new char[level.length()+1];
    char* c_msg = new char[level.length()+1];
    level.copy(c_level,level.length());
    msg.copy(c_msg,msg.length());
    c_level[level.length()]='\0';
    c_msg[msg.length()]='\0';
    log(c_level, c_msg);
    delete c_level;
    delete c_msg;
  }
}

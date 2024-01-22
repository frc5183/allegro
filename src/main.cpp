#include <iostream>
#include <filesystem>
#include <libfreenect.hpp>
#include <networktables/NetworkTableInstance.h>
#include <Logger.hpp>
#include <Config.hpp>
#include <Kinect.hpp>
using namespace Allegro;
int main() {
  Logger logger(Allegro::logPath);
  logger.log("INFO", "STARTING");
  logger.log("TEAM", std::to_string(Allegro::team).c_str());
  auto inst = nt::NetworkTableInstance::GetDefault();
  Freenect::Freenect freenect;
  Kinect* kinect = &freenect.createDevice<Kinect>(0);
  kinect->setTiltDegrees(0);
  kinect->startVideo();
  kinect->startDepth();
  kinect->stopVideo();
  kinect->stopDepth();
  return 0;
}

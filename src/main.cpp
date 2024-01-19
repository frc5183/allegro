#include <iostream>
#include <libfreenect.hpp>
#include <networktables/NetworkTableInstance.h>
#include <Logger.hpp>
#include <Config.hpp>
using namespace Allegro;
namespace Allegro
{
class Kinect : public Freenect::FreenectDevice
{
  public:
    Kinect(freenect_context *_ctx, int _index) : Freenect::FreenectDevice(_ctx, _index) {}
    void VideoCallback(void *_rgb, uint32_t timestamp) {}
    void DepthCallback(void *_depth, uint32_t timestamp) {}
};
}
int main() {
  Logger logger;
  logger.log("INFO", "Starting");
  //TODO: Fix the Logger to allow for more types and use std::string and not cstring, but man, screw const char* -> char* being blocked, hate that crap
  std:: cout << "[TEAM] " << Allegro::team << std::endl;
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

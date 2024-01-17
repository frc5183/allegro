#include <iostream>
#include <libfreenect.hpp>
#include <networktables/NetworkTableInstance.h>
int main() {
  std::cout << "Hello, World!" << std::endl;
  auto inst = nt::NetworkTableInstance::GetDefault();
  std::cout << "Hey, we made NetworkTables!" << std::endl;
  return 0;
}
class Mutex
{
  public:
    Mutex() {}
    void lock() {}
    void unlock() {}
};

class Kinect : public Freenect::FreenectDevice
{
  public:
    float getColorClipDistanceFront_off() { return 0; }
    float getColorClipDistanceBack_off() { return 0; }
    float getColorCLipDistanceFront() { return 0; }
    float getColorClipDistanceFront(float hello) { return 0; }
    float getColorClipDistanceBack() { return 0; }
    float setColorClipDistanceBack(float hello) { return 0; }
    Kinect(freenect_context *_ctx, int _index) : Freenect::FreenectDevice(_ctx, _index) { }
    void VideoCallback(void *_rgb, uint32_t timestamp) {}
    void DepthCallback(void *_depth, uint32_t tmestamp) {}

};

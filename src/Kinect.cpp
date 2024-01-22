#include <Kinect.hpp>
using namespace Allegro;
namespace Allegro
{
  Kinect::Kinect(freenect_context *_ctx, int _index) : Freenect::FreenectDevice(_ctx, _index) {}
  void Kinect::VideoCallback(void *_rgb, uint32_t timestamp) {}
  void Kinect::DepthCallback(void *_depth, uint32_t timestamp) {}
}


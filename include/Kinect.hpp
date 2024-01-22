#pragma once
#include <libfreenect.hpp>
namespace Allegro
{
class Kinect : public Freenect::FreenectDevice
{
  public:
    Kinect(freenect_context *_ctx, int _index);
    void VideoCallback(void *_rgb, uint32_t timestamp);
    void DepthCallback(void *_depth, uint32_t timestamp);
};
}

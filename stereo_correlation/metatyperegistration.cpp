#include "metatyperegistration.h"

// the classes themselves
#include "imagecamera2d.h"
#include "reticle.h"

namespace Stereo
{
    MetatypeRegistration::MetatypeRegistration()
    {

    }

    void MetatypeRegistration::doRegistration()
    {
      // Our metatypes
      qRegisterMetaType<ImageCamera2d>();
      qRegisterMetaType<Reticle>();
    }
}

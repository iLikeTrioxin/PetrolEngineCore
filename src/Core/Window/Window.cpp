#include "PCH.h"

#include "Core/Window/Window.h"

namespace PetrolEngine {

    float WindowI::getAspectRatio() const {
        return ((float) windowData.width) / ((float)windowData.height);
    }
    
}
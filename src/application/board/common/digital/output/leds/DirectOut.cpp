/*

Copyright 2015-2019 Igor Petrovic

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#include <inttypes.h>
#include "interface/digital/output/leds/DataTypes.h"

namespace Board
{
    uint8_t getRGBaddress(uint8_t rgbID, rgbIndex_t index)
    {
        return rgbID*3+static_cast<uint8_t>(index);
    }

    uint8_t getRGBID(uint8_t ledID)
    {
        uint8_t result = ledID / 3;

        if (result >= MAX_NUMBER_OF_RGB_LEDS)
            return MAX_NUMBER_OF_RGB_LEDS-1;
        else
            return result;
    }
}
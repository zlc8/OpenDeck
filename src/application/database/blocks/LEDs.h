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

#pragma once

typedef enum
{
    dbSection_leds_global,
    dbSection_leds_activationID,
    dbSection_leds_rgbEnable,
    dbSection_leds_controlType,
    dbSection_leds_activationValue,
    dbSection_leds_midiChannel,
    DB_SECTIONS_LEDS
} dbSection_leds_t;
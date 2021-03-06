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

#include "board/Board.h"
#include "board/common/uart/Variables.h"
#include "board/common/indicators/Variables.h"

namespace Board
{
    bool uartWriteOD(uint8_t channel, USBMIDIpacket_t& USBMIDIpacket, odPacketType_t packetType)
    {
        if (channel >= UART_INTERFACES)
            return false;

        uartWrite(channel, static_cast<uint8_t>(packetType));
        uartWrite(channel, USBMIDIpacket.Event);
        uartWrite(channel, USBMIDIpacket.Data1);
        uartWrite(channel, USBMIDIpacket.Data2);
        uartWrite(channel, USBMIDIpacket.Data3);
        uartWrite(channel, USBMIDIpacket.Event ^ USBMIDIpacket.Data1 ^ USBMIDIpacket.Data2 ^ USBMIDIpacket.Data3);

        return true;
    }

    bool uartReadOD(uint8_t channel, USBMIDIpacket_t& USBMIDIpacket, odPacketType_t& packetType)
    {
        using namespace Board::detail;

        packetType = odPacketType_t::packetInvalid;

        if (channel >= UART_INTERFACES)
            return false;

        if (RingBuffer_GetCount(&rxBuffer[channel]) >= 6)
        {
            uint8_t data = 0;
            uartRead(channel, data);
            uint8_t dataXOR = 0;

            if ((data == OD_FORMAT_MIDI_DATA_START) || (data == OD_FORMAT_MIDI_DATA_MASTER_START))
            {
                packetType = static_cast<odPacketType_t>(data);

                //start of frame, read rest of the packet
                for (int i=0; i<5; i++)
                {
                    uartRead(channel, data);

                    switch(i)
                    {
                        case 0:
                        USBMIDIpacket.Event = data;
                        break;

                        case 1:
                        USBMIDIpacket.Data1 = data;
                        break;

                        case 2:
                        USBMIDIpacket.Data2 = data;
                        break;

                        case 3:
                        USBMIDIpacket.Data3 = data;
                        break;

                        case 4:
                        //xor byte, do nothing
                        break;
                    }
                }

                //error check
                dataXOR = USBMIDIpacket.Event ^ USBMIDIpacket.Data1 ^ USBMIDIpacket.Data2 ^ USBMIDIpacket.Data3;

                return (dataXOR == data);
            }
            else if (data == OD_FORMAT_INT_DATA_START)
            {
                uint8_t cmd = 0;
                uartRead(channel, cmd);

                //ignore the rest of the buffer
                for (int i=0; i<4; i++)
                    uartRead(channel, data);

                switch(static_cast<odFormatCMD_t>(cmd))
                {
                    case odFormatCMD_t::cmdFwUpdated:
                    ledFlashStartup(true);
                    break;

                    case odFormatCMD_t::cmdFwNotUpdated:
                    ledFlashStartup(false);
                    break;

                    case odFormatCMD_t::cmdBtldrReboot:
                    reboot(rebootType_t::rebootBtldr);
                    break;

                    #ifndef USB_SUPPORTED
                    case odFormatCMD_t::cmdUsbStateConnected:
                    usbLinkState = true;
                    break;

                    case odFormatCMD_t::cmdUsbStateNotConnected:
                    usbLinkState = false;
                    break;
                    #endif

                    default:
                    break;
                }

                packetType = odPacketType_t::packetIntCMD;
                return true;
            }
        }

        return false;
    }
}
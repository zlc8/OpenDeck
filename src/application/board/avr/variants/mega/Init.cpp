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
#include "pins/Pins.h"
#include "board/common/constants/LEDs.h"
#include "board/common/uart/ODformat.h"
#include "core/src/HAL/avr/PinManipulation.h"
#include "core/src/HAL/avr/adc/ADC.h"

namespace Board
{
    namespace detail
    {
        void initPins()
        {
            setInput(DI_1_PORT, DI_1_PIN);
            setHigh(DI_1_PORT, DI_1_PIN);

            setInput(DI_2_PORT, DI_2_PIN);
            setHigh(DI_2_PORT, DI_2_PIN);

            setInput(DI_3_PORT, DI_3_PIN);
            setHigh(DI_3_PORT, DI_3_PIN);

            setInput(DI_4_PORT, DI_4_PIN);
            setHigh(DI_4_PORT, DI_4_PIN);

            setInput(DI_5_PORT, DI_5_PIN);
            setHigh(DI_5_PORT, DI_5_PIN);

            setInput(DI_6_PORT, DI_6_PIN);
            setHigh(DI_6_PORT, DI_6_PIN);

            setInput(DI_7_PORT, DI_7_PIN);
            setHigh(DI_7_PORT, DI_7_PIN);

            setInput(DI_8_PORT, DI_8_PIN);
            setHigh(DI_8_PORT, DI_8_PIN);

            setInput(DI_9_PORT, DI_9_PIN);
            setHigh(DI_9_PORT, DI_9_PIN);

            setInput(DI_10_PORT, DI_10_PIN);
            setHigh(DI_10_PORT, DI_10_PIN);

            setInput(DI_11_PORT, DI_11_PIN);
            setHigh(DI_11_PORT, DI_11_PIN);

            setInput(DI_12_PORT, DI_12_PIN);
            setHigh(DI_12_PORT, DI_12_PIN);

            setInput(DI_13_PORT, DI_13_PIN);
            setHigh(DI_13_PORT, DI_13_PIN);

            setInput(DI_14_PORT, DI_14_PIN);
            setHigh(DI_14_PORT, DI_14_PIN);

            setInput(DI_15_PORT, DI_15_PIN);
            setHigh(DI_15_PORT, DI_15_PIN);

            setInput(DI_16_PORT, DI_16_PIN);
            setHigh(DI_16_PORT, DI_16_PIN);

            setInput(DI_17_PORT, DI_17_PIN);
            setHigh(DI_17_PORT, DI_17_PIN);

            setInput(DI_18_PORT, DI_18_PIN);
            setHigh(DI_18_PORT, DI_18_PIN);

            setInput(DI_19_PORT, DI_19_PIN);
            setHigh(DI_19_PORT, DI_19_PIN);

            setInput(DI_20_PORT, DI_20_PIN);
            setHigh(DI_20_PORT, DI_20_PIN);

            setInput(DI_21_PORT, DI_21_PIN);
            setHigh(DI_21_PORT, DI_21_PIN);

            setInput(DI_22_PORT, DI_22_PIN);
            setHigh(DI_22_PORT, DI_22_PIN);

            setInput(DI_23_PORT, DI_23_PIN);
            setHigh(DI_23_PORT, DI_23_PIN);

            setInput(DI_24_PORT, DI_24_PIN);
            setHigh(DI_24_PORT, DI_24_PIN);

            setInput(DI_25_PORT, DI_25_PIN);
            setHigh(DI_25_PORT, DI_25_PIN);

            setInput(DI_26_PORT, DI_26_PIN);
            setHigh(DI_26_PORT, DI_26_PIN);

            setInput(DI_27_PORT, DI_27_PIN);
            setHigh(DI_27_PORT, DI_27_PIN);

            setInput(DI_28_PORT, DI_28_PIN);
            setHigh(DI_28_PORT, DI_28_PIN);

            setInput(DI_29_PORT, DI_29_PIN);
            setHigh(DI_29_PORT, DI_29_PIN);

            setInput(DI_30_PORT, DI_30_PIN);
            setHigh(DI_30_PORT, DI_30_PIN);

            setInput(DI_31_PORT, DI_31_PIN);
            setHigh(DI_31_PORT, DI_31_PIN);

            setInput(DI_32_PORT, DI_32_PIN);
            setHigh(DI_32_PORT, DI_32_PIN);


            setOutput(DO_1_PORT, DO_1_PIN);
            EXT_LED_OFF(DO_1_PORT, DO_1_PIN);

            setOutput(DO_2_PORT, DO_2_PIN);
            EXT_LED_OFF(DO_2_PORT, DO_2_PIN);

            setOutput(DO_3_PORT, DO_3_PIN);
            EXT_LED_OFF(DO_3_PORT, DO_3_PIN);

            setOutput(DO_4_PORT, DO_4_PIN);
            EXT_LED_OFF(DO_4_PORT, DO_4_PIN);

            setOutput(DO_5_PORT, DO_5_PIN);
            EXT_LED_OFF(DO_5_PORT, DO_5_PIN);

            setOutput(DO_6_PORT, DO_6_PIN);
            EXT_LED_OFF(DO_6_PORT, DO_6_PIN);

            setOutput(DO_7_PORT, DO_7_PIN);
            EXT_LED_OFF(DO_7_PORT, DO_7_PIN);

            setOutput(DO_8_PORT, DO_8_PIN);
            EXT_LED_OFF(DO_8_PORT, DO_8_PIN);

            setOutput(DO_9_PORT, DO_9_PIN);
            EXT_LED_OFF(DO_9_PORT, DO_9_PIN);

            setOutput(DO_10_PORT, DO_10_PIN);
            EXT_LED_OFF(DO_10_PORT, DO_10_PIN);

            setOutput(DO_11_PORT, DO_11_PIN);
            EXT_LED_OFF(DO_11_PORT, DO_11_PIN);

            setOutput(DO_12_PORT, DO_12_PIN);
            EXT_LED_OFF(DO_12_PORT, DO_12_PIN);

            setOutput(DO_13_PORT, DO_13_PIN);
            EXT_LED_OFF(DO_13_PORT, DO_13_PIN);

            setOutput(DO_14_PORT, DO_14_PIN);
            EXT_LED_OFF(DO_14_PORT, DO_14_PIN);

            setOutput(DO_15_PORT, DO_15_PIN);
            EXT_LED_OFF(DO_15_PORT, DO_15_PIN);

            setOutput(DO_16_PORT, DO_16_PIN);
            EXT_LED_OFF(DO_16_PORT, DO_16_PIN);


            setInput(AI_1_PORT, AI_1_PIN);
            setLow(AI_1_PORT, AI_1_PIN);

            setInput(AI_2_PORT, AI_2_PIN);
            setLow(AI_2_PORT, AI_2_PIN);

            setInput(AI_3_PORT, AI_3_PIN);
            setLow(AI_3_PORT, AI_3_PIN);

            setInput(AI_4_PORT, AI_4_PIN);
            setLow(AI_4_PORT, AI_4_PIN);

            setInput(AI_5_PORT, AI_5_PIN);
            setLow(AI_5_PORT, AI_5_PIN);

            setInput(AI_6_PORT, AI_6_PIN);
            setLow(AI_6_PORT, AI_6_PIN);

            setInput(AI_7_PORT, AI_7_PIN);
            setLow(AI_7_PORT, AI_7_PIN);

            setInput(AI_8_PORT, AI_8_PIN);
            setLow(AI_8_PORT, AI_8_PIN);

            setInput(AI_9_PORT, AI_9_PIN);
            setLow(AI_9_PORT, AI_9_PIN);

            setInput(AI_10_PORT, AI_10_PIN);
            setLow(AI_10_PORT, AI_10_PIN);

            setInput(AI_11_PORT, AI_11_PIN);
            setLow(AI_11_PORT, AI_11_PIN);

            setInput(AI_12_PORT, AI_12_PIN);
            setLow(AI_12_PORT, AI_12_PIN);

            setInput(AI_13_PORT, AI_13_PIN);
            setLow(AI_13_PORT, AI_13_PIN);

            setInput(AI_14_PORT, AI_14_PIN);
            setLow(AI_14_PORT, AI_14_PIN);

            setInput(AI_15_PORT, AI_15_PIN);
            setLow(AI_15_PORT, AI_15_PIN);

            setInput(AI_16_PORT, AI_16_PIN);
            setLow(AI_16_PORT, AI_16_PIN);
        }

        void initAnalog()
        {
            adcConf adcConfiguration;

            adcConfiguration.prescaler = ADC_PRESCALER_128;
            adcConfiguration.vref = ADC_VREF_AVCC;

            setUpADC(adcConfiguration);
            setADCchannel(AI_1_PIN);

            for (int i=0; i<3; i++)
                getADCvalue();  //few dummy reads to init ADC

            adcInterruptEnable();
            startADCconversion();
        }

        void configureTimers()
        {
            //clear timer0 conf
            TCCR0A = 0;
            TCCR0B = 0;
            TIMSK0 = 0;

            //clear timer1 conf
            TCCR1A = 0;
            TCCR1B = 0;

            //clear timer3 conf
            TCCR3A = 0;
            TCCR3B = 0;

            //set timer0 to ctc, used for millis/led matrix
            TCCR0A |= (1<<WGM01);           //CTC mode
            TCCR0B |= (1<<CS01)|(1<<CS00);  //prescaler 64
            OCR0A = 124;                    //500us
            TIMSK0 |= (1<<OCIE0A);          //compare match interrupt
        }
    }

    void ledFlashStartup(bool fwUpdated)
    {
        using namespace Board::detail;

        //there are no indicator leds on atmega2560
        //instead, send special command to USB link which will display indicator led animation
        uartWrite(UART_USB_LINK_CHANNEL, OD_FORMAT_INT_DATA_START);

        if (fwUpdated)
            uartWrite(UART_USB_LINK_CHANNEL, static_cast<uint8_t>(odFormatCMD_t::cmdFwUpdated));
        else
            uartWrite(UART_USB_LINK_CHANNEL, static_cast<uint8_t>(odFormatCMD_t::cmdFwNotUpdated));

        uartWrite(UART_USB_LINK_CHANNEL, 0x00);
        uartWrite(UART_USB_LINK_CHANNEL, 0x00);
        uartWrite(UART_USB_LINK_CHANNEL, 0x00);
        uartWrite(UART_USB_LINK_CHANNEL, 0x00);
    }

    bool startUpAnimation()
    {
        return false;
    }
}
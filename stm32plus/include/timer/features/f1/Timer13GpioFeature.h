/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 *
 * THIS IS AN AUTOMATICALLY GENERATED FILE - DO NOT EDIT!
 */

#pragma once

// ensure the MCU series is correct
#ifndef STM32PLUS_F1
#error This class can only be used with the STM32F1 series
#endif

namespace stm32plus {

  struct TIM13_CH1_IN {

    /**
     * Initialise GPIO pins for this timer GPIO mode
     * @param remap The remap level (none, partial1, partial2, full)
     */
 
    static void initialise(TimerGpioRemapLevel remap) {

      static GPIO_TypeDef *const ports[4]={ GPIOA,nullptr,nullptr,GPIOF };
      static const uint16_t pins[4]={ GPIO_Pin_6,0,0,GPIO_Pin_8 };

      GpioPinInitialiser::initialise(ports[remap],pins[remap],Gpio::INPUT,(GPIOSpeed_TypeDef)PeripheralTraits<PERIPHERAL_TIMER13>::GPIO_SPEED,Gpio::PUPD_NONE); 
    }
  };

  struct TIM13_CH1_OUT {

    /**
     * Initialise GPIO pins for this timer GPIO mode
     * @param remap The remap level (none, partial1, partial2, full)
     */
 
    static void initialise(TimerGpioRemapLevel remap) {

      static GPIO_TypeDef *const ports[4]={ GPIOA,nullptr,nullptr,GPIOF };
      static const uint16_t pins[4]={ GPIO_Pin_6,0,0,GPIO_Pin_8 };

      GpioPinInitialiser::initialise(ports[remap],pins[remap],Gpio::ALTERNATE_FUNCTION,(GPIOSpeed_TypeDef)PeripheralTraits<PERIPHERAL_TIMER13>::GPIO_SPEED,Gpio::PUPD_NONE,Gpio::PUSH_PULL,PeripheralTraits<PERIPHERAL_TIMER13>::GPIO_AF); 
    }
  };

  /**
   * Timer feature to enable any number of the GPIO alternate function outputs.
   * All remap levels are supported. An example declaration could be:
   *
   * Timer13GpioFeature<REMAP_NONE,TIM13_CH1_OUT>
   */

  template<TimerGpioRemapLevel TRemapLevel,class TF0=NullTimerGpio>
  struct Timer13GpioFeature;


  template<class TF0>
  struct Timer13GpioFeature<TIMER_REMAP_NONE,TF0> : public TimerFeatureBase {
    Timer13GpioFeature(Timer& timer) : TimerFeatureBase(timer) {
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
      TF0::initialise(TIMER_REMAP_NONE);
    }
  };


  template<class TF0>
  struct Timer13GpioFeature<TIMER_REMAP_FULL,TF0> : public TimerFeatureBase {
    Timer13GpioFeature(Timer& timer) : TimerFeatureBase(timer) {
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
      GPIO_PinRemapConfig(GPIO_Remap_TIM13,ENABLE);
      TF0::initialise(TIMER_REMAP_FULL);
    }
  };
}

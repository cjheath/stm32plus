/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


namespace stm32plus {

  /**
   * Convenience template to initialise an I2S pin package
   */

  template<class TPinPackage,class TPeripheralTraits>
  class I2SPinInitialiser {
    public:
      static void initialise(uint16_t mode,uint16_t mclkOutput);
  };


  /**
   * Initialise the pin package that we were parameterised with
   */

  template<class TPinPackage,class TPeripheralTraits>
  inline void I2SPinInitialiser<TPinPackage,TPeripheralTraits>::initialise(uint16_t mode,uint16_t mclkOutput) {

    if(mode==I2S_Mode_MasterTx || mode==I2S_Mode_MasterRx) {

      // WS/CK are AF for all master modes

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_WS,
                                     TPinPackage::Pin_WS,
                                     Gpio::ALTERNATE_FUNCTION,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL,
                                     TPeripheralTraits::GPIO_AF);

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_CK,
                                     TPinPackage::Pin_CK,
                                     Gpio::ALTERNATE_FUNCTION,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL,
                                     TPeripheralTraits::GPIO_AF);

      // MCLK is AF only for master mode and if selected

      if(mclkOutput==I2S_MCLKOutput_Enable)
        GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_MCLK,
                                       TPinPackage::Pin_MCLK,
                                       Gpio::ALTERNATE_FUNCTION,
                                       (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                       Gpio::PUPD_NONE,
                                       Gpio::PUSH_PULL,
                                       TPeripheralTraits::GPIO_AF);
    }
    else {
      // WS/CK are input floating for all slave modes

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_WS,
                                     TPinPackage::Pin_WS,
                                     Gpio::INPUT,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL);

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_CK,
                                     TPinPackage::Pin_CK,
                                     Gpio::INPUT,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL);
    }

    if(mode==I2S_Mode_MasterTx || mode==I2S_Mode_SlaveTx) {

      // SD is AF for all transmitters

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_SD,
                                     TPinPackage::Pin_SD,
                                     Gpio::ALTERNATE_FUNCTION,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL,
                                     TPeripheralTraits::GPIO_AF);
    }
    else {

      // SD is input for all receivers

      GpioPinInitialiser::initialise((GPIO_TypeDef *)TPinPackage::Port_SD,
                                     TPinPackage::Pin_SD,
                                     Gpio::INPUT,
                                     (GPIOSpeed_TypeDef)TPeripheralTraits::GPIO_SPEED,
                                     Gpio::PUPD_NONE,
                                     Gpio::PUSH_PULL);
    }
  }
}

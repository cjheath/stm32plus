/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#include "config/stm32plus.h"
#include "config/exti.h"


using namespace stm32plus;


// static initialiser for the hack that forces the IRQ handlers to be linked

template<> ExtiInterruptEnabler<3>::FPTR ExtiInterruptEnabler<3>::_forceLinkage=nullptr;
template<> Observable *ExtiPeripheral<EXTI_Line3>::_extiInstance=nullptr;


#if defined(USE_EXTI3_INTERRUPT)

extern "C" {

  void __attribute__ ((interrupt("IRQ"))) EXTI3_IRQHandler(void) {

    if(EXTI_GetITStatus(EXTI_Line3)!=RESET) {
        Exti3::_extiInstance->notifyObservers(ObservableEvent::EXTI_Triggered,(void *)3);
        EXTI_ClearITPendingBit(EXTI_Line3);
    }
  }
}

#endif

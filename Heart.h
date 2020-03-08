/*
  Heart.h - Library for flashing a beating heart.
  Created by Marcos Placona, July 26, 2019.
  MIT License
*/
#ifndef Heart_h
#define Heart_h

#include "Arduino.h"

class Heart 
{
    public:
      // Constructor
      Heart(int pin = 13, float tempo = 1.0);

      // Methods
      void beat();
      void beatForPeriod(int seconds);
    private:
      uint8_t _pin;
      long _tempo;
        
      // Methods
      void beatSequence();
};

#endif //  Heart_h
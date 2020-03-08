#include <Heart.h>

const long heartBeatArray[] = { 50, 100, 15, 1200};
int heartBeatIndex = 1;   // this initialization is important or it starts on the "wrong foot"
long prevMillis;


Heart::Heart(int pin, float tempo)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
    _tempo = tempo; 
}

void Heart::beatForPeriod(int seconds){
    uint32_t period = seconds * 1000L;
    for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
        beatSequence();
    }
}

// Private Methods
void Heart::beatSequence(){
    if ((millis() - prevMillis) > (long)(heartBeatArray[heartBeatIndex] * _tempo)){
        heartBeatIndex++;
        if (heartBeatIndex > 3) heartBeatIndex = 0;

        if ((heartBeatIndex % 2) == 0){ 
            digitalWrite(_pin, HIGH); 
            delay((int)heartBeatArray[heartBeatIndex]) ;   
            digitalWrite(_pin, LOW); 
        }
        heartBeatIndex++;

        prevMillis = millis();
    }
}
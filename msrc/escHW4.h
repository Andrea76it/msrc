#ifndef ESCHW4_H
#define ESCHW4_H

#define ESCHW4_RPM 0
#define ESCHW4_VOLTAGE 1
#define ESCHW4_CURRENT 2
#define ESCHW4_TEMPFET 3
#define ESCHW4_TEMPBEC 4

#include <Arduino.h>
#include "smartport.h"

class EscHW4Interface : public AbstractDevice
{
private:
    Stream &serial_;
    uint8_t alphaRpm_, alphaVolt_, alphaCurr_, alphaTemp_; 
    float value_[5] = {0};
    float calcTempHW(uint16_t tempRaw);
    float calcCurrHW(uint16_t currentRaw);
    uint8_t setCellCount(float voltage); 
    uint8_t cellCount_ = 255;
protected:
public:
    EscHW4Interface(Stream &serial, uint8_t alphaRpm, uint8_t alphaVolt, uint8_t alphaCurr, uint8_t alphaTemp);
    bool update();
    float read(uint8_t index);
};

#endif
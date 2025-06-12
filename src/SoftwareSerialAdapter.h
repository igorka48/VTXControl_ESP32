// SoftwareSerialAdapter.h
//
// Adapter for EspSoftwareSerial library for VTXControl class
// Extends the EspSoftwareSerial with the functionality from
// SoftwareSerialWithHalfDuplex

#ifndef __SoftwareSerialAdapter_h
#define __SoftwareSerialAdapter_h

#include "SoftwareSerial.h"
#include <stdint.h>

enum sswhdErrors {
  sswhdNoErrors = 0x00,
  sswhdIsNotListening = 0x01,
  sswhdBufferIsEmpty = 0x02,
  sswhdTxDelayIsZero = 0x04,
  sswhdRXDelayStopBitNotSet = 0x08,
};

class SoftwareSerialAdapter : public SoftwareSerial {
public:
  SoftwareSerialAdapter(int8_t rxPin, int8_t txPin = -1, bool invert = false)
      : SoftwareSerial(rxPin, txPin, invert) {}

  void
  begin(uint32_t baud,
        EspSoftwareSerial::Config config = EspSoftwareSerial::SWSERIAL_8N1);

  sswhdErrors getErrors();
  void clearErrors();

  long getSpeed();
  EspSoftwareSerial::Config getConfiguration();

  void writeDummyByte();

  void dumpReceiveBuffer();

private:
  long _speed;
  EspSoftwareSerial::Config _configuration;
  sswhdErrors _errors = sswhdErrors::sswhdNoErrors;
};

#endif // __SoftwareSerialAdapter_h

#include <Arduino.h>

#include <SoftwareSerial.h>

#include "SoftwareSerialAdapter.h"

void SoftwareSerialAdapter::begin(
    uint32_t baud,
    EspSoftwareSerial::Config config /*= EspSoftwareSerial::SWSERIAL_8N1*/
) {
  _configuration = config;
  _speed = baud;
  SoftwareSerial::begin(baud, config);
}

void SoftwareSerialAdapter::clearErrors() {
  _errors = sswhdErrors::sswhdNoErrors;
}

sswhdErrors SoftwareSerialAdapter::getErrors() { return _errors; }

long SoftwareSerialAdapter::getSpeed() { return _speed; }

EspSoftwareSerial::Config SoftwareSerialAdapter::getConfiguration() {
  return _configuration;
}

void SoftwareSerialAdapter::writeDummyByte() {
  Serial.println("<<< stub: SoftwareSerialAdapter::writeDummyByte() >>>");
}

void SoftwareSerialAdapter::dumpReceiveBuffer() {
  Serial.println("<<< stub: SoftwareSerialAdapter::dumpReceiveBuffer() >>>");
}

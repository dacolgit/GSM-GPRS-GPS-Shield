#ifndef SIMCOM900_H
#define SIMCOM900_H
#if defined MEGA || defined UNO
#include <SoftwareSerial.h>
#endif
#include "HWSerial.h"
#include "GSM.h"
class SIMCOM900 : public virtual GSM {

private:
     int configandwait(char* pin);
     int setPIN(char *pin);
     int changeNSIPmode(char);

public:
     SIMCOM900();
     ~SIMCOM900();
     int getCCI(char* cci);
     int getIMEI(char* imei);
     int sendSMS(const char* to, const char* msg);
     boolean readSMS(char* msg, int msglength, char* number, int nlength);
     boolean readCall(char* number, int nlength);
     boolean call(char* number, unsigned int milliseconds);
     char forceON();
     virtual int read(char* result, int resultlength);
     virtual uint8_t read();
     virtual int available();
     int readCellData(int &mcc, int &mnc, long &lac, long &cellid);
     void SimpleRead();
     void WhileSimpleRead();
     void SimpleWrite(char *comm);
     void SimpleWrite(char const *comm);
     void SimpleWrite(int comm);
#if defined MEGA || defined UNO
     void SimpleWrite(const __FlashStringHelper *pgmstr);
#endif
     void SimpleWriteln(char *comm);
     void SimpleWriteln(char const *comm);
#if defined MEGA || defined UNO
     void SimpleWriteln(const __FlashStringHelper *pgmstr);
#endif
     void SimpleWriteln(int comm);
};

extern SIMCOM900 gsm;

#endif


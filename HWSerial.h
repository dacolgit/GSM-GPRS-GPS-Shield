//#define MEGA

#ifndef _HWSERIAL_H_
#define _HWSERIAL_H_

//#define UNO
//#define MEGA
#define WINDOWS_GALILEO


#include "Arduino.h"
#if defined MEGA || defined UNO
#include "Streaming.h"
#endif
#include <inttypes.h>
#ifdef WINDOWS_GALILEO
#include <string>

enum base_t : int {
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16,
};
#endif


class HWSerial {
#ifdef MEGA
private:
     int write_error;
     size_t printNumber(unsigned long, uint8_t);
     size_t printFloat(double, uint8_t);

public:
     HWSerial();

     //bool listen();
     void end();
     /*
     bool isListening();
     bool overflow();
     */
     int peek();
     virtual void begin(long baud_rate);

     virtual size_t write(uint8_t byte);
     size_t write(const char *str) {
          return write((const uint8_t *)str, strlen(str));
     }
     virtual size_t write(const uint8_t *buffer, size_t size);

     virtual int read();
     virtual int available();
     virtual void flush();

     size_t print(const __FlashStringHelper *);
     size_t print(const String &);
     size_t print(const char[]);
     size_t print(char);
     size_t print(unsigned char, int = DEC);
     size_t print(int, int = DEC);
     size_t print(unsigned int, int = DEC);
     size_t print(long, int = DEC);
     size_t print(unsigned long, int = DEC);
     size_t print(double, int = 2);


     size_t println(const __FlashStringHelper *);
     size_t println(const String &s);
     size_t println(const char[]);
     size_t println(char);
     size_t println(unsigned char, int = DEC);
     size_t println(int, int = DEC);
     size_t println(unsigned int, int = DEC);
     size_t println(long, int = DEC);
     size_t println(unsigned long, int = DEC);
     size_t println(double, int = 2);

     size_t println(void);

     int getString( char *pre_string, char *post_string, char *buffer, int length);
     boolean find(char *target);
     boolean  findUntil(char *target, char *terminate);

#endif

#ifdef WINDOWS_GALILEO
private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);

    HANDLE hSerial1;      /* Handle to Serial Port */
    DCB config1;
    char outputData[30];
    char inputData[50];

    wchar_t portName1[5];

public:
    HWSerial();

    //bool listen();
    void end();
    /*
    bool isListening();
    bool overflow();
    */
    int peek();
    virtual void begin(int baud_rate);

    virtual size_t write(uint8_t byte);
    size_t write(const char *str) { return write((const uint8_t *)str, strlen(str)); }
    virtual size_t write(const uint8_t *buffer, size_t size);

    virtual int read();
    virtual int available();
    virtual void flush();

    size_t print(const std::string &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);

    size_t println(const std::string &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);

    size_t println(void);

    int getString(char *pre_string, char *post_string, char *buffer, int length);
    boolean find(char *target);
    boolean  findUntil(char *target, char *terminate);
#endif

};
#endif
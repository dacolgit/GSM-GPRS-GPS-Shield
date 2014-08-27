// Main.cpp : Defines the entry point for the console application.
//
// Sample application for sending SMS using GSM library - dacol 07/2014
//

#include "stdafx.h"
#include "arduino.h"
#include "SIM900.h"
#include "sms.h"

SMSGSM sms;

// Helper function for logging to debug output and the console
void CustomLogging(char* str)
{
	OutputDebugStringA(str); // for VS Output
	printf(str); // for commandline output
}

int _tmain(int argc, _TCHAR* argv[])
{
	return RunArduinoSketch();
}

void setup()
{
	// TODO: Add your code here

    CustomLogging("Init GSM module.\n");
    gsm.begin(19200);
}

void loop()
{
    // Add your phone number
	char phoneNumber[] = { "+49151123456" };
    char smstext[] = { "Hi, This message was sent to you By Galileo" };
    int smsCounter = 0;

    CustomLogging("Sending sms.\n");

    if (smsCounter < 1)
    {
        sms.SendSMS(phoneNumber, smstext);
        smsCounter++;
    }

    CustomLogging("sms sent.\n");
}



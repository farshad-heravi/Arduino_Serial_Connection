#ifndef ARDUINOCONNECTION_H
#define ARDUINOCONNECTION_H

#include <SerialPort.h>
#include <SerialStream.h>
#include <iostream>

class ArduinoConnection {
    private:
        LibSerial::SerialStream arduino;   // arduino connection
        
    public:
        ArduinoConnection(std::string port, int baudrate, int timeout);
        ~ArduinoConnection();
        bool is_open();
        void write(const std::vector<double>& values);
        void write(const std::string data_string);
        std::string read();
};

#endif // ARDUINOCONNECTION_H
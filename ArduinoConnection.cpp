#include "ArduinoConnection.h"
#include <chrono>

ArduinoConnection::ArduinoConnection(std::string port, int baudrate, int timeout)
    : arduino(port)  // Open the serial port
{
    // Set serial parameters
    if (baudrate==115200)
        arduino.SetBaudRate(LibSerial::BaudRate::BAUD_115200);  // Correct baud rate enumeration
    arduino.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);  // Correct character size
    arduino.SetParity(LibSerial::Parity::PARITY_NONE);  // Correct parity
    arduino.SetStopBits(LibSerial::StopBits::STOP_BITS_1);  // Correct stop bits
    arduino.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);  // Correct flow control
}

bool ArduinoConnection::is_open(){
    // Check if the port is open
    if (arduino.IsOpen()) 
        return  true;
    else
        return false;
}

void ArduinoConnection::write(const std::vector<double>& values){
    std::string data_string = "";
    for(int i=0; i<values.size(); i++) {
        if (i!=0)
            data_string += ",";
        data_string += std::to_string(values[i]);
    }
    // std::cout << data_string << std::endl;
    arduino << data_string << std::endl;
}

void ArduinoConnection::write(const std::string data_string){
    arduino << data_string << std::endl;
    // std::cout << data_string << std::endl;
    
    
    const std::string expected_response = "Received.";  // Define the expected response
    std::string response;
    bool received = false;

    // Start the timeout timer
    auto start = std::chrono::steady_clock::now();
    const auto timeout = std::chrono::seconds(1); // Set timeout duration
    while (!received) {
        // Check for timeout
        if (std::chrono::steady_clock::now() - start > timeout) {
            std::cerr << "Timeout waiting for response." << std::endl;
            break;
        }

        response = read();      // Read response from Arduino

        if (response == expected_response) {        // Check if response matches the expected value
            received = true;
        }
    }
    if (!received) {
        std::cerr << "Failed to receive acknowledgment from Arduino." << std::endl;
    }
}

std::string ArduinoConnection::read(){
    std::string response;
    if (arduino.IsDataAvailable()) { // Ensure data is available before reading
        std::getline(arduino, response);
        response.erase(response.find_last_not_of(" \n\r\t") + 1); // Trim whitespace
    }
    return response;
}

ArduinoConnection::~ArduinoConnection(){
    arduino.Close();
}

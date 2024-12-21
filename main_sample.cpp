#include <iostream>
#include "ArduinoConnection.h"
#include <chrono>
#include <thread>

int main(){
    ArduinoConnection arduino("/dev/ttyACM0", 115200, 2000);

    std::cout << "Arduino is Open: " << arduino.is_open() << std::endl;
    std::vector<double> vals = {1.0, 2, 3};
    
    bool led_state = false;
    std::string str_on = "LED_BUILTIN=1";
    std::string str_off = "LED_BUILTIN=0";
    
    
    // arduino.write(vals);
    // arduino.write(str);


    int iteration = 0;
    while (iteration < 10000) {
        // Record the start time
        auto start = std::chrono::high_resolution_clock::now();
        
        if (!led_state){
            arduino.write(str_on);
            led_state = !led_state;
        } else {
            arduino.write(str_off);
            led_state = !led_state;
        }

        auto end = std::chrono::high_resolution_clock::now();       // Record the end time

        std::chrono::duration<double> elapsed = end - start;        // Calculate the elapsed time
        std::cout << "Time taken for iteration " << iteration + 1 << ": " 
                  << 1000. * elapsed.count() << " ms" << std::endl;

        ++iteration;
    }
    
    return 0;
}
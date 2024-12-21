# ArduinoConnection

## Overview
The **ArduinoConnection** project provides a C++-based class for handling serial communication between a PC and an Arduino board. This class is designed to simplify sending and receiving data, making it easier to control Arduino devices from a PC. The class supports sending string commands and numeric data efficiently, achieving communication rates of up to **250 Hz** in benchmarks.

## Features
- **Simple API**: Easy-to-use interface for serial communication.
- **High Performance**: Supports communication rates of up to 250 Hz.
- **Error Handling**: Includes basic mechanisms for acknowledging received commands and handling timeouts.
- **Flexible Data Types**: Supports both string and numeric data transmission.

## File Structure
- `ArduinoConnection.h`: Header file defining the `ArduinoConnection` class.
- `ArduinoConnection.cpp`: Implementation of the `ArduinoConnection` class.
- `main_sample.cpp`: Sample code demonstrating how to use the `ArduinoConnection` class to control the built-in LED on an Arduino.

## Requirements
- **Dependencies**:
  - [LibSerial](https://github.com/crayzeewulf/libserial): A cross-platform C++ library for serial port communication.
- **Hardware**:
  - An Arduino board connected via USB.

## Getting Started

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/ArduinoConnection.git
   cd ArduinoConnection
   ```
2. Install the `LibSerial` library by following its [installation instructions](https://github.com/crayzeewulf/libserial).

### Usage
1. Connect your Arduino to the PC and note the serial port (e.g., `/dev/ttyACM0` on Linux).
2. Upload an appropriate sketch to your Arduino that acknowledges received commands (e.g., sending `Received.` when it processes a command).
3. Compile the code using a C++ compiler such as `g++`:
   ```bash
   g++ -std=c++17 -o main_sample main_sample.cpp ArduinoConnection.cpp -lserial
   ```
4. Run the compiled program:
   ```bash
   ./main_sample
   ```

### Sample Code
The `main_sample.cpp` file demonstrates how to:
- Open a connection to the Arduino.
- Send commands to toggle the built-in LED.
- Measure communication performance.

#### Key Functionality
```cpp
ArduinoConnection arduino("/dev/ttyACM0", 115200, 2000);
if (arduino.is_open()) {
    arduino.write("LED_BUILTIN=1");  // Turn on the built-in LED
    arduino.write("LED_BUILTIN=0");  // Turn off the built-in LED
}
```

## Benchmarks
- Achieved a communication rate of **250 Hz**, confirmed using timing measurements in the sample code.
- Response handling includes timeout checks to ensure reliability.

## Future Improvements
- Enhance error handling with more detailed logs.
- Add support for other communication protocols like SPI or I2C.
- Expand testing to ensure cross-platform compatibility.

## License
This project is licensed under the MIT License.

## Contributions
Contributions are welcome! Please open an issue or submit a pull request with your suggestions.

## Acknowledgments
- Thanks to the maintainers of [LibSerial](https://github.com/crayzeewulf/libserial) for their excellent library.

---

Start experimenting and enjoy seamless communication between your PC and Arduino!


# STM32F407VGT6  
## Multi-Protocol IoT System Based on STM32F407 and ESP32  

This project develops a versatile IoT system using the **STM32F407** as the central processing unit, combined with the **ESP32** for cloud connectivity and the **HC-06** module for Bluetooth communication with mobile devices. The system integrates multiple communication protocols (I2C, SPI, UART, 1-Wire, WiFi, Bluetooth) to enable the following functionalities:

- Collect temperature and humidity data from the **DHT11** sensor.  
- Display information on the **LCD 1602** screen.  
- Store data on an **SD card**.  
- Control motors (e.g., fans, pumps, etc.).  
- Synchronize data to **Firebase**.  
- Monitor and control remotely via a mobile application developed with **MIT App Inventor**.  

---

## System Architecture  

### 1. STM32F407 - Central Microcontroller  
- Collects data from the DHT11 sensor via the **1-Wire** protocol.  
- Displays information on the LCD 1602 screen using the **I2C** protocol.  
- Stores data on the SD card via the **SPI** protocol.  
- Controls motors through **GPIO** or **PWM**.  
- Communicates with the ESP32 via **UART** to transmit data to the cloud.  
- Connects to the HC-06 Bluetooth module via **UART** for mobile communication.  

### 2. ESP32 - Network-Connected Microcontroller  
- Receives data from the STM32F407 via **UART**.  
- Connects to **WiFi** to upload data to Firebase.  
- Processes and formats data before sending it to the cloud.  

### 3. HC-06 - Bluetooth Module  
- Connects to the STM32F407 via **UART**.  
- Establishes a Bluetooth connection with a mobile device.  
- Allows direct control from the phone when no internet connection is available.  

### 4. Other Components  
- **LCD 1602**: Displays system status and sensor data.  
- **DHT11**: Sensor for measuring temperature and humidity.  
- **SD Card**: Local storage for long-term data analysis.  
- **Motor**: Can be a fan, pump, or other controlled device.  
- **Firebase**: Cloud database for data storage and synchronization.  
- **MIT App Inventor Application**: User interface for monitoring and control on mobile devices.  

---

## Data Flow  

### 1. Data Collection  
- The STM32F407 reads temperature and humidity data from the DHT11 sensor.  
- Data is processed and displayed on the LCD 1602 screen.  
- Simultaneously, data is stored on the SD card for long-term analysis.  

### 2. Data Transmission to the Cloud  
- The STM32F407 sends data to the ESP32 via UART.  
- The ESP32 connects to WiFi and uploads the data to Firebase.  
- Data is stored in the cloud and can be accessed from anywhere.  

### 3. Remote Control  
- Users can control the system via the mobile app using two methods:  
  - Via **Firebase → ESP32 → STM32F407** (with an internet connection).  
  - Via **Bluetooth directly from the phone → HC-06 → STM32F407** (without internet).  

### 4. System Feedback  
- System status is displayed on the LCD 1602.  
- Updated information is sent back to the user via the mobile app.  
- Alerts can be triggered if data exceeds predefined thresholds.  

---

## Communication Protocols  

| **Protocol**  | **Connected Devices**       | **Speed/Configuration** | **Function**                        |  
|---------------|-----------------------------|-------------------------|-------------------------------------|  
| I2C           | STM32F407 ↔ LCD 1602       | 100kHz                 | Display status and data            |  
| SPI           | STM32F407 ↔ SD Card        | 10-25MHz              | Local data storage                 |  
| UART          | STM32F407 ↔ ESP32          | 115200 baud, 8N1      | Transmit data to the cloud         |  
| UART          | STM32F407 ↔ HC-06          | 9600 baud, 8N1        | Bluetooth connection to phone      |  
| 1-Wire        | STM32F407 ↔ DHT11          | N/A                   | Read temperature and humidity data |  
| WiFi          | ESP32 ↔ Firebase           | 2.4GHz                | Cloud connectivity                 |  
| Bluetooth     | HC-06 ↔ Phone              | 2.4GHz, SPP           | Direct control                     |  

---

## System Diagram  
![System SVG](https://raw.githubusercontent.com/Spiderman23012001/STM32F407VGT6/main/img/sys.svg)  
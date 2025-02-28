# STM32F407VGT6  
## Hệ Thống IoT Đa Giao Thức Dựa Trên STM32F407 và ESP32  

Dự án này phát triển một hệ thống IoT đa năng sử dụng **STM32F407** làm bộ xử lý trung tâm, kết hợp với **ESP32** để kết nối đám mây và module **HC-06** để giao tiếp Bluetooth với thiết bị di động. Hệ thống tích hợp nhiều giao thức truyền thông (I2C, SPI, UART, 1-Wire, WiFi, Bluetooth) nhằm thực hiện các chức năng chính:

- Thu thập dữ liệu nhiệt độ và độ ẩm từ cảm biến **DHT11**.  
- Hiển thị thông tin trên màn hình **LCD 1602**.  
- Lưu trữ dữ liệu vào **thẻ SD**.  
- Điều khiển động cơ (quạt, máy bơm, v.v.).  
- Đồng bộ dữ liệu lên **Firebase**.  
- Giám sát và điều khiển từ xa qua ứng dụng di động được phát triển bằng **MIT App Inventor**.  

---

## Kiến Trúc Hệ Thống  

### 1. STM32F407 - Bộ Vi Điều Khiển Trung Tâm  
- Thu thập dữ liệu từ cảm biến DHT11 qua giao thức **1-Wire**.  
- Hiển thị thông tin trên màn hình LCD 1602 qua giao thức **I2C**.  
- Lưu trữ dữ liệu vào thẻ SD qua giao thức **SPI**.  
- Điều khiển động cơ thông qua **GPIO** hoặc **PWM**.  
- Giao tiếp với ESP32 qua **UART** để truyền dữ liệu lên đám mây.  
- Kết nối với module Bluetooth HC-06 qua **UART** để giao tiếp với điện thoại.  

### 2. ESP32 - Bộ Vi Điều Khiển Kết Nối Mạng  
- Nhận dữ liệu từ STM32F407 qua **UART**.  
- Kết nối **WiFi** để truyền dữ liệu lên Firebase.  
- Xử lý và định dạng dữ liệu trước khi gửi lên đám mây.  

### 3. HC-06 - Module Bluetooth  
- Kết nối với STM32F407 qua **UART**.  
- Thiết lập kết nối Bluetooth với điện thoại di động.  
- Cho phép điều khiển trực tiếp từ điện thoại khi không có internet.  

### 4. Các Thành Phần Khác  
- **LCD 1602**: Hiển thị trạng thái hệ thống và dữ liệu cảm biến.  
- **DHT11**: Cảm biến đo nhiệt độ và độ ẩm.  
- **Thẻ SD**: Lưu trữ dữ liệu cục bộ để phân tích dài hạn.  
- **Động cơ**: Quạt, máy bơm hoặc thiết bị điều khiển khác.  
- **Firebase**: Cơ sở dữ liệu đám mây để lưu trữ và đồng bộ dữ liệu.  
- **Ứng dụng MIT App Inventor**: Giao diện điều khiển và giám sát trên điện thoại.  

---

## Luồng Dữ Liệu  

### 1. Thu Thập Dữ Liệu  
- STM32F407 đọc dữ liệu nhiệt độ và độ ẩm từ cảm biến DHT11.  
- Dữ liệu được xử lý và hiển thị trên màn hình LCD 1602.  
- Dữ liệu đồng thời được lưu trữ vào thẻ SD để phân tích dài hạn.  

### 2. Truyền Dữ Liệu Lên Đám Mây  
- STM32F407 gửi dữ liệu cho ESP32 qua UART.  
- ESP32 kết nối WiFi và đẩy dữ liệu lên Firebase.  
- Dữ liệu được lưu trữ trên đám mây và có thể truy cập từ bất kỳ đâu.  

### 3. Điều Khiển Từ Xa  
- Người dùng điều khiển hệ thống qua ứng dụng di động với hai phương thức:  
  - Qua **Firebase → ESP32 → STM32F407** (khi có kết nối internet).  
  - Qua **Bluetooth trực tiếp từ điện thoại → HC-06 → STM32F407** (khi không có internet).  

### 4. Phản Hồi Hệ Thống  
- Trạng thái hệ thống được hiển thị trên LCD 1602.  
- Thông tin cập nhật được gửi lại cho người dùng qua ứng dụng di động.  
- Cảnh báo được kích hoạt nếu dữ liệu vượt ngưỡng cài đặt.  

---

## Giao Thức Truyền Thông  

| **Giao Thức** | **Thiết Bị Kết Nối**        | **Tốc Độ/Cấu Hình** | **Chức Năng**                        |  
|---------------|-----------------------------|---------------------|--------------------------------------|  
| I2C           | STM32F407 ↔ LCD 1602       | 100kHz             | Hiển thị trạng thái và dữ liệu       |  
| SPI           | STM32F407 ↔ Thẻ SD         | 10-25MHz           | Lưu trữ dữ liệu cục bộ              |  
| UART          | STM32F407 ↔ ESP32          | 115200 baud, 8N1   | Truyền dữ liệu lên đám mây          |  
| UART          | STM32F407 ↔ HC-06          | 9600 baud, 8N1     | Kết nối Bluetooth với điện thoại    |  
| 1-Wire        | STM32F407 ↔ DHT11          | N/A                | Đọc dữ liệu nhiệt độ và độ ẩm       |  
| WiFi          | ESP32 ↔ Firebase           | 2.4GHz             | Kết nối đám mây                     |  
| Bluetooth     | HC-06 ↔ Điện thoại         | 2.4GHz, SPP        | Điều khiển trực tiếp                |  

---

## Sơ Đồ Hệ Thống  
![System SVG](https://raw.githubusercontent.com/Spiderman23012001/STM32F407VGT6/main/img/sys.svg)  

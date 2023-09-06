# MÜHTAS-1 IoT Device
MÜHTAS-1 is an IoT (Internet of Things) device designed to collect and analyze color and distance data. This device utilizes an STM32F103T8C6 MCU, a TCS3200 color sensor, an HC-SR04 distance sensor, and a WIZnet 5500 Ethernet module.

<div style="display: inline-block;">
  <img src="images/hardware.jpg" alt="Image Description" width="270" height="auto">
  <img src="images/mcu1.jpg" alt="Image Description" width="270" height="auto">
  <img src="images/mcu2.jpg" alt="Image Description" width="270" height="auto">
</div>

> The two images above do not feature the distance sensor. This is because the sensor was not included in the project for the fall semester of 2023.

## Features of Devices

* **STM32F103T8C6 MCU:** Microcontroller manages communication between all sensors and handles data collection processes.
* **TCS3200 Renk Sensörü:** Sensor collects color information from packages.
* **HC-SR04 Uzaklık Sensörü:** Sensor determines the position of packages on the conveyor belt.
* **WIZnet 5500 Ethernet Modülü:** Module sends collected data to a web interface via UDP.

## Timers

* **SPI1:** Used for SPI communication with the WIZnet 5500 Ethernet Module. It operates at a speed of 72MHz, connected to APB2.
* **TIM1:** Used to read data from the HC-SR04 Distance Sensor. It operates with a prescaler of 72-1 and a counter period of 65535-1.
* **TIM3 CHA1:** Used to read data from the TCS3200 Color Sensor. It operates with a prescaler of 0 and a counter period of 65535.

## How It Works

The basic operational cycle of MÜHTAS-1 is outlined below:

1. Set the color sensor to red, blue, and green colors in sequence, and read the frequency value for each color.
2. Perform a reading from the distance sensor.
3. Convert the read color and distance data into a JSON string and send it to the WIZnet module.
4. The WIZnet module sends this data to the network using the UDP protocol.
5. The cycle restarts with a specific delay.

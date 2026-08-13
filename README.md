# 🥬 Smart Food Spoilage Detection and Preservation System

An AI-powered food monitoring and preservation system that combines **real-time environmental sensing, embedded control, LabVIEW-based monitoring, and Machine Learning** to detect food spoilage conditions and automatically activate preservation mechanisms.

---

## 🤖 Project Overview

The **Smart Food Spoilage Detection and Preservation System** is an integrated hardware and software platform designed to monitor food storage conditions in real time and estimate the freshness and remaining shelf life of stored food.

The system continuously monitors key environmental parameters such as:

* 🌡️ Temperature
* 💧 Humidity
* 🧪 Gas concentration
* ⏱️ Elapsed storage time

The collected sensor data is processed through an **Artificial Intelligence / Machine Learning model** to estimate the spoilage condition and remaining freshness of the food.

Based on the detected storage conditions and predicted spoilage risk, the system can automatically control preservation mechanisms such as:

* ❄️ Peltier-based cooling
* 🌬️ Internal air circulation
* 💨 Exhaust ventilation
* 🚨 Buzzer alarm
* 💡 Status indicators

The complete system was physically implemented inside a dedicated food storage chamber and integrated with a **LabVIEW monitoring and control interface**.

---

## 🧠 Machine Learning System

One of the key aspects of the project is the integration of Machine Learning into the physical food storage system.

A Random Forest Regression model was developed to estimate the remaining time before food reaches a spoilage condition.

### Input Features

The ML model uses multiple environmental and system parameters:

* Temperature
* Humidity
* Gas Concentration
* Elapsed Time
* Peltier Status
* Fan Status
  
### Model Output

The trained model predicts:

* Food Status (Fresh, Moderate, Rotten)
* Remaining Time Before Spoilage
* Risk (Spoilage Index)

## 🥩 Food-Specific Prediction

The system is designed to support different food categories because different foods exhibit different spoilage behavior.

Separate models / datasets can be developed for categories such as:

* 🍎 Fruits
* 🥕 Vegetables
* 🐟 Fish
* 🥩 Meat
* 🥛 Dairy products

This allows the prediction system to account for the different environmental conditions and spoilage rates associated with different food types.

## 🧪 Environmental Monitoring

The system continuously monitors the storage environment using multiple sensors.

### 🌡️ Temperature Measurement

An NTC thermistor-based sensing circuit is used to measure the temperature inside the storage chamber.

The thermistor signal is conditioned using an LM358-based analog circuit before being acquired by the measurement system.

### 💧 Humidity Measurement

A DHT22 humidity/temperature sensor is used to monitor relative humidity inside the chamber.

Humidity information is used both for real-time monitoring and as an input to the ML prediction system.

### 🧪 Gas Detection

An MQ-135 gas sensor is used to detect changes in gas concentration associated with changes in the food storage environment.

Gas concentration is used as an additional indicator for spoilage prediction.

## 🔌 Arduino Embedded System

The Arduino acts as one of the main embedded control units of the system.

Its responsibilities include:

* Sensor interfacing
* Environmental data acquisition
* Processing sensor readings
* Controlling actuators
* Peltier control
* Fan control
* Buzzer control
* LED status indication
* OLED display interfacing
* Communication with the monitoring system

The Arduino provides the low-level hardware interface between the sensing and actuation components.

## ❄️ Automatic Preservation System

A major feature of the project is that the system does not only detect spoilage conditions—it also attempts to control the storage environment.

### Peltier Cooling

A TEC1-12706 Peltier module is used as the cooling mechanism.

When the chamber temperature rises above the desired operating range, the cooling system can be activated to reduce the temperature.

### 🌬️ Internal Circulation Fan

An internal fan is used to circulate air within the chamber and improve temperature distribution.

### 💨 Exhaust Fan

The exhaust fan can be activated when required to remove air from the chamber and assist in controlling the internal environment.

### 🚨 Alarm System

A buzzer provides an audible warning when critical conditions or high spoilage risk are detected.

### 💡 Status Indicators

LED indicators provide visual information about the current operating state of the system.

## 🖥️ LabVIEW Monitoring & Control

A dedicated LabVIEW interface was developed to provide real-time visualization of the food storage environment.

The dashboard provides information such as:

### 📊 Real-Time Parameters

* Temperature
* Humidity
* Gas concentration
* Spoilage risk
* Remaining shelf life
* Food type
* System status
  
### ⚙️ System Status

The interface can display the operating status of:

* Cooling Unit
* Internal Fan
* Exhaust Fan
* Buzzer
* LED Indicators

### 📈 Visualization

The LabVIEW interface provides real-time graphical monitoring of sensor parameters, allowing changes in the storage environment to be observed over time.

## 🤖 Machine Learning + LabVIEW Integration

The project integrates the ML prediction engine with the LabVIEW monitoring system.

The general data flow is:

Physical Sensors
       │
       ▼
Arduino / DAQ
       │
       ▼
LabVIEW
       │
       ▼
Python ML Backend
       │
       ▼
Random Forest Model
       │
       ▼
Spoilage Prediction
       │
       ▼
LabVIEW Dashboard
       │
       ▼
Preservation / Alarm Decision

This allows the system to combine physical sensor measurements with AI-based prediction rather than relying only on fixed threshold values.

## 🏠 Physical Implementation

The complete system was physically implemented inside a dedicated food storage chamber.

The physical prototype integrates:

* Acrylic / enclosed storage chamber
* Arduino controller
* Temperature sensing circuit
* Humidity sensor
* Gas sensor
* Peltier cooling module
* Heat sink
* Cooling fan
* Exhaust fan
* MOSFET switching circuits
* Buzzer
* LEDs
* OLED display
* Power supply
* Interconnecting wiring

The physical setup was designed to create a controlled environment where temperature, humidity, and gas conditions could be monitored and manipulated.

## ⚡ Actuator Control

Power-intensive loads are controlled through dedicated switching circuits rather than directly from the Arduino.

The system uses MOSFET-based switching for controlling loads such as:

* TEC1-12706 Peltier module
* DC fans
* Other high-current actuators

This provides electrical isolation between the low-power microcontroller control signals and the higher-power actuator circuits.

## 🧪 Experimental Testing

The physical system was tested under different environmental conditions to evaluate the response of the sensing, control, and prediction systems.

Testing focused on:

* Temperature response
* Humidity measurement
* Gas sensor response
* Cooling performance
* Fan operation
* Sensor stability
* ML prediction behavior
* LabVIEW data visualization
* Arduino actuator control
* Integrated system operation
  
## 📊 System Evaluation

The system can be evaluated using parameters such as:

* Parameter	Evaluation Objective
* Temperature Accuracy	Reliable chamber monitoring
* Humidity Accuracy	Environmental monitoring
* Gas Detection	Spoilage indication
* ML Prediction Error	Prediction reliability
* Cooling Response	Preservation performance
* Sensor Response Time	Real-time monitoring
* Actuator Response	Control reliability
* System Stability	Long-duration operation
  
## 🧠 Challenges Faced

Several engineering challenges were encountered during development:

* Sensor calibration and noise
* Reliable humidity data acquisition
* Thermistor signal conditioning
* Gas sensor variability
* Integrating Arduino with LabVIEW
* Real-time sensor communication
* Controlling high-current Peltier loads
* Thermal management of the Peltier module
* Maintaining stable chamber temperature
* Synchronizing ML predictions with real-time sensor data
* Integrating hardware, software, and ML components
* Developing a reliable physical enclosure

These challenges required iterative hardware testing, software debugging, circuit modification, and system-level integration.

## 🌟 Special Features

The project combines several technologies into a single integrated platform:

### 🔹 Artificial Intelligence

Machine Learning is used to estimate food freshness and remaining shelf life.

### 🔹 Embedded Systems

Arduino-based sensing and actuator control provide the hardware interface.

### 🔹 LabVIEW

A graphical monitoring dashboard provides real-time visualization and system status.

### 🔹 Automated Preservation

The system can automatically activate cooling and ventilation mechanisms based on environmental conditions.

### 🔹 Physical Prototype

Unlike a software-only ML project, the prediction system is connected to a physically implemented food storage chamber.

### 🔹 Multi-Parameter Analysis

Food condition is evaluated using multiple environmental variables rather than relying on a single sensor.

## 🎯 Future Improvements

Potential future developments include:

* Advanced deep-learning-based spoilage prediction
* LSTM-based time-series prediction
* Computer vision-based food condition detection
* Electronic nose / advanced gas sensing
* Improved sensor fusion
* IoT cloud connectivity
* Mobile application
* Remote monitoring
* Automated food-type recognition
* Adaptive temperature and humidity control
* Digital twin of the storage chamber
* Predictive maintenance
* Larger food spoilage datasets
* Edge AI implementation
* Custom PCB development
* Improved thermal insulation
* Multi-compartment food storage
  
## 📸 Physical Prototype

### Physical Setup
<img width="1200" alt="Smart Food Spoilage Detection System" src="https://github.com/user-attachments/assets/93a5b83c-7299-4988-beac-43d49a4afbba"/>

### Team
<img width="1200" alt="Physical Food Storage Chamber" src="https://github.com/user-attachments/assets/f7940b5b-d5d0-41d1-a71d-c97a0911dd24"/>

## 🎥 Project Demonstration

🎥 Demonstration Video:
(https://drive.google.com/drive/folders/13WYR62Bh3aPECDqB0d2YvAxTqItwog0W)

## 👥 Project Team

* K. Pasindu Jayawardana
* A.J.A. Jayawardana
* J.M.T.R.B. Jayasundara

University: University of Moratuwa
Department: Department of Electrical Engineering

## 🎓 Academic Project

This project was developed as an engineering project with the objective of integrating concepts from:

* Electrical Engineering
* Electronics
* Embedded Systems
* Instrumentation
* Control Systems
* Machine Learning
* Data Acquisition
* LabVIEW
* Thermal Management
* Automation

The project provided practical experience in developing a complete engineering system from sensor-level hardware to AI-based decision making and physical implementation.

## 🙌 Acknowledgements

Special thanks to:

* University of Moratuwa
* Department of Electrical Engineering
* Project supervisors and lecturers
* Laboratory staff
* Team members
  
## 📜 License

This project is developed for educational and research purposes.

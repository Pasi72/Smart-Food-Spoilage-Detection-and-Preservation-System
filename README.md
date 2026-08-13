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

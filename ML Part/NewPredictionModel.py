import socket
import joblib
import numpy as np

models = {"fruits":joblib.load("fruits_model.pkl"), "vegetables":joblib.load("vegetables_model.pkl"), "fish":joblib.load("fish_model.pkl"), "meat":joblib.load("meat_model.pkl"), "dairy":joblib.load("dairy_model.pkl")}

def calculate_spoilage_index(temperature, humidity, gas, elapsed_time):
    temp_risk = 0
    humidity_risk = 0
    gas_risk = 0
    
    # Threshold values might be changed according to the specific storage conditions (Here we are only considering fruits)
    temp_threshold = 25
    humidity_threshold = 70
    gas_threshold = 300

    if temperature > temp_threshold:
        temp_risk = min(100, max(0,(temperature - temp_threshold) * 5))

    if humidity > humidity_threshold:
        humidity_risk = min(100, max(0,(humidity - humidity_threshold) * 2))

    if gas > gas_threshold:
        gas_risk = min(100, max(0,(gas - gas_threshold) * 0.2))

    risk = temp_risk * 0.5 + humidity_risk * 0.3 + gas_risk * 0.2
    risk += elapsed_time * 2

    if risk < 0:
        risk = 0

    if risk > 100:
        risk = 100

    return risk

# These remaining time and risk thresholds might be changed
def food_status(remaining_time, risk):

    if remaining_time > 12 and risk < 30:
        return "FRESH"

    elif remaining_time > 4 and risk < 70:
        return "MODERATE"

    else:
        return "SPOILED"

# Connecting the Labview with ML (To send inputs for the ML from Labview sensor outputs)

HOST = "127.0.0.1"
PORT = 5000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST,PORT))
server.listen(1)
print("Waiting for LabVIEW...")
conn, address = server.accept()

print("Connected:", address)

while True:

    data = conn.recv(1024).decode()
    if not data:
        continue

    try:
        values = data.split(",")
        
        food_type = values[0]
        temperature = float(values[1])
        humidity = float(values[2])
        gas = float(values[3])
        elapsed_time=float(values[4])
        peltier = int(values[5])
        fan=int(values[6])

        X = np.array([temperature, humidity, gas, elapsed_time, peltier, fan]).reshape(1,-1)
        remaining_time = models[food_type].predict(X)[0]

        risk = calculate_spoilage_index(temperature, humidity, gas, elapsed_time)
        status = food_status(remaining_time, risk)

        result = f"{risk:.2f},{remaining_time:.2f},{status}"

        conn.send(result.encode())
        print("Input :",data)
        print("Output :",result)

    except Exception as e:
        conn.send(b"ERROR")
        print(e)
import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error
import joblib

data = pd.read_csv("food_spoilage_combined.csv")
food_types = data["food_type"].unique()


features = ["temperature", "humidity", "gas", "elapsed_time", "peltier", "fan"]

for food in food_types:

    print("Training :", food)
    food_data = data[data["food_type"] == food]
    X = food_data[features]
    y = food_data["remaining_time"]

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 42)

    model = RandomForestRegressor(n_estimators=300, max_depth=15, random_state=42)
    model.fit(X_train, y_train)
    prediction = model.predict(X_test)
    error = mean_absolute_error( y_test, prediction)

    print(food, "error :", error, "hours")

    joblib.dump(model, food + "_model.pkl")
print("All models trained")
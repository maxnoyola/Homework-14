#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;


json loadJson(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open the JSON file!" << endl;
        exit(EXIT_FAILURE);
    }

    json jsonData;
    file >> jsonData;
    file.close();
    return jsonData;
}


json chooseDonut(const json &data) {
    cout << "Choose a donut type:\n";
    for (const auto &item : data) {
        cout << item["id"] << ": " << item["name"] << "\n";
    }

    string donutId;
    while (true) {
        cin >> donutId;
        for (const auto &item : data) {
            if (item["id"] == donutId) {
                return item;
            }
        }
        cout << "Invalid ID! Please try again: ";
    }
}


string chooseBatter(const json &donut) {
    cout << "Choose a batter type:\n";
    for (const auto &batter : donut["batters"]["batter"]) {
        cout << batter["id"] << ": " << batter["type"] << "\n";
    }

    string batterId;
    while (true) {
        cin >> batterId;
        for (const auto &batter : donut["batters"]["batter"]) {
            if (batter["id"] == batterId) {
                return batter["type"];
            }
        }
        cout << "Invalid ID! Please try again: ";
    }
}


string chooseTopping(const json &donut) {
    cout << "Choose a topping type:\n";
    for (const auto &topping : donut["topping"]) {
        cout << topping["id"] << ": " << topping["type"] << "\n";
    }

    string toppingId;
    while (true) {
        cin >> toppingId;
        for (const auto &topping : donut["topping"]) {
            if (topping["id"] == toppingId) {
                return topping["type"];
            }
        }
        cout << "Invalid ID! Please try again: ";
    }
}


int main() {
    
    string filePath = "donuts.json"; 
    json data = loadJson(filePath);
    json selectedDonut = chooseDonut(data);
    string selectedBatter = chooseBatter(selectedDonut);
    string selectedTopping = chooseTopping(selectedDonut);
    cout << "You have ordered a " << selectedDonut["name"] << " donut with " 
         << selectedBatter << " batter and " << selectedTopping << " topping.\n";

    return 0;
}

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class TrafficLight {
public:
    enum LightState { RED, YELLOW, GREEN };

private:
    LightState state;
    int redDuration;     // Duration for red light in seconds
    int yellowDuration;  // Duration for yellow light in seconds
    int greenDuration;   // Duration for green light in seconds

public:
    TrafficLight(int redDur, int yellowDur, int greenDur)
        : redDuration(redDur), yellowDuration(yellowDur), greenDuration(greenDur), state(RED) {}

    void setState(LightState newState) {
        state = newState;
    }

    LightState getState() const {
        return state;
    }

    void changeLight() {
        switch (state) {
            case RED:
                setState(YELLOW);
                break;
            case YELLOW:
                setState(GREEN);
                break;
            case GREEN:
                setState(RED);
                break;
        }
    }

    int getDuration() const {
        switch (state) {
            case RED:
                return redDuration;
            case YELLOW:
                return yellowDuration;
            case GREEN:
                return greenDuration;
        }
        return 0; // Default case (should not reach here)
    }

    string getStateString() const {
        switch (state) {
            case RED:
                return "RED";
            case YELLOW:
                return "YELLOW";
            case GREEN:
                return "GREEN";
        }
        return ""; // Default case (should not reach here)
    }
};

int main() {
    
    cout<<"            TRAFFIC CYCLE MANAGEMENT SYSTEM  "  <<endl;
    TrafficLight light(5, 3, 2); // Red for 5s, Yellow for 3s, Green for 2s
    char input;

    while (true) {
        for (int i = 0; i < 3; ++i) { // Simulate 3 light changes (RED -> YELLOW -> GREEN)
            cout << "Light is: " << light.getStateString() << " for " << light.getDuration() << " seconds" << endl;
            this_thread::sleep_for(chrono::seconds(light.getDuration()));
            light.changeLight();
        }

        cout << "\nPress 's' to stop, press 'c' to continue: ";
        cin >> input;

        if (input == 's') {
            break;
        }
    }

    return 0;
}

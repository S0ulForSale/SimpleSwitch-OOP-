#include <Arduino.h>
#include <vector>

// Basic abstract class
class SmartDevice {
protected:
    String name;
    int pin;
    bool state;
public:
    SmartDevice(String n, int p,bool s) : name(n), pin(p), state(s) {}
    virtual void toggle() = 0; 
    virtual void printStatus() {
        Serial.print("Device: " + name + " | State: ");
        Serial.println(state ? "ON" : "OFF");
    }
    virtual ~SmartDevice() {} 
};

// Light
class SimpleLight : public SmartDevice {
public:
    SimpleLight(String n, int p,bool s = false) : SmartDevice(n, p, s) { pinMode(pin, OUTPUT); }
    void toggle() override {
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
        Serial.println(name + " switch");
    }
};

//Signalisation
class StatusIndicator : public SmartDevice {
public:
    StatusIndicator(String n, int p,bool s = true) : SmartDevice(n, p, s) { pinMode(pin, OUTPUT); }
    void toggle() override {
        state = !state;
        for(int i=0; i<3; i++) {
            digitalWrite(pin, HIGH); delay(100);
            digitalWrite(pin, LOW); delay(100);
        }
        digitalWrite(pin, state ? HIGH : LOW); // return final state
    }
};

std::vector<SmartDevice*> devices;
int lastButtonState = HIGH;

// OnButtonPress
void toggleAll() {
    Serial.println("--- Triggering all devices ---");
    for (auto device : devices) {
        device->toggle();
        device->printStatus();
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(25, INPUT_PULLUP);

    devices.push_back(new SimpleLight("Light", 2));
    devices.push_back(new StatusIndicator("Indicator", 4));
    
    Serial.println("System Ready! Press the button on GPIO 25.");
}

void loop() {
    int currentButtonState = digitalRead(25);
    //if button pressed
    if (lastButtonState == HIGH && currentButtonState == LOW) {
        delay(50); // Debounce
        toggleAll();
    }

    lastButtonState = currentButtonState;
    
    delay(10);
}
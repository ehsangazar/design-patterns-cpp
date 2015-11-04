#include <iostream>
#include <string>
using namespace std;

// Default Classes
class Device
{
public:
    virtual void send(string data) = 0; 
    virtual int setSpeed(int value) = 0;
    virtual int getSpeed() = 0;
};

class Wifi : public Device
{
public:
    int speed;
    Wifi()
    {
        speed = 100;
    }
    int setSpeed(int value)
    {
        speed = value;
    }
    int getSpeed()
    {
        return speed;
    }
    void send(string data)
    {
        cout<<"Sent By Wifi: "<<data<<" Speed: "<<speed<<endl;
    }
};

class Bluetooth : public Device
{
public:
    int speed;
    Bluetooth(){
        speed = 8;
    }
    int setSpeed(int value)
    {
        speed = value;
    }
    int getSpeed()
    {
        return speed;
    }
    void send(string data)
    {
        cout<<"Sent By Bluetooth: "<<data<<" Speed: "<<speed<<endl;
    }
};

// Prototype Started
// Problem: Clone the old object
// Solution: Clone function

class Prototype
{
public:
    virtual Device* clone(Device *oldOneObject) = 0;
};

class BluetoothPrototype : public Prototype
{
public:
    Device* clone(Device* oldOneObject)
    {
        Device* newOneObject = new Bluetooth;
        newOneObject->setSpeed(oldOneObject->getSpeed());
        return newOneObject;
    }
};


// Main Usage
int main(){
    Device* bluetoothObject = new Bluetooth;
    bluetoothObject->setSpeed(20);
    bluetoothObject->send("First Object");

    Prototype* prototypeObject = new BluetoothPrototype;
    Device* clonedBluetoothObject = prototypeObject->clone(bluetoothObject);
    clonedBluetoothObject->send("Cloned Object creatd");

    cout<<"If speed is same in two objects, it means clone worked successfully"<<endl;
}
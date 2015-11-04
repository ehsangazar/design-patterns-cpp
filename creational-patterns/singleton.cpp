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
    static Wifi* thisInstance;
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
    // Singleton Design Pattern
    static Device* instance()
    {
      if (!thisInstance){
        thisInstance = new Wifi;
      }      
      return thisInstance;
    }
};

class Bluetooth : public Device
{        
public:    
    int speed;
    static Bluetooth* thisInstance;
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
    // Singleton Design Pattern
    static Bluetooth *instance()
    {
      if (!thisInstance){
        thisInstance = new Bluetooth;
      }      
      return thisInstance;
    }
};

// Singleton Design Pattern Just added in to the every object
// Problem: access same object everywhere
// Solution: Add that to Object
Bluetooth *Bluetooth::thisInstance = 0;
Wifi *Wifi::thisInstance = 0;
int main()
{  
  Bluetooth::instance()->setSpeed(20);
  Bluetooth::instance()->send("First Object");

  Bluetooth::instance()->send("Second Object");  

  cout<<"Second Object should be same as the first one"<<endl;
}
#include <iostream>
#include <string>
using namespace std;

// Default Classes
class Device
{
public:
	virtual void send(string data) = 0;	
};

class Wifi : public Device
{
public:
	void send(string data)
	{
		cout<<"Sent By Wifi: "<<data<<endl;
	}
};

class Bluetooth : public Device
{
public:
	void send(string data)
	{
		cout<<"Sent By Bluetooth: "<<data<<endl;
	}
};

// Abstract Factory Started
// Problem: Multiple if every function for handle the environment
// Solution: Build Abstract Factory and get method

class AbstractFactory
{
public:
	virtual Device* get() = 0;
};

class DeviceAbstractFactory : public AbstractFactory
{
public:
	Device* get()
	{
		if (true) // Confitions
		{
			return new Wifi;
		}
		else
		{
			return new Bluetooth;
		}
	}
};

// Main Usage
int main()
{
	AbstractFactory *abstractFactory = new DeviceAbstractFactory;
	Device* device;
	device = abstractFactory->get();	
	
	device->send("Abstract Factory Design Pattern Worked.");
}

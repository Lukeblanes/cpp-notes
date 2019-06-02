#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName()
{
	return "Chernicious";
}

// Another useful practical example
class Device{};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:

	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const 
	{
		return m_Devices;
	}
};
int main()
{
	int a = 5;

	// int b = a;
	// instead of typing int i can write auto
	auto b = a; // to determine what type b will be it looks at the type of a
	auto c = 5; // to determine what type c will be it looks at what 5 is
	auto d = 5L; // the L makes it a long

	// auto can be anything
	
	auto name = GetName();  // In this case i wouldn't use auto
	// if i decide to change the return type of GetName. I don't have to change this code
	// But if name relies on functions from std::string and it's a char* there might be a problem
	std::cout << name << std::endl;

	// Actual useful use cases. Suppose we have a function
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	// Let's say i want to iterate
	// You probably would use a foreach loop
	for (std::vector<std::string>::iterator it = strings.begin();
			it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// In the case above the type of the iterator is huge
	// This might be a good place to use auto
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// Other practical case with device manager
	DeviceManager dm;
	// this is what i would have to do to get devices
	const std::unordered_map<std::string, std::vector<Device*>> devs = dm.GetDevices();

	// the type is massive
	// One solution is aliasing the type
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	// alternative to using
	// typedef DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	const DeviceMap& devices = dm.GetDevices();

	// we can use auto as another alternative. we still have to indicate it's a reference. If we don't, it will make a copy
	const auto& devices_auto = dm.GetDevices();	// here we only copy the reference
	// auto devices_auto = dm.GetDevices();	this will copy the unordered_map
}

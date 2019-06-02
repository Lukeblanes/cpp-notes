#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "player -> x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;
#define VEC2(a) std::cout << "vec2 -> x: " << a.x << " y: " << a.y << std::endl;

// We're going to create a class to log our messages. Debugging purposes
// - Write text to console
// - Mantain a Log level (Error, Warning, Message)
// - With Log Level we will later on be able to filter through the levels

class Log 
{
	// we use public again to separate the public variables from the public functions
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo; // i use the m_ to know that it's a private member from the class
	// 2 will be info
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}
	
	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main() 
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("Hello");
	log.Error("This is error");
	log.Info("This is important");
	std::cin.get();

}


#include <iostream>

#define LOG(x) std::cout << x << std::endl;
#define PLAYER(a) std::cout << "player -> x: " << a.x << " y: " << a.y << " speed: " << a.speed << std::endl;
#define VEC2(a) std::cout << "vec2 -> x: " << a.x << " y: " << a.y << std::endl;

class Log
{
public:
	/* OLD
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
	*/
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo; // i use the m_ to know that it's a private member from the class
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::LevelError);
	log.Warn("Hello");
	log.Error("This is error");
	log.Info("This is important");
	std::cin.get();

}


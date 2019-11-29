#include <iostream>
#include <mutex>
#include <stdlib.h>

class MySingleton
{
public:
	~MySingleton()=default;

	MySingleton* getInstance()
	{
		if (!sInstance)
		{
			sInstance = new MySingleton();
			static GCMySingleton gCMySingleton;
		}
		return sInstance;
	}
	class GCMySingleton
	{
	public:
		GCMySingleton() = default;
		~GCMySingleton();
	private:
	};

private:
	MySingleton() = default;

	static MySingleton* sInstance;
};
MySingleton* MySingleton::sInstance = nullptr;

MySingleton::GCMySingleton::~GCMySingleton()
{
	if (MySingleton::sInstance)
	{
		delete MySingleton::sInstance;
		MySingleton::sInstance = nullptr;
	}
}

#ifndef _RANDOM_H
#define _RANDOM_H
#include <random>
#include <chrono>

namespace SDLFramework {
	class Random
	{
	private:
		static Random* sInstance;

	public:
		static Random* Instance();
		static void Release();

	private:
		Random();
		~Random();
		std::mt19937 mGenerator;

	public:
		unsigned RandomInt();	//[0, unsigned max]
		float RandomFloat();	//[0.0, 1.0]
		int RandomRange(int low, int high);	// [low, high]
		float RandomRange(float low, float high);	// [low, high]
	};
}

#endif // !_RANDOM_H
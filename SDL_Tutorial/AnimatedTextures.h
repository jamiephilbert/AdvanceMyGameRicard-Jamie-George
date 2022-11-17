#ifndef _ANIMATEDTEXTURES_H
#define _ANIMATEDTEXTURES_H
#include "Texture.h"
#include "Timer.h"

namespace SDLFramework {
class AnimatedTextures : public Texture
{
public:
	enum WrapMode {Once = 0, Loop = 1};
	enum AnimDir {Horizontal = 0, Vertical = 1 };
	 
private:
	Timer* m_pTimer;
	int mStartX;
	int mStartY;
	int mFrameCount;
	float mAnimationSpeed;
	float mTimerPerFrame;
	float mAnimationTimer;

	WrapMode mWrapMode;
	AnimDir mAnimationDirection;

	bool mAnimationDone;

public:
	AnimatedTextures(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed,
		AnimDir animationDir, bool managed = false);
	~AnimatedTextures();

	void SetWrapMode(WrapMode mode);
	void ResetAnimation();
	bool IsAnimation();

	void Update();

};
}
#endif // !1
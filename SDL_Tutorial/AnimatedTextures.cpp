#include "AnimatedTextures.h"

namespace SDLFramework {
	AnimatedTextures::AnimatedTextures(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed,
		AnimDir animationDir, bool managed) : Texture(filename, x, y, w, h, managed) {
		m_pTimer = Timer::Instance();

		mStartX = x;
		mStartY = y;
		mFrameCount = frameCount;
		mAnimationSpeed = animationSpeed;
		mTimerPerFrame = mAnimationSpeed / mFrameCount;
		mAnimationTimer = 0.0f;
		mWrapMode = Loop;
		mAnimationDirection = animationDir;
		mAnimationDone = false;

	}


	AnimatedTextures::~AnimatedTextures() {}

	void AnimatedTextures::SetWrapMode(WrapMode wrapmode) {
		mWrapMode = wrapmode;
	}

	void AnimatedTextures::ResetAnimation() {
		mAnimationTimer = 0.0f;
		mAnimationDone = false;
	}

	bool AnimatedTextures::IsAnimation() {
		return !mAnimationDone;
	}

	void AnimatedTextures::Update() {
		if (!mAnimationDone) {
			mAnimationTimer += m_pTimer->DeltaTime();
			if (mAnimationTimer >= mAnimationSpeed) {
				if (mWrapMode == Loop) {
					mAnimationTimer -= mAnimationSpeed;
				}
				else {
					mAnimationDone = true;
					mAnimationTimer = mAnimationSpeed - mTimerPerFrame;
				}
			}
			if (mAnimationDirection == Horizontal) {
				mSourceRect.x = mStartX + (int)(mAnimationTimer / mTimerPerFrame) * mWidth;
			}
			else {
				mSourceRect.y = mStartY + (int)(mAnimationTimer / mTimerPerFrame) * mHeight;
			}

		}
	}
}
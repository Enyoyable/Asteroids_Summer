#pragma once

#include "stdafx.h"

class AnimatedSprite : public sf::Sprite
{
public:

	struct Frame
	{
		sf::IntRect m_placement;
		sf::Texture *m_texture;
		float mf_duration;
	};

public:
	AnimatedSprite();

	void update(float pf_deltaTime);

	void play();

	void pause();

	void addFrame(Frame *p_Frame);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setCurrentframe(int pi_currentFrame);

	int getCurrentFrame();

	int getFramesCount();

	void setAnimationRange(int pi_Index1, int pi_Index2);

	void setFramesToAnimate(std::vector<int> pv_frames);

	void resetAnimationConditions();

	bool onLastFrame();

	void setTriggers(std::vector<int> p_vTriggers);

	void clearTriggers();

	bool getIsTrigger();

private:

	bool mb_isPlaying;

	std::vector<Frame*> mv_frames;

	std::vector<Frame*> mv_totalFrames;

	int mi_currentFrame;

	float mf_timeSicneLastFrame;

	bool mb_Specialcondition;

	std::vector<int> mv_framesToAnimate;

	std::vector<int> mv_Triggers;

	bool mb_isTriggered;
};
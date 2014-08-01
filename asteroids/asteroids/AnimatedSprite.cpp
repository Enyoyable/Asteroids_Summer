#include "AnimatedSprite.h"
#include <fstream>

AnimatedSprite::AnimatedSprite()
{
	mf_timeSicneLastFrame = 0;
	play();
	mi_currentFrame = 0;
}

void AnimatedSprite::update(float pf_deltaTime)
{
	if (mb_isPlaying)
	{
		mf_timeSicneLastFrame += pf_deltaTime;

		if (mf_timeSicneLastFrame > mv_frames[mi_currentFrame]->mf_duration)
		{
			mi_currentFrame = (mi_currentFrame + 1) % mv_frames.size();
			mf_timeSicneLastFrame = 0;

			for (auto trigger : mv_Triggers)
			{
				if (mi_currentFrame == trigger)
				{
					mb_isTriggered = true;
					break;
				}
				else
				{
					mb_isTriggered = false;
				}
			}
		}
	}
}

void AnimatedSprite::play()
{
	mb_isPlaying = true;
}

void AnimatedSprite::pause()
{
	mb_isPlaying = false;
}

void AnimatedSprite::addFrame(Frame *p_Frame)
{
	mv_frames.push_back(p_Frame);
	mv_totalFrames.push_back(p_Frame);
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(*mv_frames[mi_currentFrame]->m_texture, mv_frames[mi_currentFrame]->m_placement);
	states.transform *= getTransform();
	target.draw(sprite, states);
}

void AnimatedSprite::setCurrentframe(int pi_currentFrame)
{
	mi_currentFrame = pi_currentFrame;
}

int AnimatedSprite::getCurrentFrame()
{
	return mi_currentFrame;
}

int AnimatedSprite::getFramesCount()
{
	return mv_frames.size();
}

void AnimatedSprite::setAnimationRange(int pi_Index1, int pi_Index2)
{
	mv_frames.clear();

	for (int i = pi_Index1; i <= pi_Index2; i++)
	{
		mv_frames.push_back(mv_totalFrames[i]);
	}
}

void AnimatedSprite::setFramesToAnimate(std::vector<int> pv_frames)
{
	mv_frames.clear();

	for (auto frame : pv_frames)
	{
		mv_frames.push_back(mv_totalFrames[frame]);
	}
}

void AnimatedSprite::resetAnimationConditions()
{
	mv_frames = mv_totalFrames;
}

bool AnimatedSprite::onLastFrame()
{
	return mi_currentFrame == (mv_frames.size() - 1);
}

void AnimatedSprite::setTriggers(std::vector<int> p_vTriggers)
{
	mv_Triggers = p_vTriggers;
}

void AnimatedSprite::clearTriggers()
{
	mv_Triggers.clear();
}

bool AnimatedSprite::getIsTrigger()
{
	if (mb_isTriggered)
	{
		mb_isTriggered = false;
		return true;
	}
	return false;
}


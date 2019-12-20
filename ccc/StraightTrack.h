#pragma once
#include "Track.h"
class StraightTrack : public Track
{

public:
	StraightTrack(Track prev, Track nextA, Track nextB);
	~StraightTrack();

public:
	int id;

	int length;

};



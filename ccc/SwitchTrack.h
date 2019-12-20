#pragma once

#include "Track.h"
class SwitchTrack : public Track
{
public:
	SwitchTrack(Track prev, Track nextA, Track nextB);
	~SwitchTrack();

public:
	int id;
	
	int length;

};


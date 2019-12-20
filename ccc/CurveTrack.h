#pragma once
#include "Track.h"

class CurveTrack : public Track
{
public:
	CurveTrack(Track prev, Track next);
	~CurveTrack();

public:
	int id;

	int length;

};


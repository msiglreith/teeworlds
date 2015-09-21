/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_CLIENT_COMPONENTS_MAPSAMPLES_H
#define GAME_CLIENT_COMPONENTS_MAPSAMPLES_H

#include <engine/sound.h>
#include <game/client/component.h>

class CMapSamples : public CComponent
{
	enum { MAX_SAMPLES=64, };

	ISound::CSampleHandle m_aSamples[MAX_SAMPLES];
	int m_Count;

public:
	CMapSamples();

	ISound::CSampleHandle Get(int Index) const;
	int Num() const;

	virtual void OnMapLoad();
};

#endif

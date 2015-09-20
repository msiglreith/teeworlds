/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "editor.h"

CLayerSounds::CLayerSounds()
{
	m_Type = LAYERTYPE_SOUNDS;
	str_copy(m_aName, "Sounds", sizeof(m_aName));
}

CLayerSounds::~CLayerSounds()
{

}

void CLayerSounds::Render()
{
	Graphics()->TextureClear();
	Graphics()->BlendNormal();
	Graphics()->QuadsBegin();

	// TODO:

	Graphics()->QuadsEnd();
}

CAudioSource *CLayerSounds::NewSource()
{
	m_pEditor->m_Map.m_Modified = true;

	CAudioSource *pSource = &m_lSources[m_lSources.add(CAudioSource())];

	pSource->m_Position.x = i2fx(0);
	pSource->m_Position.y = i2fx(0);

	pSource->m_FalloffDist = 1600;

	return pSource;
}

int CLayerSounds::RenderProperties(CUIRect *pToolbox)
{
	return 0;
}

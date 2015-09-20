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

	// render falloff distance circle
	Graphics()->SetColor(0.5f, 0.75f, 1.0f, 0.4f);
	for(int i = 0; i < m_lSources.size(); i++)
	{
		CAudioSource *pSource = &m_lSources[i];
		m_pEditor->RenderTools()->DrawCircle(fx2f(pSource->m_Position.x), fx2f(pSource->m_Position.y), pSource->m_FalloffDist, 32);
	}

	Graphics()->QuadsEnd();
}

CAudioSource *CLayerSounds::NewSource()
{
	m_pEditor->m_Map.m_Modified = true;

	CAudioSource *pSource = &m_lSources[m_lSources.add(CAudioSource())];

	pSource->m_Position.x = i2fx(0);
	pSource->m_Position.y = i2fx(0);

	pSource->m_FalloffDist = 1000;

	return pSource;
}

int CLayerSounds::RenderProperties(CUIRect *pToolbox)
{
	return 0;
}

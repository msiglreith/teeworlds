/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "editor.h"

CLayerSounds::CLayerSounds()
{
	m_Type = LAYERTYPE_SOUNDS;
	str_copy(m_aName, "Sounds", sizeof(m_aName));
	m_Sample = -1;
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
	Graphics()->SetColor(0.2f, 0.3f, 0.4f, 0.4f);
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

int CLayerSounds::RenderProperties(CUIRect *pToolBox)
{
	// layer props
	enum
	{
		PROP_SAMPLE=0,
		NUM_PROPS,
	};

	CProperty aProps[] = {
		{"Sample", m_Sample, PROPTYPE_SAMPLE, -1, 0},
		{0},
	};

	static int s_aIds[NUM_PROPS] = {0};
	int NewVal = 0;
	int Prop = m_pEditor->DoProperties(pToolBox, aProps, s_aIds, &NewVal);
	if(Prop != -1)
		m_pEditor->m_Map.m_Modified = true;

	if(Prop == PROP_SAMPLE)
	{
		if(NewVal >= 0)
			m_Sample = NewVal%m_pEditor->m_Map.m_lSamples.size();
		else
			m_Sample = -1;
	}

	return 0;
}

void CLayerSounds::ModifySampleIndex(INDEX_MODIFY_FUNC Func)
{
	Func(&m_Sample);
}

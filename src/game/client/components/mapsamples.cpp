
#include "mapsamples.h"

CMapSamples::CMapSamples()
{
	m_Count = 0;
}

void CMapSamples::OnMapLoad()
{
	IMap *pMap = Kernel()->RequestInterface<IMap>();

	// unload all samples
	for(int i = 0; i < m_Count; i++)
	{
		Sound()->UnloadSample(m_aSamples[i]);
		m_aSamples[i] = ISound::CSampleHandle();
	}
	m_Count = 0;

	// load samples
	int Start;
	pMap->GetType(MAPITEMTYPE_SAMPLE, &Start, &m_Count);

	for(int i = 0; i < m_Count; i++)
	{
		CMapItemSample *pSample = (CMapItemSample *)pMap->GetItem(Start+i, 0, 0);

		char Buf[256];
		char *pName = (char *)pMap->GetData(pSample->m_SampleName);
		str_format(Buf, sizeof(Buf), "mapres/%s.wv", pName);
		dbg_msg("mapsounds", "load sample %s", Buf);
		m_aSamples[i] = Sound()->LoadWV(Buf);
	}
}

ISound::CSampleHandle CMapSamples::Get(int Index) const
{
	return m_aSamples[clamp(Index, 0, m_Count)];
}

int CMapSamples::Num() const
{
	return m_Count;
}

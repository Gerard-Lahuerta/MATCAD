// EntornV3D.h: archivo de encabezado principal para la aplicaci�n EntornV3D
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // S�mbolos principales
#include "quatern.h"


// CEntornV3DApp:
// Consulte la secci�n EntornV3D.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CEntornV3DApp : public CWinAppEx
{
public:
	CEntornV3DApp();


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementaci�n
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEntornV3DApp theApp;

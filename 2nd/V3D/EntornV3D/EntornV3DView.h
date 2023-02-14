//******** PRACTICA VISUALITZACI� 3D (Facultat de Ci�ncies / Escola d'Enginyeria - UAB)
//******** Entorn b�sic VS2019 MULTIFINESTRA amb OpenGL, interf�cie MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Setembre 2021)
// EntornV3DView.h : interface of the CEntornV3D class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "MainFrm.h"

// Entorn V3D: Constants de l'aplicaci� entorn V3D
#include "constants.h"

// Entorn V3D: Includes shaders GLSL
#include <gl/glew.h>
#include <gl/wglew.h>

// Entorn V3D: Llibreries OpenGL
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <gl/glut.h>

// Entorn V3D: OBJECTE 3DS. Include per la definici� de l'objecte Obj_3DS
#include "Obj3DS.h"	

// Entorn V3D: OBJECTE OBJ. Include per la definici� de l'objecte Obj_OBJ
#include "objLoader.h"

// Entorn V3D. QUATERNIONS: Include per a la definici� del tipus GL_QUAT i crida a les funcions de quatern.
#include "quatern.h"	

class CEntornV3DView : public CView
{
protected: // Crear s�lo a partir de serializaci�n
	CEntornV3DView();
	DECLARE_DYNCREATE(CEntornV3DView)

// Atributos
public:
	CEntornV3DDoc* GetDocument() const;

//-------------- Entorn V3D: Variables globals de CPractivaView
	HGLRC	 m_hrc;		// OpenGL Rendering Context 

// Entorn V3D: Variables de control per Men� C�mera: Esf�rica, Navega, M�bil, Zoom, Satelit, Polars... 
	char camera;	// Variable que controla el tipus de c�mera segons valors definits en constants.h
	bool mobil;	 // Opci� canvi de Punt de Vista interactiu (mobil) [0:NO,1:SI]
	bool zzoom;	 // Opci� Zoom interactiu (zoom) [0:NO,1:SI]
	bool zzoomO;	// Opci� Zoom en Projecci� Ortogr�fica adaptant Volum Visualitzaci� [0:NO,1:SI]
	bool satelit; // Opci� de navegaci� animada al volt de l'objecte centrat definint increment per mouse (SAT�LIT)
	//bool navega; // Opci� Navega [F:NO,T:SI].

// Entorn V3D: Variables de control per Men� Vista: fullscreen, pan, dibuixar eixos i grid 
	bool fullscreen;	// Opci� booleana per Pantalla Completal [0:NO,1:SI]
	bool pan;    // Opcio Pan. Despla�ament del centre de l'esfera de Vista [0:NO,1:SI]
	bool eixos;	 // Opci� per dibuixar els eixos X,Y,Z (Eixos?) [0:NO,1:SI]
	bool sw_grid; // Opci� per activar comandes teclat per moure grids [TRUE] o no [FALSE]
	CMask3D grid; // Opci� per a dibuixar grids (.x: grid XY, .y:grid XZ, .z: grid YZ, .w:grid XYZ)
	CPunt3D hgrid; // Al�ada de cada grid (.x: grid XY, .y:grid XZ, .z: grid YZ, .w:grid XYZ)

// Entorn V3D: Variables de l'opci� Vista->Pan
	float fact_pan;	  // Factor de despla�ament de la c�mara (opci� pan).
	CPunt3D tr_cpv;   // Vector de Traslaci� del Centre del Punt de Vista actiu dins opci� pan.
	CPunt3D tr_cpvF;  // Vector de Traslaci� del Centre del Punt de Vista (fixat amb INSERT dins opci� pan) 
					  //       i actiu fora l'opci� pan.

// Entorn V3D: Variables de control de l'opci� C�mera->Loxodroma_T*?
	GLfloat cam_t;  // Par�metre de la corba Loxodroma que defineix la posici� de la c�mera.
	CPunt3D nCam;   // Punt cap on mira.
	CPunt3D vCam;   // Definici� vector v de la c�mera (en coordenades m�n)
	bool animaCamLxd;	// Activaci� [TRUE] /Desactivaci� [FALSE] de l'animaci� de la C�mera Loxodroma.
	bool palante;		// Indica la direcci� de l'animaci� de la c�mera Loxodroma (esquerra [TRUE] o dreta [FALSE])
	
// Entorn V3D: Variables de control de l'opci� Vista->Navega?
	GLdouble n[3];   // Punt cap on mira.
	CPunt3D opvN;   // Definici� Or�gen C�mera (en coordenades m�n)
	float angleZ;   // angle de rotaci� de la traject�ria.

// Entorn V3D: Variables de control per les opcions de men� Projecci�, Objecte
	char projeccio;	// Men� Projecci�: Tipus de projeccio 
	char objecte;	// Men� Objecte: Tipus d'Objecte

// Entorn V3D: Variables de control del men� Transforma
	bool transf;	// Booleana per activar Transformacions (true) o no (false).
	bool trasl;		// Booleana d'activaci� de la Traslaci� (true) o no (false).
	bool rota;		// Booleana d'activaci� de la Rotaci� (true) o no (false).
	bool escal;		// Booleana d'activaci� de l'Escalatge (true) o no (false).
	float fact_Tras, fact_Rota;	// Increments de Traslaci� i Rotaci�.
	INSTANCIA TG;	// Estructura que cont� TG del men� Transforma actiu dins qualsevol opci� de Transforma 
					//      (Traslaci� Rotaci� i Escalatge).
	INSTANCIA TGF;	// Estructura que cont� TG del men� Transforma fixat amb INSERT dins les opcions de Transforma
					//     i actiu fora l'opci� Transforma.
	bool transX;	// Opci� Mobil Eix X?: TG interactives per l'eix X via mouse [F:NO,T:SI].
	bool transY;	// Opci� Mobil Eix Y?: TG interactives per l'eix Y via mouse [F:NO,T:SI].
	bool transZ;	// Opci� Mobil Eix Z?: TG interactives per l'eix Z via mouse [F:NO,T:SI].

// Entorn V3D: Variables de control per les opcions de men� Ocultacions
	bool front_faces;// Men� ocultacions: Determina si les cares visibles s�n les frontals [true-defecte] o les back [false] pel Test de Visibilitat.
	bool test_vis;  // Men� ocultacions: Activa [true] o desactiva [false] Test Visibilitat.
	bool oculta;    // Men� ocultacions: Activa [true] o desactiva [false] Ocultacions (Z-buffer).
	bool back_line; // Men� ocultacions: Activa [true] o desactiva [false] dibuix cares back com a l�nies.

// Entorn V3D: Variables de control del men� Iluminaci�	
	bool ifixe;         // Iluminaci� fixe independent del PV (ifixe=1) 
						// o depenent (mobil) respecte el PV (casc miner) (ifixe=0)
	bool ilum2sides;	// Iluminaci� de les cares FRONT i BACK [TRUE] o nom�s les FRONT [FALSE]
	char ilumina;		// Tipus d'il.luminaci� [FILFERROS 'f',PLANA 'c',SUAU 'c']
	bool sw_material[4];// Variable que controla els coeficients de reflectivitat del material [TRUE] o no [FALSE]:
						// [0]: emission, [1]: ambient, [2]: difusa, [3] especular.
	bool sw_material_old[4]; // Variable que guarda els valors de sw_material mentre no hi ha reflectivitat de material (refl_material=false).
	bool textura;       // Control de textures desactivades [0:NO] o activades [1:SI]
	char t_textura;		// Tipus de textures (predefinides o per fitxer)
	GLint texturesID[NUM_MAX_TEXTURES];	// Vector d'identificadors de textura de l'entorn. Si no hi ha textura activa, agafa el valor -1.
									// 0: Textura general, assignada a la lectura de fitxer.
									// 1-6: Textures de l'objecte Truck
									// 7-9: Lliures

// Entorn V3D: Variables de control del men� Llums
	bool llum_ambient;	// Booleana que controla la llum ambient (SI/NO).
	LLUM llumGL[NUM_MAX_LLUMS];		// Vector de llums d'OpenGL
	bool sw_llambient;	// Booleana que controla modus de configurar el color de la llum ambient [TRUE] o no [FALSE]
	CColor col_llambient;// Color llum ambient.

// Entorn V3D: Variables de control del men� Shaders
	bool sw_shader;			// Variable que controla si els shaders s�n actius [TRUE] o no [FALSE]
	char shader_menu;		// Variable que defineix el shader actiu
	GLuint shader_program;	// Shader Program que cont� el Vertex i Fragment program.

// Entorn V3D: Variables butons de mouse 
	CPoint m_PosEAvall, m_PosDAvall; // Coordenades del cursor quan el boto esquerre(E) o dret(D) del 
									 //    mouse ha estat clicat.
	bool m_ButoEAvall, m_ButoDAvall; //TRUE si el boto esquerre(E) o dret(D) del mouse esta clicat.
	CEsfe3D m_EsfeEAvall;			 // Coordenades Esf�riques del PV (OPV) quan el boto esquerre(E) o dret(D) del 
	//										mouse ha estat clicat.
	CEsfe3D m_EsfeIncEAvall;		 // Increment de despla�ament en coordenades Esf�riques del PV (OPV).

// Entorn V3D: Variables que controlen par�metres visualitzaci�: Mides finestra Windows i PV
	int w, h;				// Mides de la finestra Windows (w-amplada,h-al�ada)
	int w_old, h_old;		// Mides de la finestra Windows (w-amplada,h-al�ada) per restaurar Finestra des de fullscreen
	CEsfe3D OPV;			// Par�metres camera en coord. esf�riques (R,alfa,beta)
	char Vis_Polar;			// Variable que controla orientaci� dels eixos en Visualitzaci� Interactiva (POLARZ,POLARY,POLARX)

// Entorn V3D: Color de fons i de l'objecte
	bool fonsR, fonsG, fonsB;	// Booleanes per controlar variaci� de color per teclat.
	CColor c_fons;			// Intensitat de color de fons.
	bool sw_color;			// Booleana que controla el modus de configurar color de l'objecte per teclat [TRUE] o no [FALSE]
	CColor col_obj;			// Color de l'objecte simple.

// Entorn V3D: Objecte 3DS:
	Obj_3DS* Ob3DS;			// Variable d'objecte 3D Studio (*.3DS)

// Entorn V3D: Objecte OBJ:
	COBJModel* ObOBJ;		// Variable d'objecte format OBJ (*.OBJ)

// V3D: OBJECTE --> Corbes lemniscata, Bezier i BSpline
	int npts_T;							// N�mero de punts de control de la corba en el Vector corbaSpline (<=MAX_PATH_SPLINE)
	CPunt3D PC_t[MAX_PATCH_CORBA];		// Vector que enmagatzema Punts de Control Corba Spline
	GLdouble pas_Corba;					// Increment del par�metre t per al dibuix de les corbes.

	GLdouble pas_CS;						// Increment del par�metre t per al dibuix de corbes i superficies.
	bool sw_Punts_Control;				// Booleana que activa o desactiva la visualitzaci� dels punts de control de la corba o de la superficie

// Entorn V3D. TRIEDRE DE FRENET / DARBOUX: VT: vector Tangent, VNP: Vector Normal Principal, VBN: vector BiNormal
	bool dibuixa_TriedreFrenet;			// Booleana que controla dibuix de Triedre de Frenet per a cada punt de la Corba [TRUE-dibuixa, FALSE-no dibuixa]
	bool dibuixa_TriedreDarboux;		// Booleana que controla dibuix de Triedre de Frenet per a cada punt de la Corba [TRUE-dibuixa, FALSE-no dibuixa]
	CPunt3D VT, VNP, VBN;				// TRIEDRE de FRENET: VT: Vector Tangent, VNP: Vector Normal Principal, VBN: Vector BiNormal.

// Entorn V3D: Variables de l'objecte FRACTAL
	char t_fractal;		// Tipus de fractal.
	char soroll;		// Men� Fractals: Tipus de soroll
	int pas, pas_ini;	// Resoluci� del fractal inicial (pas_ini) i de visualitzaci� (pas).
	bool sw_il;			// Booleana que controla si cal compilar el fractal (sw_il=1) o no (sw_il=0)
	bool palcolFractal;	// Booleana que activa coloraci� del fractal segons paleta de colors [TRUE] o no [FALSE].

// Entorn V3D. QUATERNIONS: Animaci� de cossos r�gids per QUATERNIONS
	bool rotaQ;				// Booleana que verifica si les rotacions es fan per Quaternions.
	int np_InQ=0;				// Controla el n�mero de keyframes entrats.
	bool animaQ=false;			// Booleana que controla si l'animaci� r�gida �s activa (TRUE) o no (FALSE).
	char interpolacio;
	unsigned index=0;
	float temps = 1.0f / NFRAMES_Q;
	CPunt3D keyf_Rota[MAX_KEYFRAMES_Q]; // Estructura que guarda fins a 3 keyframes d'orientaci� de l'objecte r�gid
										//	en angles d'Euler. Es graben amb la tecla INSERT.
	GL_Quat keyf_Quat[MAX_KEYFRAMES_Q]; // Estructura que guarda fins a 3 keyframes d'orientaci� de l'objecte r�gid
										//	en Quaternions. Es graben amb la tecla INSERT.
	CPunt3D keyf_Tras[MAX_KEYFRAMES_Q]; // Estructura que guarda fins a 3 keyframes de TRASLACI� de 
//										//	l'objecte r�gid. Es graben amb la tecla INSERT.
	CPunt3D int_Tras;		// Valors de Traslaci� interpolats en moviment rigid.
	GL_Quat qI, qF, qT;		// Quaternions inicial (qI), final (qF) i intermig (qT) del
							//	    moviment d'objectes r�gids.
	GLdouble QMatrix[16];	// Matriu de rotaci� corresponent a un quaterni�.

 //Entorn V3D.ESCENA: Definici� variables animaci� ESCENA
	float t=0;				// Par�metre t pel Timer.
	float delta;			// Increment de la traject�ria
	bool adelante = true;
	bool animaE;			// Booleana que controla si l'animaci� �s activa (TRUE) o no (FALSE)
							//    dins la funci� de control del rellotge OnTimer.
	CPunt3D ctr[4];			// Punts control del patch del BSpline.
	int patch;				// Patch actual de la corba que es tracta.
	//CPunt3D VT, VNP, VBN;	// TRIEDRE de FRENET: VT: Vector Tangent, VNP: Vector Normal Principal, VBN: Vector BiNormal.
	CPunt3D pos_traject;	// Posici� (x,y,z) de la traject�ria.
	CPunt3D angle_traject;  // Orientaci� de l'objecte en angles d'Euler


// Entorn V3D: Altres variables
	GLdouble mida;	// Factor d'escala per calcular Volum de Visualitzaci� de l'objecte que encaixi.
	CString nom;	// Nom de fitxer.
	CString buffer; // Buffer que magatzema string caracters corresponent a variables float a printar en Status Bar (funci� Barra_Estat).
//-------------- Entorn V3D: Fi De Variables globals de CEntornV3DView

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Funcions de c�rrega i activaci� de shaders
	void InitAPI();
	void GetGLVersion(int* major, int* minor);
	void OnInitialUpdate();

// Implementaci�n
public:
	virtual ~CEntornV3DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void CEntornV3DView::configura_Escena();
	void CEntornV3DView::dibuixa_Escena();
	void CEntornV3DView::Barra_Estat();
	void CEntornV3DView::float2CString(float varf);
	int CEntornV3DView::Log2(int num);							// Log2: C�lcul del log base 2 de num
	char * CEntornV3DView::CString2Char(CString entrada);		// Conversi� string CString --> char *
	void CEntornV3DView::Refl_MaterialOff();					// Desactivar Reflexi� de Material
	void CEntornV3DView::Refl_MaterialOn();						// Activar Reflexi� de Material
	int CEntornV3DView::llegir_ptsC(char *nomf);				// Lectura Punts de Control Corba (B-spline o Bezier)

// Entorn V3D: Funcions de c�rrega i activaci� de shaders
	GLuint CEntornV3DView::initializeShaders(CString filename);
	GLuint CEntornV3DView::loadFileShaders(CString file_Vert, CString file_Frag);
	char *CEntornV3DView::textFileRead(char *fn);
	void CEntornV3DView::releaseAllShaders();

// // Entorn V3D: Funcions de tractament de teclat en diferents modus
	void CEntornV3DView::Teclat_Camera_Loxodroma(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_PasCorbes(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_Escena(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_ColorObjecte(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_ColorFons(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_Navega(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_Pan(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_TransEscala(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_TransRota(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_TransTraslada(UINT nChar, UINT nRepCnt);
	void CEntornV3DView::Teclat_Grid(UINT nChar, UINT nRepCnt);

	CMFCStatusBar& GetStatusBar() const
	{
		return ((CMainFrame*)AfxGetMainWnd())->GetStatusBar();
	}

// Variables Full Screen
protected:
	CWnd *saveParent;
	CMenu *ContextMenu;

private:

//Rendering Context and Device Context Pointers
	HGLRC     m_hRC;
	CDC*      m_pDC;

// Funciones de asignaci�n de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnArxiuObrirFractal();
	afx_msg void OnArxiuObrirFitxerObj();
	afx_msg void OnArxiuObrirFitxer3ds();
	afx_msg void OnVistaMobil();
	afx_msg void OnUpdateVistaMobil(CCmdUI *pCmdUI);
	afx_msg void OnVistaZoom();
	afx_msg void OnUpdateVistaZoom(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsX();
	afx_msg void OnUpdateVistaPolarsX(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsY();
	afx_msg void OnUpdateVistaPolarsY(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsZ();
	afx_msg void OnUpdateVistaPolarsZ(CCmdUI *pCmdUI);
	afx_msg void OnVistaPan();
	afx_msg void OnUpdateVistaPan(CCmdUI *pCmdUI);
	afx_msg void OnVistaOrigenpan();
	afx_msg void OnVistaNavega();
	afx_msg void OnUpdateVistaNavega(CCmdUI *pCmdUI);
	afx_msg void OnVistaOrigennavega();
	afx_msg void OnVistaEixos();
	afx_msg void OnUpdateVistaEixos(CCmdUI *pCmdUI);
	afx_msg void OnProjeccioPerspectiva();
	afx_msg void OnUpdateProjeccioPerspectiva(CCmdUI *pCmdUI);
	afx_msg void OnObjecteCub();
	afx_msg void OnUpdateObjecteCub(CCmdUI *pCmdUI);
	afx_msg void OnObjecteEsfera();
	afx_msg void OnUpdateObjecteEsfera(CCmdUI *pCmdUI);
	afx_msg void OnObjecteTetera();
	afx_msg void OnUpdateObjecteTetera(CCmdUI *pCmdUI);
	afx_msg void OnObjecteTruck();
	afx_msg void OnUpdateObjecteTruck(CCmdUI *pCmdUI);
	afx_msg void OnTransformaTraslacio();
	afx_msg void OnUpdateTransformaTraslacio(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigentraslacio();
	afx_msg void OnTransformaRotacio();
	afx_msg void OnUpdateTransformaRotacio(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigenrotacio();
	afx_msg void OnTransformaEscalat();
	afx_msg void OnUpdateTransformaEscalat(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigenescalat();
	afx_msg void OnTransformaMobilx();
	afx_msg void OnUpdateTransformaMobilx(CCmdUI *pCmdUI);
	afx_msg void OnTransformaMobily();
	afx_msg void OnUpdateTransformaMobily(CCmdUI *pCmdUI);
	afx_msg void OnTransformaMobilz();
	afx_msg void OnUpdateTransformaMobilz(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsTestvis();
	afx_msg void OnUpdateOcultacionsTestvis(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsZbuffer();
	afx_msg void OnUpdateOcultacionsZbuffer(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsBackline();
	afx_msg void OnUpdateOcultacionsBackline(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioLlumfixe();
	afx_msg void OnUpdateIluminacioLlumfixe(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioFilferros();
	afx_msg void OnUpdateIluminacioFilferros(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioPlana();
	afx_msg void OnUpdateIluminacioPlana(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioGouraud();
	afx_msg void OnUpdateIluminacioGouraud(CCmdUI *pCmdUI);
	afx_msg void OnMaterialEmissio();
	afx_msg void OnUpdateMaterialEmissio(CCmdUI *pCmdUI);
	afx_msg void OnMaterialAmbient();
	afx_msg void OnUpdateMaterialAmbient(CCmdUI *pCmdUI);
	afx_msg void OnMaterialDifusa();
	afx_msg void OnUpdateMaterialDifusa(CCmdUI *pCmdUI);
	afx_msg void OnMaterialEspecular();
	afx_msg void OnUpdateMaterialEspecular(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioTextures();
	afx_msg void OnUpdateIluminacioTextures(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioTexturaFitxerimatge();
	afx_msg void OnUpdateIluminacioTexturaFitxerimatge(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlumambient();
	afx_msg void OnUpdateLlumsLlumambient(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum0();
	afx_msg void OnUpdateLlumsLlum0(CCmdUI *pCmdUI);
	afx_msg void OnShadersSense();
	afx_msg void OnUpdateShadersSense(CCmdUI *pCmdUI);
	afx_msg void OnShadersGouraud();
	afx_msg void OnUpdateShadersGouraud(CCmdUI *pCmdUI);
	afx_msg void OnShadersPhong();
	afx_msg void OnUpdateShadersPhong(CCmdUI *pCmdUI);
	afx_msg void OnVistaSatelit();
	afx_msg void OnUpdateVistaSatelit(CCmdUI *pCmdUI);
	afx_msg void OnVistaFullscreen();
	afx_msg void OnUpdateVistaFullscreen(CCmdUI *pCmdUI);
	afx_msg void OnObjecteCubRGB();
	afx_msg void OnUpdateObjecteCubRGB(CCmdUI *pCmdUI);
	afx_msg void OnObjecteTie();
	afx_msg void OnUpdateObjecteTie(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioPunts();
	afx_msg void OnUpdateIluminacioPunts(CCmdUI *pCmdUI);
	afx_msg void OnShaderLoadFiles();
	afx_msg void OnUpdateShaderLoadFiles(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsFrontFaces();
	afx_msg void OnUpdateOcultacionsFrontFaces(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum1();
	afx_msg void OnUpdateLlumsLlum1(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum2();
	afx_msg void OnUpdateLlumsLlum2(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum3();
	afx_msg void OnUpdateLlumsLlum3(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum4();
	afx_msg void OnUpdateLlumsLlum4(CCmdUI *pCmdUI);
	afx_msg void OnObjeteCorbaBezier();
	afx_msg void OnUpdateObjeteCorbaBezier(CCmdUI *pCmdUI);
	afx_msg void OnObjecteCorbaLemniscata();
	afx_msg void OnUpdateObjecteCorbaLemniscata(CCmdUI *pCmdUI);
	afx_msg void OnObjecteCorbaBSpline();
	afx_msg void OnUpdateObjecteCorbaBSpline(CCmdUI *pCmdUI);
	afx_msg void OnObjectePuntsControl();
	afx_msg void OnUpdateObjectePuntsControl(CCmdUI *pCmdUI);
	afx_msg void OnVistaGridXY();
	afx_msg void OnUpdateVistaGridXY(CCmdUI *pCmdUI);
	afx_msg void OnVistaGridXZ();
	afx_msg void OnUpdateVistaGridXZ(CCmdUI *pCmdUI);
	afx_msg void OnVistaGridYZ();
	afx_msg void OnUpdateVistaGridYZ(CCmdUI *pCmdUI);
	afx_msg void OnVistaGridXYZ();
	afx_msg void OnUpdateVistaGridXYZ(CCmdUI *pCmdUI);
	afx_msg void OnIluminacio2Sides();
	afx_msg void OnUpdateIluminacio2Sides(CCmdUI *pCmdUI);
//	afx_msg void OnObjecteEscena();
//	afx_msg void OnUpdateObjecteEscena(CCmdUI *pCmdUI);
	afx_msg void OnObjecteEscenaTfrenet();
	afx_msg void OnUpdateObjecteEscenaTFrenet(CCmdUI *pCmdUI);
	afx_msg void OnObjecteEscena();
	afx_msg void OnUpdateObjecteEscena(CCmdUI *pCmdUI);
	afx_msg void OnCameraEsferica();
	afx_msg void OnUpdateCameraEsferica(CCmdUI* pCmdUI);
	afx_msg void OnObjecteEscenaLoxodroma();
	afx_msg void OnUpdateObjecteEscenaLoxodroma(CCmdUI* pCmdUI);
	afx_msg void OnCorbesTriedreFrenet();
	afx_msg void OnUpdateCorbesTriedreFrenet(CCmdUI* pCmdUI);
	afx_msg void OnProjeccioOrtografica();
	afx_msg void OnUpdateProjeccioOrtografica(CCmdUI* pCmdUI);
	afx_msg void OnProjeccioAxonometrica();
	afx_msg void OnUpdateProjeccioAxonometrica(CCmdUI* pCmdUI);
	afx_msg void OnTransforma_Quaternions();
	afx_msg void OnObjecteCamion();
	afx_msg void OnUpdateObjecteCamion(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTransformaQuaternions(CCmdUI* pCmdUI);
	afx_msg void OnTransformaLerp();
	afx_msg void OnUpdateTransformaLerp(CCmdUI* pCmdUI);
	afx_msg void OnTransformaSlerp();
	afx_msg void OnUpdateTransformaSlerp(CCmdUI* pCmdUI);
	afx_msg void OnObjectePato();
	afx_msg void OnUpdateObjectePato(CCmdUI* pCmdUI);
	afx_msg void OnLoxodromaLoxodroma32891();
	afx_msg void OnUpdateLoxodromaLoxodroma32891(CCmdUI* pCmdUI);
	afx_msg void OnLoxodromaLoxodroma32892();
	afx_msg void OnUpdateLoxodromaLoxodroma32892(CCmdUI* pCmdUI);
	afx_msg void OnLoxodromaLoxodroma32893();
	afx_msg void OnUpdateLoxodromaLoxodroma32893(CCmdUI* pCmdUI);
	afx_msg void OnLoxodromaLoxodroma32894();
	afx_msg void OnUpdateLoxodromaLoxodroma32894(CCmdUI* pCmdUI);
	afx_msg void OnLoxodromaLoxodroma32895();
	afx_msg void OnUpdateLoxodromaLoxodroma32895(CCmdUI* pCmdUI);
	afx_msg void OnCorbesTriedrededarboux();
	afx_msg void OnUpdateCorbesTriedrededarboux(CCmdUI* pCmdUI);
	afx_msg void OnC32897();
	afx_msg void OnUpdateC32897(CCmdUI* pCmdUI);
	afx_msg void OnC32898();
	afx_msg void OnUpdateC32898(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // Versi�n de depuraci�n en EntornV3DView.cpp
inline CEntornV3DDoc* CEntornV3DView::GetDocument() const
   { return reinterpret_cast<CEntornV3DDoc*>(m_pDocument); }
#endif


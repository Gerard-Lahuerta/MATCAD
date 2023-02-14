//******** PRACTICA VISUALITZACI� 3D (Facultat de Ci�ncies / Escola d'Enginyeria - UAB)
//******** Entorn b�sic VS2019 MULTIFINESTRA amb OpenGL, interf�cie MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Setembre 2021)
// constants.h : Definici� de constants compartides a
//				 CENtornV3DView.cpp, visualitzacio.cpp i escena.cpp


#ifndef CONST_H
#define CONST_H

//--------------- V3D: Tipus de C�mera
#define CAP ' '
#define CAM_ESFERICA 'E'
#define CAM_GEODE 'G'
#define CAM_LOXODROMA_TFRENET 'F'
#define CAM_LOXODROMA_TDARBOUX 'D'
#define CAM_NAVEGA 'N'

//--------------- V3D: Tipus de Projecci�
#define AXONOM 'A'
#define ORTO 'O'
#define PERSPECT 'P'
#define IMA_PICK 3
#define PASSEIG_V 4

//--------------- V3D: Tipus de Polars (per la Visualitzaci� Interactiva)
#define POLARZ 'Z'
#define POLARY 'Y'
#define POLARX 'X'

//-------------- V3D: Tipus d'Objectes 
#define CAMIO 'm'
#define CILINDRE 'y'
#define CUB 'c'
#define CUB_RGB 'C'
#define C_BEZIER '2'
#define C_LEMNISCATA 'K'
#define C_LOXODROMA 'X'
#define C_BSPLINE 'q'
#define ESFERA 'e'
#define ESCENA_LOXODROMA 'M'
#define ESCENA_TFRENET 'F'
#define O_FRACTAL 'f'
#define HIDROAVIO 'H'
#define PATO 'p'
#define TETERA 't'
#define TIE 'I'
#define TRUCK 'T'
#define VAIXELL 'v'
#define OBJ3DS '3'		// Objecte format 3DS
#define OBJOBJ '4'		// Objecte format OBJ
//-------------- V3D: Tipus d'interpolaci�
#define ESFERICA 'S'
#define LINEAL 'L'

//-------------- V3D: Tipus d'Iluminacio
#define PUNTS 'P'
#define FILFERROS 'f'
#define PLANA 'p'
#define GOURAUD 'g'

//-------------- V3D: Tipus de corbes
#define LOXO025 '0'
#define LOXO05 '5'
#define LOXO1 '1'
#define LOXO2 '2'
#define LOXO4 '4'

//-------------- V3D: Objectes precompilats OpenGL amb glNewList
#define EIXOS 1			// Eixos
#define FRACTAL 2		// Fractal
#define OBJECTE3DS 3	// Objecte 3DS sense textures
#define OBJECTE3DST 4	// Objecte 3DS amb textures
#define OBJECTEOBJ 5	// Objecte OBJ sense textures
#define OBJECTEOBJT 6   // Objecte OBJ amb textures

// -------------- V3D: Definici� dels valors del pla near i far del Volum de Visualitzaci� en Perspectiva
const GLdouble p_near=1;
const GLdouble p_far=50000;

//-------------- V3D: Tipus d'Objectes Picking
#define PICKCAP 0
#define PICKFAR 1
#define PICKVAIXELL 2 
#define PICKHIDRO 3 

// -------------- V3D: CONSTANTS TEXTURES
// Nombre m�xim de textures
#define NUM_MAX_TEXTURES 10

// Tipus de textures
#define CAP ' '
#define FUSTA 'F'
#define MARBRE 'M'
#define METALL 'E'
#define FITXER 'f'
#define FITXERBMP 'f'
#define FITXERIMA 'I'

// --------------  V3D: NOMBRE DE LLUMS: Nombre de Llums de l'aplicaci�, les d'OpenGL
const int NUM_MAX_LLUMS = 8;

// Permet prendre les funcions _s enlloc de les deprecated (strcpy -> strcpy_s). Ja definit
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

// Elimina missatges warning que venen de crides deprecated (strcpy -> strcpy_s).
//#define _CRT_SECURE_NO_WARNINGS -> Posat a "Project"->"Properties"->"Configuration properties"->"C/C++"->"Preprocessor"->"Preprocessor definitions".

// -------------- V3D: SHADERS --> Tipus de Shaders
#define CAP_SHADER ' '
#define GOURAUD_SHADER 'G'
#define PHONG_SHADER 'P'
#define GOURAUD_TOON 'g'
#define PHONG_TOON 'p'
#define FILE_SHADER 'f'

//--------------- V3D: Valor constant de pi
const GLdouble pi=3.14159;
const GLdouble TWOPI = 2 * pi;
const GLdouble PID2 = pi / 2;
//const double pi=3.14159265358979323846264338327950288419716939937510f;

// --------------- GMS. GRID
#define GRID_SIZE 50	// Maximum size of the grid in OpenGL World Coordenates unities.
#define PAS_GRID 1		// Step to shift the grid planes.

// --------------- V3D. TRUCK: Resoluci� de les rodes (Nombre de divisions del cilindre i discos)
#define RESOLUCIO_RODA 16

// --------------- V3D. CAMERA / ESCENA LOXODROMA
const GLfloat a_CamLoxo = 0.125; // Par�metre a per a la corba Loxodroma que defineix la C�mera i l'Escena Loxodroma 
const GLfloat tmin_CamLoxo = -15; // M�nim del par�metre t per a la corba Loxodroma que defineix la C�mera i l'Escena Loxodroma 
const GLfloat tmax_CamLoxo = 15; // M�nim del par�metre t per a la corba Loxodroma que defineix la C�mera i l'Escena Loxodroma 

/* --------------- V3D: Estructura coordenada 2D (Ja definida en Visual Studio 2010)
struct CPoint
{   GLint x;
    GLint y;
};
*/

// --------------- V3D: Estructura coordenada 3D
struct CPunt3D
{   GLdouble x;
    GLdouble y;
	GLdouble z;
	GLdouble w;
};

// --------------- GMS: 3M�scara booleana sobre coordenades 3D
struct CMask3D
{
	bool x;
	bool y;
	bool z;
	bool w;
};

// --------------- V3D: Estructura de color R,G,B,A
struct CColor
{   GLdouble r;
    GLdouble g;
	GLdouble b;
	GLdouble a;
};

// --------------- V3D: Estructura coordenada Esf�rica 3D
struct CEsfe3D
{   GLdouble R;
    GLdouble alfa;
	GLdouble beta;
};

// --------------- V3D: INSTANCIA (TG d'instanciaci� d'un objecte)
struct INSTANCIA
{	CPunt3D VTras;	// Vector de Traslaci�
	CPunt3D VScal;	// Vector d'Escalatge
	CPunt3D VRota;	// Vector de Rotaci�
};

// --------------- V3D: Coeficients equaci� d'atenuaci� de la llum fatt=1/(ad2+bd+c)
struct CAtenua
{   GLfloat a;
    GLfloat b;
	GLfloat c;
};

// --------------- V3D: Estructura de coeficients de reflectivitat de materials
struct MATERIAL
{
	GLdouble ambient[4];
	GLdouble diffuse[4];
	GLdouble specular[4];
	GLdouble emission[4];
	GLdouble shininess;
};

// --------------- V3D: Estructura font de llum
struct LLUM
{	bool encesa;		// Booleana que controla si la llum �s encesa [TRUE] o no [FALSE]
	CEsfe3D posicio;	// Posici� d ela foont de llum en coordenades esf�riques.
	GLfloat difusa[4];	// Intensitat difusa de la font de llum (r,g,b,a)
	GLfloat especular[4];	// Intensitat especular de la font de llum (r,g,b,a)
	CAtenua atenuacio;		// Coeficients de l'equaci� d'atenuaci� de la llum fatt=1/(ad2+bd+c)
	bool restringida;		// Booleana que indica si la font de llum �s restringida [TRUE] i per tant s�n v�lids els coeficients posteriors o no [FALSE].
	GLfloat spotdirection[3];	// vector de direci� de la font de llum restringida (x,y,z).
	GLfloat cutoff;			// Angle d'obertura de la font de llum restringida.
	GLfloat exponent;		// Exponent que indica l'atenuaci� de la font del centre de l'eix a l'exterior, segons model de Warn.
};

#endif
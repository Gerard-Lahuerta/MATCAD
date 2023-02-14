//******** PRACTICA VISUALITZACI� 3D (Facultat de Ci�ncies / Escola d'Enginyeria - UAB)
//******** Entorn b�sic VS2019 MULTIFINESTRA amb OpenGL, interf�cie MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Setembre 2021)
// escena.h : interface de escena.cpp
//

#ifndef GLSOURCE_H
#define GLSOURCE_H
/* ------------------------------------------------------------------------- */
/*                            Funcions de les escenes                        */
/* ------------------------------------------------------------------------- */
// Entorn V3D: dibuixa_EscenaGL -> Dibuix de l'escena GL
void dibuixa_EscenaGL(char objecte, CColor col_object, bool ref_mat, bool sw_mat[4],
	bool textur, GLint texturID[NUM_MAX_TEXTURES],
	int nptsU, CPunt3D PC_u[MAX_PATCH_CORBA], GLdouble pasCS, bool sw_PC,GLdouble QMat[16],
	bool dib_TFrenet, bool dib_TDarboux, GLfloat croata);

// Entorn V3D: dibuixa -> Funci� que dibuixa objectes simples de la llibreria GLUT segons obj
void dibuixa(char obj);

// Entorn V3D. ESCENA: dibuixaEscena_Fixe: Funci� que dibuixa tots els elements fixes d'ESCENA.
void dibuixaEscena_Fixe(GLint CloudsT);

// Entorn V3D. ESCENA: dibuixaEscena: Funci� que dibuixa tots els elements de l'ESCENA, tant fixes com m�bils.
void dibuixaEscena(GLint CloudsT, bool transparent, CPunt3D pos_t, CPunt3D angles_t, GLdouble QMat[16]);

// Entorn V3D: Truck - Objecte fet per alumnes.
void truck(bool textu,GLint VTextu[NUM_MAX_TEXTURES]);
void neumatic(bool textur, GLint VTextur[NUM_MAX_TEXTURES]);
void llanta(bool textur, GLint VTextur[NUM_MAX_TEXTURES]);
void sea(void);

// Entorn V3D: Tie (Nau enemiga Star Wars) - Objecte fet per alumnes.
void tie();
void Alas();
void Motor();
void Canon();
void Cuerpo();
void Cabina();
#endif
// Common.h : Contient toutes les define, et les définitions de variables
// 
///////////////////////////////////////////////////////////////////////////////////////

#ifndef		__COMMON_H__
#define		__COMMON_H__

#include "math.h"

// Définition d'un point du graphe
typedef struct {
	float x;
	float y;
}	HistoPointData;

typedef struct {
	unsigned char b;
	unsigned char g;
	unsigned char r;
} RvbValues;

class CBitmapManipulations;

typedef struct { 
	CBitmapManipulations *bmpManip;
	CView* pView;
} CallStruct;

// Liste des defines

// Les defines utilisées pour dessiner les flèches
#define FLECHE_EXT		1
#define FLECHE_ORG		2

// Les defines utilisées pour dessiner les quadrillages
#define QUADRILLAGE_X	1
#define	QUADRILLAGE_Y	2

// Les defines utilisées pour les types de histogrammes
#define HISTO_COURBE	1
#define HISTO_DISCRET	2
#define HISTO_POINTS	3

// Les defines utilisées pour choisir le type du graphique
#define PICTURE_HISTOGRAMME		1
#define CUMULATIF_HISTOGRAMME	2

#define PI	3.1415926535897932384626433832795

// Les defines utilisées pour la détection de contours
#define HORIZONTAL_DETECT	0
#define VERTICAL_DETECT		1
#define ALL_DETECT			2

// Liste de fonctions
int RvbCmp(RvbValues a, RvbValues b);
void RvbSet(RvbValues* a, RvbValues* b);
void Qsort(RvbValues a[], int lo0, int hi0);
UINT sort(LPVOID lpVoid);
void sort(int count, CPoint pt[], BOOL x_ord);
void insertionSort(RvbValues a[], int lo0, int hi0);
int dichotomicSearch(COLORREF clr[], COLORREF search, int lo, int hi);

// Tracage des flèches
void fleche(CDC *pDC, CRect rect, int type);

#endif	//	__COMMON_H__
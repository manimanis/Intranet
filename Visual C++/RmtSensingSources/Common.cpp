#include "stdafx.h"
#include "Common.h"

// Définition de la fonction de tracage des flèches
void fleche(CDC *pDC, CRect rect, int type)
{
	double sin_a, cos_a;
	double dx, dy;

	double sin_b = sin(PI / 12);
	double cos_b = cos(PI / 12);

	dx = (double)(rect.right - rect.left);
	dy = (double)(rect.bottom - rect.top);

	cos_a =  dx / sqrt(dx * dx + dy * dy);
	sin_a =  dy / sqrt(dx * dx + dy * dy);

	double cos_a_p_b = cos_a * cos_b - sin_a * sin_b;
	double sin_a_p_b = sin_a * cos_b + cos_a * sin_b;

	double cos_a_m_b = cos_a * cos_b + sin_a * sin_b;
	double sin_a_m_b = sin_a * cos_b - cos_a * sin_b;

	if ((!type) || ((type & FLECHE_ORG) == FLECHE_ORG))
	{
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.left + (int) (300 * cos_a_p_b),
					rect.top + (int) (300 * sin_a_p_b));

	
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.left + (int) (300 * cos_a_m_b),
					rect.top + (int) (300 * sin_a_m_b));
	}
	
	if ((!type) || ((type & FLECHE_EXT) == FLECHE_EXT))
	{
		pDC->MoveTo(rect.right, rect.bottom);
		pDC->LineTo(rect.right - (int) (300 * cos_a_p_b),
					rect.bottom - (int) (300 * sin_a_p_b));

		pDC->MoveTo(rect.right, rect.bottom);
		pDC->LineTo(rect.right - (int) (300 * cos_a_m_b),
				rect.bottom - (int) (300 * sin_a_m_b));
	}

	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.right, rect.bottom);
}

void sort(int count, CPoint pt[], BOOL x_ord)
{
	int min;
	CPoint swapper;

	if (x_ord)
		for (int i = 0 ; i < count - 1 ; i++)
		{
			min = i;
			for (int j = min ; j < count ; j++)
					if (pt[j].x < pt[min].x) min = j;
		
			swapper = pt[i];
			pt[i] = pt[min];
			pt[min] = swapper;
		}
	else
		for (int i = 0 ; i < (count - 1) ; i++)
		{
			min = i;
			for (int j = min ; j < count ; j++)
					if (pt[j].y < pt[min].y) min = j;
		
			swapper = pt[i];
			pt[i] = pt[min];
			pt[min] = swapper;
		}
}

int RvbCmp(RvbValues a, RvbValues b)
{
	int x = RGB(a.r, a.g, a.b),
		y = RGB(b.r, b.g, b.b);
	
	if (x > y) return 1; // a > b
		else if (x < y) return -1; // a < b

	return 0; // a = b
}


void RvbSet(RvbValues* a, RvbValues* b)
{
	memcpy(a, b, sizeof(RvbValues));
}

int dichotomicSearch(COLORREF clr[], COLORREF search, int lo, int hi)
{
	if (lo >= hi) return -1;

	if (clr[lo] == search) return lo;
	if (clr[hi] == search) return hi;

	int mid;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;

		if (clr[mid] == search) return mid;
			else if (clr[mid] > search) hi = --mid;
				else lo = ++mid;
	}

	return -1;
}
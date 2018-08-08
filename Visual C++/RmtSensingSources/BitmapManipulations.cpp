// BitmapManipulations.cpp: implementation of the CBitmapManipulations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "BitmapManipulations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int entry, maxentry;
CSemaphore sem;

CBitmapManipulations::CBitmapManipulations()
{
	iFile = "";
	IsOpened = FALSE;
	firstDrawCall = TRUE;
	ArraySize = 0;
	ColorArray = NULL;

	memset(picData, 0, sizeof(picData));
}

CBitmapManipulations::~CBitmapManipulations()
{
	if (ColorArray) delete [] ColorArray;

	memDC.DeleteDC();

	bmp.Detach();
	bmp.DeleteObject();
}

BOOL CBitmapManipulations::Open(CString FileName)
{
	iFile = FileName;
		
	IsOpened = FileStream.Open(iFile, CFile::modeReadWrite);

	if (IsOpened)
	{
		FileStream.Seek(0, CFile::begin);
		FileStream.Read(&bmpFileHeader, sizeof(bmpFileHeader));
		FileStream.Read(&bmpInfoHeader, sizeof(bmpInfoHeader));
	}

	return IsOpened;
}

void CBitmapManipulations::Close()
{
	FileStream.Close();
	IsOpened = FALSE;
}

BOOL CBitmapManipulations::IsValidBitmap()
{
	// Si l'entête de fichier est != de "BM" alors le bitmap n'est pas valide
	if (bmpFileHeader.bfType != 19778 /* = "BM" */) return FALSE;
	
	// Vérfie la taille de l'entête d'info
	if (bmpInfoHeader.biSize != 40) return FALSE;

	return TRUE;
}

int CBitmapManipulations::GetWidth()
{
	return bmpInfoHeader.biWidth;
}

int CBitmapManipulations::GetHeight()
{
	return bmpInfoHeader.biHeight;
}

WORD CBitmapManipulations::GetBitCount()
{
	return bmpInfoHeader.biBitCount;
}

BOOL CBitmapManipulations::IsCompressed()
{
	return (bmpInfoHeader.biCompression == BI_RGB);
}

// Crée une copie temporaire du fichier, ferme le fichier courant et ouvre le nouveau
BOOL CBitmapManipulations::CreateTempCopy(CString oFileName)
{
	CFile oFile;
	
	unsigned char *mem = new unsigned char [8192];
	if (!mem)
	{
		AfxMessageBox("Erreur : ne peut pas allouer de la mémoire dans\n"
						"BOOL CBitmapManipulations::CreateTempCopy()");
		return FALSE;
	}

	int FileLength = FileStream.GetLength(),
		Portions = FileLength / 8192,
		Reste = FileLength % 8192;

	FileStream.Close();
	FileStream.Open(iFile, CFile::modeRead);

	FileStream.Seek(0, CFile::begin);
	oFile.Open(oFileName, CFile::modeCreate | CFile :: modeWrite);
	
	for (int i = 0 ; i < Portions ; i++)
	{
		FileStream.Read(mem, 8192);
		oFile.Write(mem, 8192); 
	}

	if (Reste)
	{
		FileStream.Read(mem, Reste);
		oFile.Write(mem, Reste);
	}

	FileStream.Close();
	oFile.Close();

	FileStream.Open(iFile, CFile::modeReadWrite);

	delete [] mem;

	return TRUE;
}

int CBitmapManipulations::GetWidthBytes()
{
	int BmpWidth = bmpInfoHeader.biWidth * bmpInfoHeader.biBitCount; 

	return (((BmpWidth >> 5) + ((BmpWidth % 32) > 0)) << 2);
}

void CBitmapManipulations::Draw(CDC *pDC, CRect &rect)
{	
	if (firstDrawCall) 
	{
		firstDrawCall = FALSE;
		memDC.CreateCompatibleDC(pDC);	
	}
	
	memDC.SelectObject(&bmp);

	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, 
				bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, SRCCOPY);
}


// !!!!!!!!!!!! Uniquement 24 bits !!!!!!!!!!!!!!!
void CBitmapManipulations::GetHistogrammeInfo()
{
	memset(picData, 0, sizeof(picData));


	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return;
	}

	BITMAP bm; bmp.GetBitmap(&bm);

	FillPictureInfo(bmpInfoHeader.biHeight, (unsigned char *)bm.bmBits);
	FillCumulatifInfo();
}

void CBitmapManipulations::FillPictureInfo(int nbrScanLines, unsigned char *p)
{
	unsigned char *p1 = p;
	int WidthBytes = GetWidthBytes(), i, j;

	for (j = 0 ; j < nbrScanLines ; j++)
	{
		for (i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			picData[0][*(p + 0)]++; // Blue
			picData[1][*(p + 1)]++; // Green
			picData[2][*(p + 2)]++; // Red

			p += 3;
		}
		p = p1 + WidthBytes;
		p1 = p;
	}	
}

void CBitmapManipulations::FillCumulatifInfo()
{
	memcpy(cumData, picData, sizeof(picData));

	for (int j = 0 ; j < 3 ; j++)
		for (int i = 1 ; i < 256 ; i++)
			cumData[j][i] += cumData[j][i - 1];
}

BOOL CBitmapManipulations::MakeModification(CLookUpTables *lkUpTable)
{
	unsigned char rvblkUpTable[3][256];

	// On initialise la première instance de CLookUpTable
	lkUpTable->InitInstance();

	// On effectue une petite initialisation avant l'affichage
	lkUpTable->PreDlgShow((int *)picData, (int *)cumData);

	if (lkUpTable->DoModal() == IDCANCEL) return FALSE;

	// On traite les bleus
	lkUpTable->FillLookUpTable(256, picData[0]);
	memcpy(rvblkUpTable[0], lkUpTable->GetTable(), 256);
			

	// On traite les Verts
	lkUpTable->FillLookUpTable(256, picData[1]);
	memcpy(rvblkUpTable[1], lkUpTable->GetTable(), 256);

	// On traite les rouges
	lkUpTable->FillLookUpTable(256, picData[2]);
	memcpy(rvblkUpTable[2], lkUpTable->GetTable(), 256);
	
	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return FALSE;
	}

	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes();
	unsigned char *mem1, *mem = mem1 = (unsigned char *)bm.bmBits;

	for (int j = 0 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem = mem1;
		for (int i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			*(mem + 0) = rvblkUpTable[0][*(mem + 0)];		
			*(mem + 1) = rvblkUpTable[1][*(mem + 1)];
			*(mem + 2) = rvblkUpTable[2][*(mem + 2)];

			mem += 3;
		}
		mem1 += widthBytes;
	}
	
	FillColorArray();

	return TRUE;
}

BOOL CBitmapManipulations::RestoreFromTempCopy(CString iFileName)
{
	bmp.Detach();

	// Essaie d'ouvrir le fichier bitmap
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, iFileName, IMAGE_BITMAP, 0, 0, 
											LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Si l'ouverture a échoué ????
	if (!hBmp) 
	{ 
		AfxMessageBox("Impossible d'ouvrir " + iFileName + ".");
		return FALSE;
	}

	bmp.Attach(hBmp);

	FillColorArray();

	return TRUE;
}

int *CBitmapManipulations::GetPictureHistogrammeInfo()
{
	return (int *)picData;
}

int *CBitmapManipulations::GetCumulatifHistogrammeInfo()
{
	return (int *)cumData;
}

BOOL CBitmapManipulations::GetRGBComponents()
{
	if (!IsOpened) return FALSE;
	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return FALSE;
	}

	return TRUE;
}

BOOL CBitmapManipulations::InitBitmap(CString inFile)
{
	// Essaie d'ouvrir le fichier bitmap
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, inFile, IMAGE_BITMAP, 0, 0, 
											LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Si l'ouverture a échoué ????
	if (!hBmp) 
	{ 
		AfxMessageBox("Impossible d'ouvrir " + inFile + ".");
		return FALSE;
	}
	
	// Attacher l'objet CBitmap de son handle HBITMAP sinon ----> WinGdi erreur
	if (firstDrawCall) 
	{
		bmp.Attach(hBmp);
	}

	Open(inFile);
	Close();

	FillColorArray();

	return TRUE;
}

HBITMAP CBitmapManipulations::GetBitmapHandle()
{
	return HBITMAP(bmp);
}

void CBitmapManipulations::DrawEx(CDC *pDC, CRect &rect, COLORREF couleur)
{
	if (firstDrawCall) 
	{
		firstDrawCall = FALSE;
		memDC.CreateCompatibleDC(pDC);	
	}

	CBrush brush(couleur), *oldBrush;

	oldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(rect);
	
	memDC.SelectObject(&bmp);

	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, 
				bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, SRCAND);

	pDC->SelectObject(oldBrush);
	brush.DeleteObject();
}

BITMAPINFOHEADER* CBitmapManipulations::GetBitmapInfoHeader()
{
	return (&bmpInfoHeader);
}

BITMAPFILEHEADER* CBitmapManipulations::GetBitmapFileHeader()
{
	return (&bmpFileHeader);
}

CBitmap* CBitmapManipulations::GetCBitmap()
{
	return (&bmp);
}

void CBitmapManipulations::BWTransform()
{
	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes(), moy;
	unsigned char *mem1, *mem = mem1 = (unsigned char *)bm.bmBits;

	for (int j = 0 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem = mem1;
		for (int i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			moy = (*(mem + 0) + *(mem + 1) + *(mem + 2)) / 3;
			*(mem + 0) = moy;		
			*(mem + 1) = moy;
			*(mem + 2) = moy;

			mem += 3;
		}
		mem1 += widthBytes;
	}

	FillColorArray();
}

BOOL CBitmapManipulations::ConvertToRGB(CDC *pDC, BOOL SaveChooseAnotherFile, CString& iFile)
{
	CFileDialog fDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Bitmap (*.bmp)|*.bmp|");

	if 	(SaveChooseAnotherFile)
	{
		if (fDlg.DoModal() != IDOK) return FALSE;
		iFile = fDlg.GetPathName();
	}
	
	SaveBitmap(pDC, &bmp, iFile);
	bmp.Detach();

	return TRUE;
}

BOOL CBitmapManipulations::SaveBitmap(CDC *pDC, CBitmap *bitmap, CString fileName)
{
	CDC newDC; newDC.CreateCompatibleDC(pDC);
	newDC.SelectObject(bitmap);

	CFile file;
	BITMAP bm;
	
	bitmap->GetBitmap(&bm);
	// On essaye d'ouvrir le fichier
	if (!file.Open(fileName, CFile::modeWrite | CFile::modeCreate)) return FALSE;
	
	BITMAPFILEHEADER bFh;
	BITMAPINFOHEADER bIh;

	memset(&bFh, 0, sizeof(BITMAPFILEHEADER));
	memset(&bIh, 0, sizeof(BITMAPINFOHEADER));
	
	bIh.biWidth = bm.bmWidth;
	bIh.biHeight = bm.bmHeight;

	int BmpWidth = bIh.biWidth * 24; 
	BmpWidth = (((BmpWidth >> 5) + ((BmpWidth % 32) > 0)) << 2);

	bFh.bfType = 19778;
	bFh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + BmpWidth * bIh.biHeight;
	bFh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	bIh.biBitCount = 24;
	bIh.biPlanes = 1;
	bIh.biCompression = BI_RGB;
	bIh.biSize = sizeof(BITMAPINFOHEADER);

	unsigned char *p, *p1, *bmpBits = new unsigned char [BmpWidth * bIh.biHeight];

	p = p1 = bmpBits;

	for (int j = (bIh.biHeight - 1) ; j >= 0 ; j--)
	{
		p = p1;
		for (int i = 0 ; i < bIh.biWidth ; i++)
		{
			int rvb = newDC.GetPixel(i, j);		
			*(p++) = (rvb & 0xff0000)	>> 16;	// b
			*(p++) = (rvb & 0xff00)		>> 8;	// g
			*(p++) = (rvb & 0xff)		>> 0;	// r
		}
		p1 += BmpWidth;
	}	

	file.Write(&bFh, sizeof(BITMAPFILEHEADER));
	file.Write(&bIh, sizeof(BITMAPINFOHEADER));
	file.Write(bmpBits, BmpWidth * bIh.biHeight);

	file.Close();

	delete [] bmpBits;
	newDC.DeleteDC();

	return TRUE;
}

void CBitmapManipulations::Flou()
{
	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes(), moy;

	unsigned char *mem2, *mem1, *mem = mem1 = mem2 = (unsigned char *)bm.bmBits;
	unsigned char *cpy2, *cpy1, *cpy = cpy1 = cpy2 = new unsigned char [widthBytes * bmpInfoHeader.biHeight];

	memcpy(cpy, mem, widthBytes * bmpInfoHeader.biHeight);

	for (int j = 3 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem1 += widthBytes;
		mem = mem1;

		cpy1 += widthBytes;
		cpy = cpy1;
		for (int i = 2 ; i < bmpInfoHeader.biWidth ; i++)
		{
			mem += 3;
			cpy += 3;

			moy = (*(mem - widthBytes - 3) + *(mem - widthBytes + 0) + *(mem - widthBytes + 3) +
					*(mem - 3) + *(mem + 0) + *(mem + 3) +
					*(mem + widthBytes - 3) + *(mem + widthBytes + 0) + *(mem + widthBytes + 3)) / 9;
			*(cpy + 0) = moy;
			
			moy = (*(mem - widthBytes - 2) + *(mem - widthBytes + 1) + *(mem - widthBytes + 4) +
					*(mem - 2) + *(mem + 1) + *(mem + 4) +
					*(mem + widthBytes - 2) + *(mem + widthBytes + 1) + *(mem + widthBytes + 4)) / 9;
			*(cpy + 1) = moy;

			moy = (*(mem - widthBytes - 1) + *(mem - widthBytes + 2) + *(mem - widthBytes + 5) +
					*(mem - 1) + *(mem + 2) + *(mem + 5) +
					*(mem + widthBytes - 1) + *(mem + widthBytes + 2) + *(mem + widthBytes + 5)) / 9;
			*(cpy + 2) = moy;
		}
	}

	memcpy(mem2, cpy2, widthBytes * bmpInfoHeader.biHeight);

	delete [] cpy2;

	FillColorArray();
}

void CBitmapManipulations::EdgeDetect(int typeDetect)
{
	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes();
	int i, j;

	unsigned char *mem2, *mem1, *mem = mem1 = mem2 = (unsigned char *)bm.bmBits;
	unsigned char *cpy2, *cpy1, *cpy = cpy1 = cpy2 = new unsigned char [widthBytes * bmpInfoHeader.biHeight];

	memcpy(cpy, mem, widthBytes * bmpInfoHeader.biHeight);

	for (j = 2 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem1 += widthBytes;
		mem = mem1;

		cpy1 += widthBytes;
		cpy = cpy1;
		
		switch(typeDetect)
		{
		//------------------------------------------------------------------
		case ALL_DETECT : // Detection totale
			for (i = 2 ; i < bmpInfoHeader.biWidth ; i++)
			{
				mem += 3;
				cpy += 3;

				*(cpy + 0) = ((*(mem + 0) > *(mem - widthBytes + 0)) ? (*(mem + 0) - *(mem - widthBytes + 0)) : (*(mem + 0) - *(mem - widthBytes + 0))) +
					((*(mem + 0) > *(mem - 3)) ? (*(mem + 0) - *(mem - 3)) : (*(mem + 0) - *(mem - 3))) / 2;

				*(cpy + 1) = ((*(mem + 1) > *(mem - widthBytes + 1)) ? (*(mem + 1) - *(mem - widthBytes + 1)) : (*(mem + 1) - *(mem - widthBytes + 1))) +
					((*(mem + 1) > *(mem - 2)) ? (*(mem + 1) - *(mem - 2)) : (*(mem + 1) - *(mem - 2))) / 2;

				*(cpy + 2) = ((*(mem + 2) > *(mem - widthBytes + 2)) ? (*(mem + 2) - *(mem - widthBytes + 2)) : (*(mem + 2) - *(mem - widthBytes + 2))) +
					((*(mem + 2) > *(mem - 1)) ? (*(mem + 2) - *(mem - 1)) : (*(mem + 2) - *(mem - 1))) / 2;
			}
			break;
		//----------------------------------------------------------------------------
		case HORIZONTAL_DETECT : // Detection Horizontale
			for (i = 2 ; i < bmpInfoHeader.biWidth ; i++)
			{
				mem += 3;
				cpy += 3;

				*(cpy + 0) = (*(mem + 0) - *(mem - widthBytes + 0));
				*(cpy + 1) = (*(mem + 1) - *(mem - widthBytes + 1));
				*(cpy + 2) = (*(mem + 2) - *(mem - widthBytes + 2));
			}
			break;
		//-----------------------------------------------------------------------------
		case VERTICAL_DETECT : // Détection Verticale
			for (i = 2 ; i < bmpInfoHeader.biWidth ; i++)
			{
					mem += 3;
					cpy += 3;


					*(cpy + 0) = (*(mem + 0) - *(mem - 3));
					*(cpy + 1) = (*(mem + 1) - *(mem - 2));
					*(cpy + 2) = (*(mem + 2) - *(mem - 1));
			}
			break;
		//------------------------------------------------------------------------------
		}
	}
		

	memcpy(mem2, cpy2, widthBytes * bmpInfoHeader.biHeight);

	delete [] cpy2;

	FillColorArray();
}

void CBitmapManipulations::FakeColours(int count, COLORREF* OldColors, COLORREF *NewColors)
{
	BITMAP bm; bmp.GetBitmap(&bm);
	unsigned int widthBytes = GetWidthBytes(), rvb;
	int k;

	unsigned char *mem2, *mem1, *mem = mem1 = mem2 = (unsigned char *)bm.bmBits;

	for (int j = 0 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem = mem1;
		for (int i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			rvb = RGB(*(mem + 2), *(mem + 1), *(mem + 0));

			if ((k = dichotomicSearch(OldColors, rvb, 0, count - 1)) >= 0)
			{
				*(mem + 0) = NewColors[k] >> 16;			// B
				*(mem + 1) = (NewColors[k] >> 8) & 0xff;	// G
				*(mem + 2) = NewColors[k] & 0xff;			// R
			}
			
			mem += 3;
		}
		mem1 += widthBytes;
	}
	FillColorArray();
}

COLORREF CBitmapManipulations::GetPixel(CPoint point)
{
	BITMAP bm; bmp.GetBitmap(&bm);
	point.y = bmpInfoHeader.biHeight - point.y;

	int offset = GetWidthBytes() * point.y + 3 * point.x;

	if ((offset > GetWidthBytes() * bmpInfoHeader.biHeight) ||
		(offset < 0)) return RGB(0, 0, 0);

	unsigned char *mem = (unsigned char *)bm.bmBits;

	return RGB(*(mem + offset + 2), *(mem + offset + 1), *(mem + offset)); 
}

int CBitmapManipulations::GetColorCount()
{
	return ArraySize;
}

void CBitmapManipulations::LimitRGBBright(int precision)
{
	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes();

	unsigned char *mem2, *mem1, *mem = mem1 = mem2 = (unsigned char *)bm.bmBits;

	for (int j = 0 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem = mem1;
		for (int i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			*(mem + 0) = *(mem + 0) / precision * precision;
			*(mem + 1) = *(mem + 1) / precision * precision;
			*(mem + 2) = *(mem + 2) / precision * precision;	
			
			mem += 3;
		}
		mem1 += widthBytes;
	}

	FillColorArray();
}

UINT CBitmapManipulations::FillColorArray()
{
	cStruct.bmpManip = this;

	AfxBeginThread(sort,(LPVOID)&cStruct);

	return 0;
}

void Qsort(RvbValues a[], int lo0, int hi0)
{
	int prog;
	RvbValues mid;
	RvbValues sw, pivot;

	RvbSet(&mid, (a + (lo0 + hi0) / 2));

	if (RvbCmp(a[lo0], a[hi0]) > 0) 
	{
		if (RvbCmp(mid, a[hi0]) > 0) RvbSet(&pivot, &a[hi0]);
		else 
		{ 
			if (RvbCmp(mid, a[lo0]) > 0) RvbSet(&pivot, &mid); 
				else RvbSet(&pivot, &a[lo0]);
		} 
	} 
	else 
	{ 
		if (RvbCmp(mid, a[lo0]) > 0) RvbSet(&pivot, &a[lo0]);
		else 
		{ 
			if (RvbCmp(mid, a[hi0]) > 0) RvbSet(&pivot, &mid);  
				else RvbSet(&pivot, &a[hi0]);  
		} 
	}

	int lo = lo0, hi = hi0;

	entry++;
	prog = entry * 100 / (maxentry + 1);

	if (prog == (prog / 5 * 5)) 
	{
		((CRmtSensingApp *)AfxGetApp())->wDlg.m_progression.SetPos(prog);
	}

	if (lo0 >= hi0) return;

	RvbSet(&mid, (a + (lo0 + hi0) / 2));
	
	do { 
		MSG msg;

		if (PeekMessage(&msg, AfxGetMainWnd()->m_hWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		while(lo < hi0 && RvbCmp(a[lo], pivot) < 0) lo++;
		while(hi > lo0 && RvbCmp(a[hi], pivot) > 0) hi--;

		if (lo <= hi)
		{
			if (lo != hi)
			{
				RvbSet(&sw, &a[lo]);
				RvbSet(&a[lo], &a[hi]);
				RvbSet(&a[hi], &sw); 
			}

			lo++; hi--;
		}
	} while(lo <= hi);

	if (hi - lo0 > 10) Qsort(a, lo0, hi); 
		else insertionSort(a, lo0, hi); 
	
	if (hi0 - lo > 10) Qsort(a, lo, hi0); 
		else insertionSort(a, lo, hi0); 
}

UINT sort(LPVOID lpVoid)
{
	CSingleLock lock(&sem);

	lock.Lock();

	CRmtSensingApp* app = ((CRmtSensingApp *) AfxGetApp());

	app->wDlg.Create(AfxGetMainWnd());
	app->wDlg.ShowWindow(SW_SHOWNORMAL);

	CallStruct* Cs = (CallStruct*) lpVoid;

	CBitmapManipulations* bmpMan = (CBitmapManipulations*) Cs->bmpManip;
	CBitmap *bmp; bmp = bmpMan->GetCBitmap();

	BITMAP bm; bmp->GetBitmap(&bm);
	int widthBytes = bmpMan->GetWidthBytes();
	unsigned char *mem1, *mem = mem1 = (unsigned char *)bm.bmBits;
	RvbValues *cpy1 = new RvbValues [bmpMan->GetWidth() * bmpMan->GetHeight()],
		others = {0, 0, 0};

	if (!cpy1) 
	{
		AfxMessageBox("Un problème de mémoire !!!!!");
	}
	int i, j;

	for (j = 0 ; j < bmpMan->GetHeight() ; j++)
	{
		memcpy(&cpy1[j * bmpMan->GetWidth()], 
				mem1 + j * widthBytes, bmpMan->GetWidth() * 3);
	}

	for (i = 1, j = 0 ; i < bmpMan->GetWidth() * bmpMan->GetHeight() ; i++)
		if (RvbCmp(cpy1[j], cpy1[i])) RvbSet(&cpy1[++j], &cpy1[i]);

	for (i = j + 1 ; i < bmpMan->GetWidth() * bmpMan->GetHeight() ; i++)
							RvbSet(&cpy1[i], &others);

	entry = 0; maxentry = j / 8;

	Qsort(cpy1, 0, j);

	for (i = 1, j = 0 ; i < bmpMan->GetWidth() * bmpMan->GetHeight() ; i++)
		if (RvbCmp(cpy1[j], cpy1[i]) < 0) RvbSet(&cpy1[++j], &cpy1[i]);

	for (i = j + 1 ; i < bmpMan->GetWidth() * bmpMan->GetHeight() ; i++)
							RvbSet(&cpy1[i], &others);

	bmpMan->SetColorArrayData(j + 1, cpy1);

	delete [] cpy1;

	app->wDlg.EndDialog(0);
	app->wDlg.DestroyWindow();

	lock.Unlock();

	return 0;
}

COLORREF* CBitmapManipulations::GetColorArrayPointer()
{
	return ColorArray;
}

void CBitmapManipulations::SetColorArrayData(int count, RvbValues rgb[])
{
	if (count != ArraySize)
	{
		ArraySize = count;
		delete [] ColorArray;
		ColorArray = new COLORREF [ArraySize];
	}

	for (int i = 0 ; i < count ; i++)
	{ 
		ColorArray[i] = RGB(rgb[i].r, rgb[i].g, rgb[i].b); 
	}
}

void insertionSort(RvbValues a[], int lo0, int hi0)
{
	RvbValues sw;

	if (lo0 >= hi0) return;

	for (int i = lo0 + 1 ; i <= hi0 ; i++)
		for (int j = i ; j > lo0 ; j--)
			if (RvbCmp(a[j], a[j - 1]) < 0)
			{
				RvbSet(&sw, &a[j - 1]);
				RvbSet(&a[j - 1], &a[j]);
				RvbSet(&a[j], &sw); 
			}
			else break;
}
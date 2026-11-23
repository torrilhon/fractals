#include <vcl.h>
#pragma hdrstop

#include "Frak1.h"
#include "FrakMain.h"
#include "FrakTrans.h"
#include "math.h"
#include "stdlib.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TKoord *Koord;
//---------------------------------------------------------------------------
__fastcall TKoord::TKoord(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKoord::FormCreate(TObject *Sender)
{
	T1 = new Trafo;
    T2 = new Trafo;
    T = T1;
    D = new DrehKoord;

	x1 = -2.0;
    y1 = -0.5;
    x2 = 2.0;
    y2 = 2.5;
    a1 = ClientWidth;
    b1 = ClientHeight-19;
    SetKoord();

    xMouse = 0;
    yMouse = 0;

    Kreuz = false;
    Ready = false;
    Fest  = false;
    Ebenen = 10;

    PL[0].Set( -0.1, -0.4 );
    PL[1].Set( 0.1, -0.4 );
    PL[2].Set( 0.0, 0.6 );
    PL[3] = PL[0];
}
//---------------------------------------------------------------------
void __fastcall TKoord::FormPaint(TObject *Sender)
{
    Farbe(1);
    D->Reset();

    if( Ready || Fest )
    {
    	ZeichneEbene(0);
		for( int i = 0; i < Ebenen+1; i++ )
    	{
        	T1->Transform( D );
    		DrawList( PL, 4 );
    	};
    }
    else
    {
	    DrawList( PL, 4 );

		T1->Transform( D );
    	DrawList( PL, 4 );
        D->Reset();
        T2->Transform( D );
        DrawList( PL, 4 );
        Farbe(2);
        D->Reset();
        T->Transform( D );
        DrawList( PL, 4 );
    };
};
//---------------------------------------------------------------------
void __fastcall TKoord::FormResize(TObject *Sender)
{
	a1 = ClientWidth;
    b1 = ClientHeight;
	SetKoord();
	Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::FormDestroy(TObject *Sender)
{
	delete T1;
    delete T2;
    delete D;
}
//---------------------------------------------------------------------------

void TKoord::ZeichneEbene( int e )
{
   	DrawList( PL, 4 );
	if( e++ == Ebenen+1 )
    {
     	return;
    };

    DrehKoord Temp = *D;

    T1->Transform( D );
    ZeichneEbene( e );
    *D = Temp;

    T2->Transform( D );
    ZeichneEbene( e );
};








void TKoord::InitKoord( float v, float w,
                        float x, float y )
{
	x1 = v;
    y1 = w;
    x2 = x;
    y2 = y;

    SetKoord();
};


void TKoord::SetKoord()
{
	dx = (x2 - x1)/a1;
	dy = (y2 - y1)/b1;
	a0 = -x1/dx;
	b0 = y2/dy;
};

TColor TKoord::Farbe( int Z )
{
	switch( Z )
    {
    case( 0 ): Canvas->Pen->Color = Color; //clTeal;
    break;
    case( 1 ): Canvas->Pen->Color = clBlack; //clSilver;
    break;
    case( 2 ): Canvas->Pen->Color = clRed;
    break;
    case( 3 ): Canvas->Pen->Color = clAqua;
    break;
    case( 4 ): Canvas->Pen->Color = clLime;
    break;
    };

    return( Canvas->Pen->Color );
};


void TKoord::DrawKoord( int Flag )
{
	Kreuz = Flag;

    Farbe( Flag );
    Canvas->Brush->Color = Farbe( Flag );
    Canvas->Brush->Style = bsSolid;
	Canvas->MoveTo( a0, b1-5 );
    Canvas->LineTo( a0, 18 );
	Canvas->MoveTo( a0, 5 );
	Canvas->LineTo( a0+2, 18 );
	Canvas->LineTo( a0-2, 18 );
	Canvas->LineTo( a0, 5 );
    Canvas->FloodFill( a0, 15, Farbe( Flag ), fsBorder );

	Canvas->MoveTo( 5, b0 );
    Canvas->LineTo( a1-18, b0 );
	Canvas->MoveTo( a1-5, b0 );
	Canvas->LineTo( a1-18, b0-2 );
	Canvas->LineTo( a1-18, b0+2 );
	Canvas->LineTo( a1-5, b0 );
    Canvas->FloodFill( a1-15, b0, Farbe( Flag ), fsBorder );

	Farbe( 1 );
};

void TKoord::DrawList( Punkt *P, int Anz )
{
	Moveto( P[0].X, P[0].Y );
    for( int i = 1; i < Anz; i++ )
    	Lineto( P[i].X, P[i].Y );
};


inline void TKoord::Transform( int &a, int &b, float x, float y )
{
	a = ( x - x1 ) / dx;
	b = ( y2 - y ) / dy;
};


void TKoord::Moveto( float x, float y )
{
	int a, b;
    Punkt P = D->Transform( Punkt( x, y ) );
	Transform( a, b, P.X, P.Y );

	Canvas->MoveTo( a, b );
};


void TKoord::Lineto( float x, float y )
{
	int a, b;
    Punkt P = D->Transform( Punkt( x, y ) );
	Transform( a, b, P.X, P.Y );

	Canvas->LineTo( a, b );
};

//---------------------------------------------------------------------------
void __fastcall TKoord::ActionClick(TObject *Sender)
{
	Ready = true;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::TrafoBtnClick(TObject *Sender)
{
	Ready = false;
    Invalidate();
	Transformer->ShowModal();
    Change();
}
//----------------------------------------
void TKoord::Change()
{
	if( T == T1 ) T = T2;
    else T = T1;
    Invalidate();
};
//---------------------------------------------------------------------------
void __fastcall TKoord::PopIter1Click(TObject *Sender)
{
	Ebenen = 1;
	PopAktuell->Caption = String("Aktuell: ")+Ebenen;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::PopIter10Click(TObject *Sender)
{
	Ebenen = 10;
	PopAktuell->Caption = String("Aktuell: ")+Ebenen;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::PopIter20Click(TObject *Sender)
{
	Ebenen = 13;
	PopAktuell->Caption = String("Aktuell: ")+Ebenen;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::PopIter30Click(TObject *Sender)
{
	Ebenen = 15;
	PopAktuell->Caption = String("Aktuell: ")+Ebenen;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TKoord::FestBtnClick(TObject *Sender)
{
	Fest = !Fest;
}
//---------------------------------------------------------------------------

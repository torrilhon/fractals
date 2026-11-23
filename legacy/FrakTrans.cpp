//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Frak1.h"
#include "FrakTrans.h"
#include "FrakMain.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TTransformer *Transformer;
//---------------------------------------------------------------------------
__fastcall TTransformer::TTransformer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::FormCreate(TObject *Sender)
{
	dx = 0.1;
    dp = M_PI/20;
    dr = 0.05;
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::HochClick(TObject *Sender)
{
	Koord->T->ys += dx;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::RunterClick(TObject *Sender)
{
	Koord->T->ys -= dx;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::LinksClick(TObject *Sender)
{
	Koord->T->xs -= dx;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::RechtsClick(TObject *Sender)
{
	Koord->T->xs += dx;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::DrehRechtsClick(TObject *Sender)
{
	Koord->T->phi += dp;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::DrehLinksClick(TObject *Sender)
{
	Koord->T->phi -= dp;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::StauchenClick(TObject *Sender)
{
	Koord->T->r -= dr;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::DehnenClick(TObject *Sender)
{
	Koord->T->r += dr;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::NeigLinksClick(TObject *Sender)
{
	Koord->T->psi += dp;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::NeigRechtsClick(TObject *Sender)
{
	Koord->T->psi -= dp;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::XMehrClick(TObject *Sender)
{
	Koord->T->rx += dr;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::XWenigerClick(TObject *Sender)
{
	Koord->T->rx -= dr;
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::TrafoOKClick(TObject *Sender)
{
	Koord->Invalidate();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::TrafoResetClick(TObject *Sender)
{
	Koord->T->Reset();
    Koord->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTransformer::TrafoNextClick(TObject *Sender)
{
	Koord->Change();
    Koord->Invalidate();
}
//---------------------------------------------------------------------------

#ifndef FrakTransH
#define FrakTransH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TTransformer : public TForm
{
__published:	// IDE-verwaltete Komponenten
	TGroupBox *GroupBox1;
	TSpeedButton *Hoch;
	TSpeedButton *Links;
	TSpeedButton *Runter;
	TSpeedButton *Rechts;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TGroupBox *GroupBox5;
	TButton *TrafoOK;
	TButton *TrafoReset;
	TSpeedButton *DrehLinks;
	TSpeedButton *DrehRechts;
	TSpeedButton *Dehnen;
	TSpeedButton *Stauchen;
	TSpeedButton *NeigRechts;
	TSpeedButton *NeigLinks;
	TSpeedButton *XMehr;
	TSpeedButton *XWeniger;
	TButton *TrafoNext;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HochClick(TObject *Sender);
	void __fastcall RunterClick(TObject *Sender);
	void __fastcall LinksClick(TObject *Sender);
	void __fastcall RechtsClick(TObject *Sender);
	void __fastcall DrehRechtsClick(TObject *Sender);
	void __fastcall DrehLinksClick(TObject *Sender);
	void __fastcall StauchenClick(TObject *Sender);
	void __fastcall DehnenClick(TObject *Sender);
	void __fastcall NeigLinksClick(TObject *Sender);
	void __fastcall NeigRechtsClick(TObject *Sender);
	void __fastcall XMehrClick(TObject *Sender);
	void __fastcall XWenigerClick(TObject *Sender);
	void __fastcall TrafoOKClick(TObject *Sender);
	void __fastcall TrafoResetClick(TObject *Sender);
	void __fastcall TrafoNextClick(TObject *Sender);
private:	// Benutzer-Deklarationen

	float dx, dp, dr;

public:		// Benutzer-Deklarationen
	__fastcall TTransformer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TTransformer *Transformer;
//---------------------------------------------------------------------------
#endif

#ifndef FrakMainH
#define FrakMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <vcl\Menus.hpp>

//---------------------------------------------------------------------------

class TKoord : public TForm
{
__published:    // IDE-managed Components
	TButton *Action;
	TButton *TrafoBtn;
	TPopupMenu *PopupMenu1;
	TMenuItem *PopIter1;
	TMenuItem *PopIter10;
	TMenuItem *PopIter20;
	TMenuItem *PopIter30;
	TMenuItem *PopAktuell;
	TMenuItem *PopN1;
	TButton *FestBtn;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);


	void __fastcall ActionClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall TrafoBtnClick(TObject *Sender);
	void __fastcall PopIter1Click(TObject *Sender);
	void __fastcall PopIter10Click(TObject *Sender);
	void __fastcall PopIter20Click(TObject *Sender);
	void __fastcall PopIter30Click(TObject *Sender);
	void __fastcall FestBtnClick(TObject *Sender);
public:                                      // User declarations
    virtual __fastcall TKoord(TComponent* Owner);

	void InitKoord( float v, float w, float x, float y );
    void DrawKoord( int Flag = 1 );
	TColor Farbe( int Z );
    void DrawList( Punkt *P, int Anz );
	void Moveto( float x, float y );
	void Lineto( float x, float y );

    Trafo *T;
    void Change();
private:                                       // User declarations
    float x1, x2, y1, y2, dx, dy;
    float xMouse, yMouse;
    int a0, b0, a1, b1;
    bool Kreuz, Ready, Fest;

    Punkt PL[4];
    DrehKoord *D;
    Trafo *T1, *T2;
    int Ebenen;

    void ZeichneEbene( int e );

    inline void Transform( int &a, int &b, float x, float y );
    void SetKoord();

};
//---------------------------------------------------------------------------
extern TKoord *Koord;
//---------------------------------------------------------------------------

#endif

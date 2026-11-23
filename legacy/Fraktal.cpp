//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("FrakMain.cpp", Koord);
USERES("Fraktal.res");
USEUNIT("Frak1.cpp");
USEFORM("FrakTrans.cpp", Transformer);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->Title = "Fraktale";
		Application->CreateForm(__classid(TKoord), &Koord);
		Application->CreateForm(__classid(TTransformer), &Transformer);
		Application->Run();

    return 0;
}
//---------------------------------------------------------------------------

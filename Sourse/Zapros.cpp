//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Zapros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
      
      Form1->Close();  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Enter(TObject *Sender)
{
      BitBtn1->Focused();  
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Filtr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CBSizeClick(TObject *Sender)
{
// управление доступностью ComboBox1 и SpinEdit1
 ComboBox1->Enabled = !CBSize->Checked;
 CSpinEdit1->Enabled = !CBSize->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RGDataClick(TObject *Sender)
{
 // управление доступностью DateTimePicker1 и DateTimePicker2
 DateTimePicker1->Enabled = (RGData->ItemIndex == 4);
 DateTimePicker2->Enabled = DateTimePicker1->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------


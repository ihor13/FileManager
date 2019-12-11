//---------------------------------------------------------------------------

#ifndef FiltrH
#define FiltrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TGroupBox *GroupBox1;
        TRadioGroup *RGData;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TGroupBox *GroupBox2;
        TLabel *Label2;
        TCheckBox *CBSize;
        TComboBox *ComboBox1;
        TCSpinEdit *CSpinEdit1;
        TEdit *EPattern;
        TButton *Button1;
        void __fastcall CBSizeClick(TObject *Sender);
        void __fastcall RGDataClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

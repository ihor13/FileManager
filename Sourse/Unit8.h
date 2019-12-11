//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Sockets.hpp>
#include <ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TTcpClient *TcpClient1;
        TProgressBar *ProgressBar1;
        TStatusBar *StatusBar1;
        TBitBtn *BitBtn2;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TPanel *Panel1;
        TLabeledEdit *LabeledEdit3;
        TRichEdit *RichEdit1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall LabeledEdit1Change(TObject *Sender);
        void __fastcall LabeledEdit2Change(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall LabeledEdit5Change(TObject *Sender);
        void __fastcall LabeledEdit4Change(TObject *Sender);
        void __fastcall LabeledEdit5KeyPress(TObject *Sender, char &Key);
        void __fastcall LabeledEdit4KeyPress(TObject *Sender, char &Key);
        void __fastcall LabeledEdit1KeyPress(TObject *Sender, char &Key);
        void __fastcall LabeledEdit2KeyPress(TObject *Sender, char &Key);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall LabeledEdit3KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);

int i,sip,dip;
String ip;
void scann(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#ifndef UricheditH
#define UricheditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <AppEvnts.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *MFile;
    TMenuItem *MOpen;
    TMenuItem *MClose;
    TMenuItem *N5;
    TMenuItem *MSave;
    TMenuItem *MSaveAs;
    TMenuItem *N8;
    TMenuItem *MPrint;
    TMenuItem *MPrintSetup;
    TMenuItem *N12;
    TMenuItem *MExit;
    TMenuItem *N14;
	TMenuItem *MEdit;
	TMenuItem *MUndo;
    TMenuItem *N17;
	TMenuItem *MCut;
	TMenuItem *MCopy;
	TMenuItem *MPaste;
    TMenuItem *N21;
	TMenuItem *MFind;
	TMenuItem *MReplace;
    TMenuItem *N24;
    TMenuItem *MFont;
    TMenuItem *MAlign;
    TRichEdit *RichEdit1;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TFontDialog *FontDialog1;
	TMenuItem *MCreate;
    TMenuItem *MLeft;
    TMenuItem *MRight;
    TMenuItem *MCenter;
    TMenuItem *MNumb;
	TFindDialog *FindDialog1;
	TReplaceDialog *ReplaceDialog1;
	TPrintDialog *PrintDialog1;
	TPrinterSetupDialog *PrinterSetupDialog1;
	TToolBar *ToolBar1;
	TToolButton *TBOpen;
	TToolButton *TBSave;
	TToolButton *ToolButton3;
	TToolButton *TBPrint;
	TToolButton *ToolButton5;
	TToolButton *TBExit;
	TImageList *ImageList1;
	TMenuItem *N23;
	TMenuItem *N25;
	TToolButton *TBCreate;
	TToolButton *TBFont;
	TToolButton *TBCenter;
	TToolButton *TBLeft;
	TToolButton *TBRight;
	TToolButton *TBFind;
	TToolButton *TBReplace;
	TToolButton *ToolButton1;
	TToolButton *TBCut;
	TToolButton *TBCopy;
	TToolButton *TBPaste;
	TToolButton *TBNumb;
        TApplicationEvents *ApplicationEvents1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N9;
        TStatusBar *StatusBar1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N10;
        TMenuItem *N28;
        TMenuItem *N29;
        TMenuItem *N30;
        TMenuItem *N31;
        TMenuItem *N32;
        TMenuItem *N33;
        TGroupBox *GroupBox1;
        TBitBtn *BitBtn1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit1;
        TGroupBox *GroupBox2;
        TLabel *Label4;
        TComboBox *ComboBox1;
        TLabel *Label5;
        TEdit *Edit2;
        TUpDown *UpDown1;
        TButton *Button1;
    void __fastcall MOpenClick(TObject *Sender);
    void __fastcall MSaveAsClick(TObject *Sender);
    void __fastcall MFontClick(TObject *Sender);
    
    void __fastcall MNumbClick(TObject *Sender);
    void __fastcall MLeftClick(TObject *Sender);
    
    void __fastcall MRightClick(TObject *Sender);
    void __fastcall MCenterClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);

	void __fastcall RichEdit1KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall RichEdit1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	
	void __fastcall FormResize(TObject *Sender);
	
	
	void __fastcall MSaveClick(TObject *Sender);
	void __fastcall FontDialog1Apply(TObject *Sender, HWND Wnd);
	void __fastcall MFindClick(TObject *Sender);
	void __fastcall FindDialog1Find(TObject *Sender);
	void __fastcall MCopyClick(TObject *Sender);
	void __fastcall MCutClick(TObject *Sender);
	void __fastcall MPasteClick(TObject *Sender);
	void __fastcall MUndoClick(TObject *Sender);

	void __fastcall ReplaceDialog1Replace(TObject *Sender);
	void __fastcall MReplaceClick(TObject *Sender);
	void __fastcall MExitClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall MCreateClick(TObject *Sender);
	void __fastcall MPrintSetupClick(TObject *Sender);
	void __fastcall MPrintClick(TObject *Sender);
        void __fastcall ApplicationEvents1Hint(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N28Click(TObject *Sender);
        void __fastcall N29Click(TObject *Sender);
        void __fastcall N30Click(TObject *Sender);
        void __fastcall N31Click(TObject *Sender);
        void __fastcall N32Click(TObject *Sender);
        void __fastcall N33Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
	


	
private:
 // User declarations
 AnsiString MyFName;
public:		// User declarations
    __fastcall TForm6(TComponent* Owner);
    void __fastcall DisplayHint(TObject *Sender);
    void __fastcall StatusExecute(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif

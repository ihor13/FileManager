//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
# include<stdio.h>
#include <FileCtrl.hpp>
#include "Urichedit.h"
#include "Unit4.h"
#include<math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
AnsiString Dir2;
char * Code_Dec(char *s,char Key)
{

 for (int i = 0; ; i++)
 {
  if (s[i] == '\0') break;
  s[i] = s[i] ^ Key;
 }
 return s;
}
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MOpenClick(TObject *Sender)
{
if (OpenDialog1->Execute())
 {
  MyFName = OpenDialog1->FileName;
  RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
  RichEdit1->Modified = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MSaveAsClick(TObject *Sender)
{
SaveDialog1->FileName = MyFName;
if (SaveDialog1->Execute())
 {
  MyFName = OpenDialog1->FileName;
  RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
  RichEdit1->Modified = false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::MFontClick(TObject *Sender)
{
FontDialog1->Font->Assign(RichEdit1->SelAttributes);
if (FontDialog1->Execute())
   RichEdit1->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::MNumbClick(TObject *Sender)
{
 MNumb->Checked = ! MNumb->Checked;
 if (MNumb->Checked) RichEdit1->Paragraph->Numbering = nsBullet;
 else  RichEdit1->Paragraph->Numbering = nsNone;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MLeftClick(TObject *Sender)
{
 MLeft->Checked = true;
 RichEdit1->Paragraph->Alignment = taLeftJustify;
}
//---------------------------------------------------------------------------


void __fastcall TForm6::MRightClick(TObject *Sender)
{
 MRight->Checked = true;
 RichEdit1->Paragraph->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MCenterClick(TObject *Sender)
{
 MCenter->Checked = true;
 RichEdit1->Paragraph->Alignment = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormCreate(TObject *Sender)
{
RichEdit1->Paragraph->FirstIndent = 0;
RichEdit1->Paragraph->LeftIndent = - RichEdit1->Paragraph->FirstIndent;
RichEdit1->Modified = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::DisplayHint(TObject *Sender)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::StatusExecute(TObject *Sender)
{
 StatusBar1->Panels->Items[0]->Text =
                    IntToStr((int)RichEdit1->CaretPos.y+1) +
                    ": "+IntToStr((int)RichEdit1->CaretPos.x+1);
 if (RichEdit1->Modified)
  StatusBar1->Panels->Items[1]->Text = "модиф.";
  else StatusBar1->Panels->Items[1]->Text = "";
 switch (RichEdit1->Paragraph->Alignment)
 {
   case taLeftJustify: TBLeft->Down = true;
   break;
   case taCenter: TBCenter->Down = true;
   break;
   case taRightJustify: TBRight->Down = true;
   break;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::RichEdit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 StatusExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::RichEdit1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 StatusExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormResize(TObject *Sender)
{
 StatusExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MSaveClick(TObject *Sender)
{
if (MyFName != "")
 RichEdit1->Lines->SaveToFile(MyFName);
 else MSaveAsClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FontDialog1Apply(TObject *Sender, HWND Wnd)
{
   RichEdit1->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MFindClick(TObject *Sender)
{

  FindDialog1->FindText = RichEdit1->SelText;
  FindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FindDialog1Find(TObject *Sender)
{
  int FoundAt, StartPos, ToEnd;
  TSearchTypes Option;
  TReplaceDialog *dlg = (TReplaceDialog *)Sender;

  StartPos = RichEdit1->SelStart;
  if (RichEdit1->SelLength)
    StartPos += RichEdit1->SelLength;


  ToEnd = RichEdit1->Text.Length() - StartPos;



  if (dlg->Options.Contains(frWholeWord))
   Option << stWholeWord;
  else Option >> stWholeWord;


  if (dlg->Options.Contains(frMatchCase))
   Option << stMatchCase;
  else Option >> stMatchCase;

  FoundAt = RichEdit1->FindText(dlg->FindText,
                                StartPos, ToEnd, Option);

  if (FoundAt != -1)
  {
    RichEdit1->SelStart = FoundAt;
    RichEdit1->SelLength = dlg->FindText.Length();
    if ((dlg->Name == "ReplaceDialog1")&&(dlg->Options.Contains(frReplaceAll)))
      ReplaceDialog1Replace(Sender);
}
  else ShowMessage("Текст '" + dlg->FindText +
                   "' не знайдено");
    RichEdit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MCopyClick(TObject *Sender)
{
 RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MCutClick(TObject *Sender)
{
 RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MPasteClick(TObject *Sender)
{
 RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MUndoClick(TObject *Sender)
{
 RichEdit1->Undo();
}
//---------------------------------------------------------------------------


void __fastcall TForm6::ReplaceDialog1Replace(TObject *Sender)
{
 RichEdit1->SetFocus();
 if (RichEdit1->SelText != "")
  {
   RichEdit1->SelText = ReplaceDialog1->ReplaceText;
   if (ReplaceDialog1->Options.Contains(frReplaceAll))
     RichEdit1->SelStart += ReplaceDialog1->ReplaceText.Length();
  }
 else if (ReplaceDialog1->Options.Contains(frReplace))
  {
   ShowMessage("Текст '" + ReplaceDialog1->FindText +
                   "' не знайдено");
   return;
  }
 if (ReplaceDialog1->Options.Contains(frReplaceAll))
   FindDialog1Find(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm6::MReplaceClick(TObject *Sender)
{

  ReplaceDialog1->FindText = RichEdit1->SelText;
  ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MExitClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 if (RichEdit1->Modified)
 {
  int res = MessageDlg("Текст у  вікні був змінений. Зберегти його?",
                 mtConfirmation,
                 TMsgDlgButtons() << mbYes<< mbNo << mbCancel,0);
  switch (res)
      {
        case mrYes:    MSaveClick(Sender);
        			   break;
        case mrCancel: CanClose = false;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MCreateClick(TObject *Sender)
{
 if (RichEdit1->Modified)
 {
  int res = MessageDlg("Текст у  вікні був змінений. Зберегти його?",
                 mtConfirmation,
                 TMsgDlgButtons() << mbYes<< mbNo << mbCancel,0);
  switch (res)
      {
        case mrYes:    MSaveClick(Sender);
        			   break;
        case mrCancel: return;
      }
  }
 RichEdit1->Clear();
 MyFName = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MPrintSetupClick(TObject *Sender)
{
 PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::MPrintClick(TObject *Sender)
{
 if (PrintDialog1->Execute())
  for (int i = 1; i <= PrintDialog1->Copies; i++)
   RichEdit1->Print("Друк");
}
//---------------------------------------------------------------------------







void __fastcall TForm6::ApplicationEvents1Hint(TObject *Sender)
{
  StatusBar1->Panels->Items[2]->Text = Application->Hint;
       
}
//---------------------------------------------------------------------------


void __fastcall TForm6::N17Click(TObject *Sender)
{
FontDialog1->Font->Assign(RichEdit1->SelAttributes);
if (FontDialog1->Execute())
   RichEdit1->SelAttributes->Assign(FontDialog1->Font);        
}
//---------------------------------------------------------------------------


void __fastcall TForm6::N1Click(TObject *Sender)
{
 MLeft->Checked = true;
 RichEdit1->Paragraph->Alignment = taLeftJustify;        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N2Click(TObject *Sender)
{
 MRight->Checked = true;
 RichEdit1->Paragraph->Alignment = taRightJustify;        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N3Click(TObject *Sender)
{
 MCenter->Checked = true;
 RichEdit1->Paragraph->Alignment = taCenter;        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N4Click(TObject *Sender)
{
 MNumb->Checked = ! MNumb->Checked;
 if (MNumb->Checked) RichEdit1->Paragraph->Numbering = nsBullet;
 else  RichEdit1->Paragraph->Numbering = nsNone;        
}
//---------------------------------------------------------------------------















void __fastcall TForm6::N10Click(TObject *Sender)
{
RichEdit1->Undo();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N28Click(TObject *Sender)
{
FontDialog1->Font->Assign(RichEdit1->SelAttributes);
if (FontDialog1->Execute())
   RichEdit1->SelAttributes->Assign(FontDialog1->Font);          
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N29Click(TObject *Sender)
{
RichEdit1->CutToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N30Click(TObject *Sender)
{
RichEdit1->CopyToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N31Click(TObject *Sender)
{
RichEdit1->PasteFromClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N32Click(TObject *Sender)
{
FindDialog1->FindText = RichEdit1->SelText;
  FindDialog1->Execute();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N33Click(TObject *Sender)
{
ReplaceDialog1->FindText = RichEdit1->SelText;
  ReplaceDialog1->Execute();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn1Click(TObject *Sender)
{
   SelectDirectory("Виберіть папку", "", Dir2);
    if(Dir2[Dir2.Length()] != '\\')
  Dir2 = Dir2 + "\\";
    Label2->Caption=Dir2 ;
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Edit2KeyPress(TObject *Sender, char &Key)
{
 if ((Key < '0' || Key > '9') && Key != 8) Key= 0;        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::N7Click(TObject *Sender)
{
CreateDir("C:\\Work");
if (RichEdit1->Lines=="" || Edit2->Text=="" ){ShowMessage("Ви не ввели дані");}
else
switch(ComboBox1->ItemIndex)
{
case 0:{
  int T;
        AnsiString buff = RichEdit1->Text;
        int key  = StrToInt(Edit2->Text);
        for (int i = 1;i<=buff.Length();i++)
                {
                        T = (unsigned char)buff[i] + key;
                        if (T >= 256) T=T-256;
                        buff[ i ] = (char)T;

                }
        RichEdit1->Text = buff;break;}//Результат
       case 1:{
       int s=StrToInt(Edit2->Text);
RichEdit1->Text = Code_Dec(RichEdit1->Text.c_str(),char(s));break; } } }

//---------------------------------------------------------------------------

void __fastcall TForm6::N9Click(TObject *Sender)
{
if (RichEdit1->Text=="" || Edit2->Text=="")   {ShowMessage("Ви не ввели дані");}
else{
switch(ComboBox1->ItemIndex)
{
case 0:{
   int T;
        AnsiString buff = RichEdit1->Text;
        int key  = StrToInt(Edit2->Text);
        for (int i = 1;i<=buff.Length();i++)
                {
                        T = (unsigned char)buff[i] - key;
                        if (T<=0) T=(unsigned char)buff[i]+256-key;
                        buff[ i ] = (char)T;
                }
        RichEdit1->Text = buff;//Результат
         break;       }
       
        case 1:{
        int s=StrToInt(Edit2->Text);
        RichEdit1->Text = Code_Dec(RichEdit1->Text.c_str(),char(s));break; } }

}  }
//---------------------------------------------------------------------------

void __fastcall TForm6::N25Click(TObject *Sender)
{
Form9->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
if (Edit1->Text =="") ShowMessage("Введіть назву файла і розширення");
else{
int descr=FileCreate(Dir2+Edit1->Text);
FileClose(descr);   }
}
//---------------------------------------------------------------------------


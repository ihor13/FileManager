//---------------------------------------------------------------------------

#include <vcl.h>
#include<vcl\Clipbrd.hpp>
#include <stdio.h>
#include "SysUtils.hpp"
#include "StrUtils.hpp"
#include "FileCtrl.hpp"
#include "DateUtils.hpp"
#pragma hdrstop
  #include "Urichedit.h"
  # include"Unit8.h"
  #include "Unit3.h"
  #include "Unit5.h"
  #include "Unit11.h"
#include "Glavn.h"
#include "Filtr.h"
#include "Zapros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
AnsiString Dir1;
TListItem* Selected1;
int ColumnIndex1 = 0;  
AnsiString Titels1[3] = {"Файл/Папка ", "Розмір ", "Дата "};
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
    DragAcceptFiles(Handle,True);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TBToolsClick(TObject *Sender)
{
       Form2->ShowModal();
       Find();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TFolderClick(TObject *Sender)
{
     SelectDirectory("Виберіть папку", "", Dir1);
 if(Dir1[Dir1.Length()] != '\\')
  Dir1 = Dir1 + "\\";
 Find();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TBUpClick(TObject *Sender)
{
     if(Dir1.Length() > 3)
 {
  Dir1 = Dir1.SubString(0, Dir1.SubString(0, Dir1.Length()-1).LastDelimiter("\\"));
  Find();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TBIconClick(TObject *Sender)
{
      ListView2->ViewStyle = vsIcon;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TBSmallIconClick(TObject *Sender)
{
         ListView2->ViewStyle = vsSmallIcon;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::TBListClick(TObject *Sender)
{
      ListView2->ViewStyle = vsList;
}
//---------------------------------------------------------------------------
 int __stdcall CustomSortProc(long Item1, long Item2, long ParamSort)
{
 int k;
 if(Form4->ListView2->Columns->Items[ParamSort]->Tag == 0)
  k = 1;
 else k = -1;

 switch (ParamSort)
 {
   case 0: if (((TListItem *)Item1)->OverlayIndex == ((TListItem *)Item2)->OverlayIndex)
            return k * AnsiCompareText(((TListItem *)Item1)->Caption, ((TListItem *)Item2)->Caption);
           else return ((TListItem *)Item1)->OverlayIndex - ((TListItem *)Item2)->OverlayIndex;
   case 1: if (((TListItem *)Item1)->OverlayIndex != ((TListItem *)Item2)->OverlayIndex)
            return ((TListItem *)Item1)->OverlayIndex - ((TListItem *)Item2)->OverlayIndex;
           else if(((TListItem *)Item1)->SubItems->Strings[0] == ((TListItem *)Item2)->SubItems->Strings[0])
            return AnsiCompareText(((TListItem *)Item1)->Caption, ((TListItem *)Item2)->Caption);
           else return k * CompareValue(StrToInt(((TListItem *)Item1)->SubItems->Strings[0]),
                             StrToInt(((TListItem *)Item2)->SubItems->Strings[0]));
   case 2: return k * CompareDateTime(StrToDateTime(((TListItem *)Item1)->SubItems->Strings[1]),
                                  StrToDateTime(((TListItem *)Item2)->SubItems->Strings[1]));
 }
}

//----------------------------------------------------------------------------
void __fastcall TForm4::TBReportClick(TObject *Sender)
{
    for(int i = 0; i < 3; i++)
 {
  if(i == ColumnIndex1)
  {
   if(ListView2->Columns->Items[i]->Tag == 0)
    ListView2->Columns->Items[i]->Caption = Titels1[i] + "+";
   else ListView2->Columns->Items[i]->Caption = Titels1[i] + "-";
  }
  else ListView2->Columns->Items[i]->Caption = Titels1[i];
 }
 ListView2->ViewStyle = vsReport;
 ListView2->CustomSort(CustomSortProc, ColumnIndex1);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ListView2ColumnClick(TObject *Sender,
      TListColumn *Column)
{
       if(ColumnIndex1 == Column->Index)
  Column->Tag = 1 - Column->Tag;
 else ColumnIndex1 = Column->Index;
 TBReportClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ListView2DblClick(TObject *Sender)
{
     if(Selected1)
 {
  if(Selected1->OverlayIndex == 0)
  {
   Dir1 += Selected1->Caption + "\\";
   Find();
  }
  else ShellExecute(Handle, "open", Selected1->Caption.c_str(), NULL, NULL, SW_SHOW);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ListView2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
           Selected1 = ListView2->GetItemAt(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
   Dir1 = ExtractFileDrive(Application->ExeName);
 if(Dir1[Dir1.Length()] == ':')
  Dir1 += "\\";
 ListView2->CustomSort(CustomSortProc, ColumnIndex1);
 Find();
}
//---------------------------------------------------------------------------
void __fastcall ViewDir(void)
{

 TSearchRec SR ;
 int ires, TBegin;
 TListItem *NewItem;
 bool ladd;
 TSHFileInfo FileInfo;
 TIcon *Icon = new TIcon;
 Form4->ImageListNormal->Clear();
 Form4->ImageListSmall->Clear();
 Form4->ImageListToolBar->GetIcon(7, Icon);
 Form4->ImageListNormal->AddIcon(Icon);
 Form4->ImageListSmall->AddIcon(Icon);

 switch (Form2->RGData->ItemIndex)
 {
  case 1: TBegin = DateTimeToFileDate(Date() - 7);
          break;
  case 2: TBegin = DateTimeToFileDate(Date() -
                   DaysInMonth(Date()));
          break;
  case 3: TBegin = DateTimeToFileDate(Date() -
                   DaysInYear(Date()));
          break;
  case 4: TBegin = DateTimeToFileDate(
                         Form2->DateTimePicker1->Date);
          break;
  default: TBegin = 0;
 }

 ChDir(Dir1);

 ires = FindFirst(Form2->EPattern->Text, faHidden+faSysFile, SR);
 while (ires == 0 )
 {
  if ((SR.Name != ".") && (SR.Name != ".."))
  {
   ladd = true;
   if ((SR.Attr & faDirectory) == 0)
   {

    if((Form2->RGData->ItemIndex == 4) &&
        (SR.Time > DateTimeToFileDate(Form2->DateTimePicker2->Date)))
      ladd = false;
    else ladd = SR.Time >=  TBegin;


    if (! Form2->CBSize->Checked)
      if (Form2->ComboBox1->ItemIndex == 0)
       ladd = ladd & (SR.Size >
                            (Form2->CSpinEdit1->Value << 10));
      else ladd = ladd & (SR.Size <
                             (Form2->CSpinEdit1->Value << 10));
   }
   if (ladd)
   {

    NewItem = Form4->ListView2->Items->Add();
    NewItem->Caption = SR.Name;

    SHGetFileInfo((Dir1 + SR.Name).c_str(), 0, &FileInfo, sizeof(FileInfo),
                  SHGFI_ICON | SHGFI_LARGEICON);
    Icon->Handle = FileInfo.hIcon;
    Form4->ImageListNormal->AddIcon(Icon);
    SHGetFileInfo((Dir1 + SR.Name).c_str(), 0, &FileInfo, sizeof(FileInfo),
                  SHGFI_ICON | SHGFI_SMALLICON);
    Icon->Handle = FileInfo.hIcon;
    Form4->ImageListSmall->AddIcon(Icon);
    NewItem->ImageIndex = Form4->ImageListNormal->Count - 1;

    NewItem->OverlayIndex = 1;
    NewItem->SubItems->Add(SR.Size);
    NewItem->SubItems->Add(DateTimeToStr(FileDateToDateTime(SR.Time)));
   }
  }

  ires = FindNext(SR);
 }
 FindClose(SR);



 ires = FindFirst("*.*", faDirectory, SR);
  while (ires == 0 )
  {
   if ((SR.Name != ".") && (SR.Name != "..") &&
        ((SR.Attr & faDirectory) != 0))
   {
    NewItem = Form4->ListView2->Items->Add();
    NewItem->Caption = SR.Name;

    NewItem->ImageIndex = 0;

    NewItem->OverlayIndex = 0;
    NewItem->SubItems->Add("");
    NewItem->SubItems->Add(DateTimeToStr(FileDateToDateTime(SR.Time)));
   }
   ires = FindNext(SR);
  }
  FindClose(SR);
}
//----------------------------------------------------------------------------
void __fastcall TForm4::Find(void)
{
 ListView2->Items->BeginUpdate();

 ListView2->Items->Clear();

 ListView2->SortType = Comctrls::stNone;

 Screen->Cursor = crHourGlass;
 StaticText1->Caption = Dir1 + Form2->EPattern->Text + "; розмір ";
 if(Form2->CBSize->Checked)
  StaticText1->Caption = StaticText1->Caption + "будь-який; дата ";
 else StaticText1->Caption = StaticText1->Caption + Form2->ComboBox1->Text + " " + Form2->CSpinEdit1->Text + " КБ; дата ";
 StaticText1->Caption = StaticText1->Caption + Form2->RGData->Items->Strings[Form2->RGData->ItemIndex];
 if(Form2->RGData->ItemIndex == 4)
  StaticText1->Caption = StaticText1->Caption + " " +
       DateToStr(Form2->DateTimePicker1->Date) + " - " +
       DateToStr(Form2->DateTimePicker2->Date);

 ViewDir();

 Screen->Cursor = crDefault;

 ListView2->SortType = Comctrls::stText;
 ListView2->CustomSort(CustomSortProc, ColumnIndex1);
 ListView2->Items->EndUpdate();

}

//-----------------------------------------------------------------------------
   
void __fastcall TForm4::N1Click(TObject *Sender)
{

  char temp[MAX_PATH];
  char params[MAX_PATH];
  if(ListView2->Selected!=NULL)
  {
   sprintf(temp,"%s\0",Dir1+ListView2->Selected->Caption.c_str());

  SHELLEXECUTEINFO execinfo ;
  memset (&execinfo, 0, sizeof (execinfo)) ;
  execinfo.cbSize = sizeof (execinfo) ;
  execinfo.lpVerb = "open" ;
  execinfo.lpFile = temp;
  execinfo.lpParameters = params;
  execinfo.fMask = SEE_MASK_NOCLOSEPROCESS ;
  execinfo.nShow = SW_SHOWDEFAULT ;


  if (! ShellExecuteEx (&execinfo))
   {
    char data[100];
    sprintf(data,"Неможливо відкрити виділений  елемент '%s'");
    MessageBox(NULL,data,"Operation Error!",MB_OK);
   }
  }
  else ShowMessage("На сторінці немає виділених елементів");
}
//---------------------------------------------------------------------------

int FileManage(AnsiString Source,AnsiString Dest,int mode)
{

 SHFILEOPSTRUCT SHF;
AnsiString SFrom, STo;

 SFrom =Source  + "\0\0";
 SFrom = AnsiReplaceStr(SFrom, ';', '\0');
 STo = Dest + "\0\0";
 SHF.hwnd = 0;
 SHF.pFrom = SFrom.c_str();
 SHF.pTo = STo.c_str();
 SHF.fFlags = FOF_ALLOWUNDO;

  switch( mode)
  {
   case 0: SHF.wFunc = FO_COPY;
        break;
   case 1: SHF.wFunc = FO_MOVE;
        break;
   case 2: SHF.wFunc = FO_RENAME;
        break;
   case 3: SHF.wFunc = FO_DELETE;
  }

 if( SHFileOperation(&SHF) != 0)
    if (SHF.fAnyOperationsAborted)
       { ShowMessage(
                "Виконання операції перервано користувачем");
         return 1;
        }
    else {ShowMessage("Помилка виконання операції");return 2;}
  else {ShowMessage("Операція успішно завершена");return 0;}

}
//---------------------------------------------------------------------

void __fastcall TForm4::N7Click(TObject *Sender)
{
     AnsiString *tmpDeleting;
     tmpDeleting=new AnsiString[ListView2->Items->Count];
     int n=0;
     for(int i=0;i<ListView2->Items->Count;i++)
      if(ListView2->Items->Item[i]->Selected)
       {
        tmpDeleting[n]=Dir1+ListView2->Items->Item[i]->Caption;
        if( FileManage(tmpDeleting[n],NULL,3)==0 )ListView2->Items->Item[i]->Delete();
        n++;
        }

     Find();
     delete tmpDeleting;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::N9Click(TObject *Sender)
{
      Form1->Caption="Створення файла";
      Form1->Label1->Caption="Вкажіть ім'я створеного файла";
      Form1->ShowModal();
      int descr=FileCreate(Dir1+Form1->Edit1->Text+".txt");
      FileClose(descr);
      Find();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ToolButton2Click(TObject *Sender)
{
    Form1->Caption="Створення файла";
      Form1->Label1->Caption="Вкажіть ім'я створеного файла";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      int descr=FileCreate(Dir1+Form1->Edit1->Text);
      FileClose(descr);
      Find();


}
//---------------------------------------------------------------------------


void __fastcall TForm4::N10Click(TObject *Sender)
{
    Form1->Caption="Створення файла";
      Form1->Label1->Caption="Вкажіть ім'я створеного файла";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      int descr=FileCreate(Dir1+Form1->Edit1->Text+".bmp");
      FileClose(descr);
      Find();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ToolButton10Click(TObject *Sender)
{
     AnsiString *tmpDeleting;
     tmpDeleting=new AnsiString[ListView2->Items->Count];
     int n=0;
     for(int i=0;i<ListView2->Items->Count;i++)
      if(ListView2->Items->Item[i]->Selected)
       {
        tmpDeleting[n]=Dir1+ListView2->Items->Item[i]->Caption;
        if(FileManage(tmpDeleting[n],NULL,3)==0)ListView2->Items->Item[i]->Delete();
        n++;
        }

     Find();
     delete tmpDeleting;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N8Click(TObject *Sender)
{
      Form1->Caption="Створення каталога";
      Form1->Label1->Caption="Вкажіть ім'я створеної папки";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      CreateDir(Dir1+Form1->Edit1->Text);

      Find();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::SpeedButton1Click(TObject *Sender)
{
  char temp[MAX_PATH];
  char params[MAX_PATH];
  sprintf(temp,"%s\0",Edit1->Text.c_str());
  sprintf(params,"%s\0",Edit2->Text.c_str());


  SHELLEXECUTEINFO execinfo ;
  memset (&execinfo, 0, sizeof (execinfo)) ;
  execinfo.cbSize = sizeof (execinfo) ;
  execinfo.lpVerb = "open" ;
  execinfo.lpFile = temp;
  execinfo.lpParameters = params;
  execinfo.fMask = SEE_MASK_NOCLOSEPROCESS ;
  execinfo.nShow = SW_SHOWDEFAULT ;


  if (! ShellExecuteEx (&execinfo))
  {
    char data[100];
    sprintf(data,"Неможливо запустити програму '%s'",Edit1->Text.c_str());
    MessageBox(NULL,data,"Operation Error!",MB_OK);
  }         
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ToolButton7Click(TObject *Sender)
{

      Form1->Caption="Копіювання виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача ";
      Form1->Edit1->Clear();
      Form1->ShowModal();

     for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,0);
      Find(); 
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N4Click(TObject *Sender)
{
     Form1->Caption="Копіювання виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача ";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,0);
      Find();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ToolButton6Click(TObject *Sender)
{
     Form1->Caption="Переміщення виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача";
      Form1->Edit1->Clear();
      Form1->ShowModal();


      for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,1);
      Find();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N5Click(TObject *Sender)
{
      Form1->Caption="Переміщення виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача ";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,1);
      Find();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::N12Click(TObject *Sender)
{
 SelectDirectory("Виберіть папку", "", Dir1);
 if(Dir1[Dir1.Length()] != '\\')
  Dir1 = Dir1 + "\\";
 Find();        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N13Click(TObject *Sender)
{
  if(Dir1.Length() > 3)
 {
  Dir1 = Dir1.SubString(0, Dir1.SubString(0, Dir1.Length()-1).LastDelimiter("\\"));
  Find();
 }        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N14Click(TObject *Sender)
{
   Form2->ShowModal();
       Find();        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N15Click(TObject *Sender)
{
  Form1->Caption="Створення файла";
      Form1->Label1->Caption="Вкажіть ім'я створеного файла";
      Form1->Edit1->Clear();
      Form1->ShowModal();

      int descr=FileCreate(Dir1+Form1->Edit1->Text);
      FileClose(descr);
      Find();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::N16Click(TObject *Sender)
{
   Form1->Caption="Копіювання виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача ";
      Form1->Edit1->Clear();
      Form1->ShowModal();

     for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,0);
      Find();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::N17Click(TObject *Sender)
{
Form1->Caption="Переміщення виділеного ";
      Form1->Label1->Caption="Вкажіть каталог і ім'я файла-приймача";
      Form1->Edit1->Clear();
      Form1->ShowModal();


      for(int i=0;i<ListView2->Items->Count;i++)
       if(ListView2->Items->Item[i]->Selected)
         FileManage(ListView2->Items->Item[i]->Caption,Form1->Edit1->Text,1);
      Find();        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N18Click(TObject *Sender)
{
 AnsiString *tmpDeleting;
     tmpDeleting=new AnsiString[ListView2->Items->Count];
     int n=0;
     for(int i=0;i<ListView2->Items->Count;i++)
      if(ListView2->Items->Item[i]->Selected)
       {
        tmpDeleting[n]=Dir1+ListView2->Items->Item[i]->Caption;
        if(FileManage(tmpDeleting[n],NULL,3)==0)ListView2->Items->Item[i]->Delete();
        n++;
        }

     Find();
     delete tmpDeleting;        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N20Click(TObject *Sender)
{
  ListView2->ViewStyle = vsIcon;        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N21Click(TObject *Sender)
{
   ListView2->ViewStyle = vsSmallIcon;        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N22Click(TObject *Sender)
{
  ListView2->ViewStyle = vsList;        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N23Click(TObject *Sender)
{
   for(int i = 0; i < 3; i++)
 {
  if(i == ColumnIndex1)
  {
   if(ListView2->Columns->Items[i]->Tag == 0)
    ListView2->Columns->Items[i]->Caption = Titels1[i] + "+";
   else ListView2->Columns->Items[i]->Caption = Titels1[i] + "-";
  }
  else ListView2->Columns->Items[i]->Caption = Titels1[i];
 }
 ListView2->ViewStyle = vsReport;
 ListView2->CustomSort(CustomSortProc, ColumnIndex1);        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N25Click(TObject *Sender)
{
Form6->Show();
}
//---------------------------------------------------------------------------





void __fastcall TForm4::N26Click(TObject *Sender)
{
  Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N28Click(TObject *Sender)
{
Form11->ShowModal();
}
//---------------------------------------------------------------------------


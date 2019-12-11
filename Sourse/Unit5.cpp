//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit7.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
AnsiString Image;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N2Click(TObject *Sender)
{
 if(OpenPictureDialog1->Execute()) Image=OpenPictureDialog1->FileName;Image1->Picture->LoadFromFile(Image);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N3Click(TObject *Sender)
{
if (SavePictureDialog1->Execute()) Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::N6Click(TObject *Sender)
{
  switch(ComboBox1->ItemIndex)
{
case 0:{
   TPicture *pic = new TPicture;
        pic=Image1->Picture;
         int s=StrToInt(Edit1->Text);

        Graphics::TBitmap *src_bmp = new Graphics::TBitmap;
        src_bmp->Assign(pic->Graphic);
        Graphics::TBitmap *dest_bmp = new Graphics::TBitmap;
        dest_bmp->Width = src_bmp->Width;
        dest_bmp->Height = src_bmp->Height;

            Image2->Width= dest_bmp->Width;  Image2->Height= dest_bmp->Height;
        for(int x=1;x<=dest_bmp->Width;x++)
        {
        for(int y=1;y<=dest_bmp->Height;y++)
        {


int j= int(Image1->Canvas->Pixels[x][y])*s-(s*x*y)/(10-s)*s;//int)Image1->Canvas->Pixels[x][y]*s-s*x*y/(10-s)*s
 Image2->Canvas->Pixels[x][y]= TColor(j);   }}  Image2->Stretch=true;  break;}
case 1:{ TPicture *pic = new TPicture;
        pic=Image1->Picture;
         int s=StrToInt(Edit1->Text);

        Graphics::TBitmap *src_bmp = new Graphics::TBitmap;
        src_bmp->Assign(pic->Graphic);
        Graphics::TBitmap *dest_bmp = new Graphics::TBitmap;
        dest_bmp->Width = src_bmp->Width;
        dest_bmp->Height = src_bmp->Height;

            Image2->Width= dest_bmp->Width;  Image2->Height= dest_bmp->Height;
        for(int x=1;x<=dest_bmp->Width;x++)
        {
        for(int y=1;y<=dest_bmp->Height;y++)
        {


int j= (int)Image1->Canvas->Pixels[x][y]*s;//int)Image1->Canvas->Pixels[x][y]*s-s*x*y/(10-s)*s
 Image2->Canvas->Pixels[x][y]= TColor(j);   }}  Image2->Stretch=true; }
}}
//---------------------------------------------------------------------------
void __fastcall TForm5::N5Click(TObject *Sender)
{
 switch(ComboBox1->ItemIndex)
{
case 0:{
TPicture *pic = new TPicture;
        pic=Image1->Picture;
         int s=StrToInt(Edit1->Text);

        Graphics::TBitmap *src_bmp = new Graphics::TBitmap;
        src_bmp->Assign(pic->Graphic);
        Graphics::TBitmap *dest_bmp = new Graphics::TBitmap;
        dest_bmp->Width = src_bmp->Width;
        dest_bmp->Height = src_bmp->Height;


        for(int x=1;x<=dest_bmp->Width;x++)
        {
        for(int y=1;y<=dest_bmp->Height;y++)
        {
 TColor tColor=Image1->Canvas->Pixels[x][y];

int i=((int)tColor+s*x*y/(10-s)*s)/s;  //((int)tColor+s*x*y/(10-s)*s)/s

Image1->Canvas->Pixels[x][y]=TColor(i);}} break;}

case 1:{
TPicture *pic = new TPicture;
        pic=Image1->Picture;
         int s=StrToInt(Edit1->Text);

        Graphics::TBitmap *src_bmp = new Graphics::TBitmap;
        src_bmp->Assign(pic->Graphic);
        Graphics::TBitmap *dest_bmp = new Graphics::TBitmap;
        dest_bmp->Width = src_bmp->Width;
        dest_bmp->Height = src_bmp->Height;


        for(int x=1;x<=dest_bmp->Width;x++)
        {
        for(int y=1;y<=dest_bmp->Height;y++)
        {
 TColor tColor=Image1->Canvas->Pixels[x][y];

int i=(int)tColor/s;  //((int)tColor+s*x*y/(10-s)*s)/s

Image1->Canvas->Pixels[x][y]=TColor(i);  }}}
} }
//---------------------------------------------------------------------------
void __fastcall TForm5::N8Click(TObject *Sender)
{
Form10->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::N9Click(TObject *Sender)
{
   if (SavePictureDialog1->Execute()) Image2->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::N10Click(TObject *Sender)
{
   Form5->Close();
   Image1->Picture=NULL;
   Image2->Picture=NULL;
}
//---------------------------------------------------------------------------


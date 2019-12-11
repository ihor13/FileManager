object Form1: TForm1
  Left = 216
  Top = 105
  Width = 330
  Height = 126
  BorderIcons = [biMinimize, biMaximize]
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 32
    Height = 13
    Caption = 'Label1'
    Transparent = True
    WordWrap = True
  end
  object BitBtn1: TBitBtn
    Left = 120
    Top = 56
    Width = 65
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
    OnClick = BitBtn1Click
    OnEnter = BitBtn1Enter
  end
  object Edit1: TEdit
    Left = 120
    Top = 16
    Width = 193
    Height = 21
    TabOrder = 1
  end
end

object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Form'
  ClientHeight = 361
  ClientWidth = 1244
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 632
    Top = 267
    Width = 71
    Height = 13
    Caption = '"a ('#1086#1090' 3 '#1076#1086' 7)"'
  end
  object Label2: TLabel
    Left = 632
    Top = 300
    Width = 74
    Height = 13
    Caption = '"b ('#1086#1090' 1 '#1076#1086' 3 )"'
  end
  object Label3: TLabel
    Left = 632
    Top = 330
    Width = 76
    Height = 13
    Caption = '"c ('#1086#1090' 1 '#1076#1086' 10)"'
  end
  object Label4: TLabel
    Left = 872
    Top = 15
    Width = 152
    Height = 13
    Caption = #1055#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' '#1082#1086#1101#1092' A'
  end
  object Label5: TLabel
    Left = 1192
    Top = 45
    Width = 41
    Height = 13
    Caption = #1095#1072#1089#1090#1086#1090#1072
  end
  object Label6: TLabel
    Left = 1192
    Top = 72
    Width = 41
    Height = 13
    Caption = #1095#1072#1089#1090#1086#1090#1072
  end
  object Label8: TLabel
    Left = 872
    Top = 42
    Width = 151
    Height = 13
    Caption = #1055#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' '#1082#1086#1101#1092' B'
  end
  object Label10: TLabel
    Left = 872
    Top = 69
    Width = 152
    Height = 13
    Caption = #1055#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' '#1082#1086#1101#1092' C'
  end
  object Label11: TLabel
    Left = 1192
    Top = 15
    Width = 41
    Height = 13
    Caption = #1095#1072#1089#1090#1086#1090#1072
  end
  object Chart: TChart
    Left = 8
    Top = 8
    Width = 836
    Height = 250
    Foot.Shadow.Visible = False
    Legend.Symbol.DefaultPen = False
    Legend.Symbol.Visible = False
    Legend.Visible = False
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' a+b*sin(c*t)')
    View3D = False
    View3DOptions.Orthogonal = False
    Zoom.MouseButton = mbMiddle
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      18
      15
      18)
    ColorPaletteIndex = 13
    object Series2: TLineSeries
      Brush.BackColor = clDefault
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {0000000000}
    end
  end
  object btnOutputToChart: TButton
    Left = 872
    Top = 127
    Width = 351
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1074#1099#1074#1086#1076' '#1076#1072#1085#1085#1099#1093' '#1085#1072' '#1075#1088#1072#1092#1080#1082
    TabOrder = 1
    OnClick = btnOutputToChartClick
  end
  object btnOutputToFile: TButton
    Left = 872
    Top = 158
    Width = 351
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1074#1099#1074#1086#1076' '#1076#1072#1085#1085#1099#1093' '#1074' txt '#1092#1072#1081#1083
    TabOrder = 2
    OnClick = btnOutputToFileClick
  end
  object btnStopA: TButton
    Left = 8
    Top = 264
    Width = 225
    Height = 25
    Caption = #1055#1088#1080#1086#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' A'
    TabOrder = 3
    OnClick = btnStopAClick
  end
  object btnStopB: TButton
    Left = 8
    Top = 295
    Width = 225
    Height = 25
    Caption = #1055#1088#1080#1086#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' B'
    TabOrder = 4
    OnClick = btnStopBClick
  end
  object btnStopC: TButton
    Left = 8
    Top = 326
    Width = 225
    Height = 25
    Caption = #1055#1088#1080#1086#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1090#1086#1082' '#1086#1090#1074#1077#1095#1072#1102#1097#1080#1081' '#1079#1072' C'
    TabOrder = 5
    OnClick = btnStopCClick
  end
  object btnSetA: TButton
    Left = 248
    Top = 264
    Width = 225
    Height = 25
    Caption = #1047#1072#1076#1072#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1101#1092' A'
    TabOrder = 6
    OnClick = btnSetAClick
  end
  object btnSetB: TButton
    Left = 248
    Top = 295
    Width = 225
    Height = 25
    Caption = #1047#1072#1076#1072#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1101#1092' B'
    TabOrder = 7
    OnClick = btnSetBClick
  end
  object btnSetC: TButton
    Left = 248
    Top = 326
    Width = 225
    Height = 25
    Caption = #1047#1072#1076#1072#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1101#1092' C'
    TabOrder = 8
    OnClick = btnSetCClick
  end
  object lineEditA: TEdit
    Left = 496
    Top = 264
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object lineEditB: TEdit
    Left = 496
    Top = 297
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object lineEditC: TEdit
    Left = 496
    Top = 330
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object btnSetVAll: TButton
    Left = 872
    Top = 96
    Width = 351
    Height = 25
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1091#1102' '#1095#1072#1089#1090#1086#1090#1091' '
    TabOrder = 12
    OnClick = btnSetVAllClick
  end
  object lineEditVA: TEdit
    Left = 1048
    Top = 15
    Width = 121
    Height = 21
    TabOrder = 13
  end
  object lineEditVB: TEdit
    Left = 1048
    Top = 42
    Width = 121
    Height = 21
    TabOrder = 14
  end
  object lineEditVC: TEdit
    Left = 1048
    Top = 69
    Width = 121
    Height = 21
    TabOrder = 15
  end
  object btnExit: TButton
    Left = 872
    Top = 220
    Width = 351
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 16
    OnClick = btnExitClick
  end
  object btnClearFile: TButton
    Left = 872
    Top = 189
    Width = 351
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' txt '#1092#1072#1081#1083
    TabOrder = 17
    OnClick = btnClearFileClick
  end
  object StaticText1: TStaticText
    Left = 872
    Top = 285
    Width = 221
    Height = 47
    AutoSize = False
    Caption = 
      #1044#1083#1103' '#1090#1086#1075#1086' '#1095#1090#1086#1073#1099' '#1082#1086#1088#1088#1077#1082#1090#1085#1086' '#1079#1072#1076#1072#1090#1100' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1086#1074', '#1087#1088#1080#1086#1089#1090#1072#1085 +
      #1086#1074#1080#1090#1077' '#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1091#1102#1097#1080#1077' '#1087#1086#1090#1086#1082#1080'.'
    TabOrder = 18
  end
end

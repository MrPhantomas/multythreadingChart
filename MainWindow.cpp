//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	randomize();
	t_ = 0;
	vA_ = 0.4;
	vB_ = 0.5;
	vC_ = 0.6;
	lineEditVA->Text = 0+vA_;
	lineEditVB->Text = 0+vB_;
	lineEditVC->Text = 0+vC_;

	flagA_ = true;
	flagB_ = true;
	flagC_ = true;
	flagChartOutput_ = true;
	flagFileOutput_ = true;
	stopA_ = false;
	stopB_ = false;
	stopC_ = false;
	stopChartOutput_ = true;
	stopFileOutput_ = true;
	//Crete mutexs and threads
	mutexClearToFile_ = new std::mutex();
	mutexOutputToChart_ = new std::mutex();
	mutexOutputToFile_ = new std::mutex();
	mutexA_  = new std::mutex();
	mutexB_  = new std::mutex();
	mutexC_  = new std::mutex();
	mutexOutputToChart_->lock();
	mutexOutputToFile_->lock();
	threadA_ = new std::thread(funcA);
	threadB_ = new std::thread(funcB);
	threadC_ = new std::thread(funcC);
	threadOutputToChart_ = new std::thread(outputToChart);
	threadOutputToFile_ = new std::thread(outputToFile);

}
//---------------------------------------------------------------------------
__fastcall TMainForm::~TMainForm()
{
	threadA_->detach();
	threadB_->detach();
	threadC_->detach();
	threadOutputToChart_->detach();
	threadOutputToFile_->detach();
	flagA_ = false;
	flagB_ = false;
	flagC_ = false;
	flagChartOutput_ = false;
	flagFileOutput_ = false;
	if(stopA_) mutexA_->unlock();
	if(stopB_) mutexB_->unlock();
	if(stopC_) mutexC_->unlock();
	if(stopChartOutput_) mutexOutputToChart_->unlock();
	if(stopFileOutput_) mutexOutputToFile_->unlock();
	//Memory clearing
	delete mutexA_;
	delete mutexB_;
	delete mutexC_;
	delete mutexOutputToChart_;
	delete mutexOutputToFile_;
	delete mutexClearToFile_;
	delete threadA_;
	delete threadB_;
	delete threadC_;
	delete threadOutputToChart_;
	delete threadOutputToFile_;
}
//---------------------------------------------------------------------------
//A procedure of managing A
 void __fastcall TMainForm::funcA()
{
	while(flagA_)
	{
		mutexA_->lock();
		double t;
		t = (std::time(0) - t_);
		a_ = 2*sin((vA_)*t)+5;
		mutexA_->unlock();
		Sleep(1000);
	};
}
//---------------------------------------------------------------------------
//A procedure of managing B
void __fastcall TMainForm::funcB()
{
	while(flagB_)
	{
		mutexB_->lock();
		double t;
		t = (std::time(0) - t_);
		b_ = sin((vB_)*t)+2;
		mutexB_->unlock();
		Sleep(1000);
	};
}
//---------------------------------------------------------------------------
//A procedure of managing C
void __fastcall TMainForm::funcC()
{
	while(flagC_)
	{
		mutexC_->lock();
		double t;
		t = (std::time(0) - t_);
		c_ = 4.5*sin((vC_)*t)+5.5;
		mutexC_->unlock();
		Sleep(1000);
	};
}
//---------------------------------------------------------------------------
//Procedure for output data in a chart
void __fastcall TMainForm::outputToChart()
{
	while(flagChartOutput_)
	{
		mutexOutputToChart_->lock();
		mutexClearToFile_->lock();
		double t;
		t = (std::time(0) - t_);
		Series2->AddXY(t,a_+b_*sin(t*c_));
		mutexClearToFile_->unlock();
		mutexOutputToChart_->unlock();
		Sleep(1000);
	};
}
//---------------------------------------------------------------------------
//Procedure for output data in a txt file
void __fastcall TMainForm::outputToFile()
{
	while(flagFileOutput_)
	{
		double t,y;
		mutexOutputToFile_->lock();
		std::ofstream fout;
		fout.open("test.txt", std::ios_base::app);
		t = (std::time(0) - t_);
		y = a_+b_*sin(t*c_);
		fout <<t<<" "<<y<<"\n";
		fout.close();
		mutexOutputToFile_->unlock();
		Sleep(1000);
	};
}
//---------------------------------------------------------------------------
//Procedure for close programm
void __fastcall TMainForm::btnExitClick(TObject *Sender)
{
 	MainForm->Close();
}
//---------------------------------------------------------------------------
//Control procedure for stopping the flow of coefficient A
void __fastcall TMainForm::btnStopAClick(TObject *Sender)
{
	if(!stopA_)
	{
		mutexA_->lock();
		btnStopA->Caption =  "Возобновить поток отвечающий за A";
	} else
	{
		mutexA_->unlock();
		btnStopA->Caption =  "Приостановить поток отвечающий за A";
	}
	stopA_=!stopA_;
}
//---------------------------------------------------------------------------
//Control procedure for stopping the flow of coefficient B
void __fastcall TMainForm::btnStopBClick(TObject *Sender)
{
	if(!stopB_)
	{
		mutexB_->lock();
		btnStopB->Caption =  "Возобновить поток отвечающий за B";
	} else
	{
	   mutexB_->unlock();
	   btnStopB->Caption =  "Приостановить поток отвечающий за B";
	}
	stopB_=!stopB_;
}
//---------------------------------------------------------------------------
//Control procedure for stopping the flow of coefficient C
void __fastcall TMainForm::btnStopCClick(TObject *Sender)
{
	if(!stopC_)
	{
		mutexC_->lock();
		btnStopC->Caption =  "Возобновить поток отвечающий за C";
	} else
	{
	   mutexC_->unlock();
	   btnStopC->Caption =  "Приостановить поток отвечающий за C";
	}
	stopC_=!stopC_;
}
//---------------------------------------------------------------------------
//Control procedure for stopping the flow of output data in a chart
 void __fastcall TMainForm::btnOutputToChartClick(TObject *Sender)
{
	if(!stopChartOutput_)
	{
		mutexOutputToChart_->lock();
		btnOutputToChart->Caption =  "Запустить вывод данных на график";
	} else
	{
		if(t_==0) t_ = std::time(0);
		mutexOutputToChart_->unlock();
		btnOutputToChart->Caption =  "Остановить вывод данных на график";
	}
	stopChartOutput_=!stopChartOutput_;
}
//---------------------------------------------------------------------------
//Control procedure for stopping the flow of output data in file
void __fastcall TMainForm::btnOutputToFileClick(TObject *Sender)
{
	 if(!stopFileOutput_)
	{
		mutexOutputToFile_->lock();
		btnOutputToFile->Caption =  "Запустить вывод данных в txt файл";
	} else
	{
    	if(t_==0) t_ = std::time(0);
		mutexOutputToFile_->unlock();
		btnOutputToFile->Caption =  "Остановить вывод данных в txt файл";
	}
	stopFileOutput_=!stopFileOutput_;
}
//---------------------------------------------------------------------------
//Procedure for setting coeffcient A
void __fastcall TMainForm::btnSetAClick(TObject *Sender)
{
	try{
		double a = lineEditA->Text.ToDouble();
		if(a<3||a>7) throw 0;
		a_ = a;
	}
	catch(...)
	{
		ShowMessage("Ошибка! Неверное значение!");
		lineEditA->Clear();
	}

}
//---------------------------------------------------------------------------
//Procedure for setting coeffcient B
void __fastcall TMainForm::btnSetBClick(TObject *Sender)
{
	try{
		double b = lineEditB->Text.ToDouble();
		if(b<1||b>3) throw 0;
		b_ = b;
	}
	catch(...)
	{
		ShowMessage("Ошибка! Неверное значение!");
		lineEditB->Clear();
	}
}
//---------------------------------------------------------------------------
//Procedure for setting coeffcient C
void __fastcall TMainForm::btnSetCClick(TObject *Sender)
{
	try{
		double c = lineEditC->Text.ToDouble();
		if(c<1||c>10) throw 0;
		c_ = c;
	}
	catch(...)
	{
		ShowMessage("Ошибка! Неверное значение!");
		lineEditC->Clear();
	}
}
//---------------------------------------------------------------------------
//Procedure for setting frequencys coeffcients
void __fastcall TMainForm::btnSetVAllClick(TObject *Sender)
{
	  try{
		double a = lineEditVA->Text.ToDouble();
		double b = lineEditVB->Text.ToDouble();
		double c = lineEditVC->Text.ToDouble();
		if(a<=0||b<=0||c<=0) throw 0;
		vA_ =  a;
		vB_ =  b;
		vC_ =  c;
	  }
	  catch(...)
	  {
		  ShowMessage("Одно или несколько полей содержат неверные данные");
	  }
}
//---------------------------------------------------------------------------
//Procedure for clearing a txt file
void __fastcall TMainForm::btnClearFileClick(TObject *Sender)
{
	mutexClearToFile_->lock();
	std::ofstream fout;
	fout.open("test.txt", std::ios_base::out);
	fout.close();
	mutexClearToFile_->unlock();
}
//---------------------------------------------------------------------------


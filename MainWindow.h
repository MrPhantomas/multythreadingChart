//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <thread>
#include <mutex>
#include <atomic>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart;
	TLineSeries *Series2;
	TButton *btnOutputToChart;
	TButton *btnOutputToFile;
	TButton *btnStopA;
	TButton *btnStopB;
	TButton *btnStopC;
	TButton *btnSetA;
	TButton *btnSetB;
	TButton *btnSetC;
	TEdit *lineEditA;
	TEdit *lineEditB;
	TEdit *lineEditC;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnSetVAll;
	TEdit *lineEditVA;
	TEdit *lineEditVB;
	TEdit *lineEditVC;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label10;
	TLabel *Label11;
	TButton *btnExit;
	TButton *btnClearFile;
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall btnStopAClick(TObject *Sender);
	void __fastcall btnStopBClick(TObject *Sender);
	void __fastcall btnStopCClick(TObject *Sender);
	void __fastcall btnSetAClick(TObject *Sender);
	void __fastcall btnSetBClick(TObject *Sender);
	void __fastcall btnSetCClick(TObject *Sender);
	void __fastcall btnOutputToChartClick(TObject *Sender);
	void __fastcall btnSetVAllClick(TObject *Sender);
	void __fastcall btnOutputToFileClick(TObject *Sender);
	void __fastcall btnClearFileClick(TObject *Sender);
private:	// User declarations
	//Atomic variable for time and coefficients
	std::atomic<double> t_,a_, b_, c_;
	//Atomic variable for frequencys
	std::atomic<double> vA_, vB_, vC_;
	//A procedure of managing A
	void __fastcall funcA();
	//Thread for coefficient A
	std::thread* threadA_;
	//Mutex for thread A
	std::mutex* mutexA_;
	//A procedure of managing B
	void __fastcall funcB();
	//Thread for coefficient B
	std::thread* threadB_;
	//Mutex for thread B
	std::mutex* mutexB_;
	//A procedure of managing C
	void __fastcall funcC();
	//Thread for coefficient C
	std::thread* threadC_;
	//Mutex for thread C
	std::mutex* mutexC_;
	//Procedure for output data in a chart
	void __fastcall outputToChart();
	//Thread for output data in a chart
	std::thread* threadOutputToChart_;
	//Mutex for thread output data in a chart
	std::mutex* mutexOutputToChart_;
	//Procedure for output data in a txt file
	void __fastcall outputToFile();
	//Thread for output data in a txt file
	std::thread* threadOutputToFile_;
	//Mutex for thread output data in a txt file  (stop)
	std::mutex* mutexOutputToFile_;
	//Mutex for thread output data in a txt file (clear)
	std::mutex* mutexClearToFile_;
	//Flags the completion of threads
	std::atomic<bool> flagA_,flagB_,flagC_,flagChartOutput_,flagFileOutput_;
	//Flags for stopping threads
	std::atomic<bool> stopA_,stopB_,stopC_,stopChartOutput_,stopFileOutput_;
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
	__fastcall ~TMainForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

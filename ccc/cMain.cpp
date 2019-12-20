#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

	EVT_BUTTON(10001, rightButtonClicked)
	EVT_BUTTON(10002, leftButtonClicked)
	EVT_COMMAND_SCROLL(10003,scrollBarMoved)
	EVT_COMMAND_SCROLL_THUMBRELEASE(10003,scrollBarReleased)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "AutonomTrain", wxPoint(100, 100), wxSize(720, 480))
{
	this->portName = "\\\\.\\COM3";
	this->arduino = new SerialPort(portName);

	this->train = new Train(1, arduino);

	m_scrollbarTempo = new wxScrollBar(this, 10003, wxPoint(150, 300), wxSize(200, 50));
	m_scrollbarTempo->SetRange(256);

	m_buttonLeft = new wxButton(this, 10002, "<", wxPoint(50, 300), wxSize(50, 50));
	m_buttonRight = new wxButton(this, 10001, ">", wxPoint(400, 300), wxSize(50, 50));


	m_textTempo = new wxStaticText(this, wxID_ANY, "tempo: ?", wxPoint(150, 100), wxSize(200, 50));

	
}

cMain::~cMain()
{
}

void cMain::rightButtonClicked(wxCommandEvent&evt)
{
	train->inputA = !train->inputA;
	train->inputB = !train->inputB;
	train->updateTrain();
	
}

void cMain::leftButtonClicked(wxCommandEvent& evt)
{
	train->inputA = !train->inputA;
	train->inputB = !train->inputB;
	train->updateTrain();
}

void cMain::scrollBarMoved(wxScrollEvent& evt)
{
	int tempo = m_scrollbarTempo->GetThumbPosition();
	train->enable = tempo;

	m_textTempo->SetLabel(wxString::Format(wxT("Tempo: %i"), tempo));
}

void cMain::scrollBarReleased(wxScrollEvent& evt)
{
	train->updateTrain();
}


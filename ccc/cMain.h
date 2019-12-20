#pragma once
#include "wx/wx.h"
#include "SerialPort.h"
#include "Train.h"
class cMain : public wxFrame
{
public:
    cMain();
    ~cMain();

public:
    const char* portName;
    SerialPort* arduino;

    Train* train;

    wxButton* m_buttonRight = nullptr;
    wxButton* m_buttonLeft = nullptr;
    wxScrollBar* m_scrollbarTempo = nullptr;

    wxStaticText* m_textTempo = nullptr;

    void rightButtonClicked(wxCommandEvent& evt);
    void leftButtonClicked(wxCommandEvent& evt);

    void scrollBarMoved(wxScrollEvent& evt);

    void scrollBarReleased(wxScrollEvent& evt);
    wxDECLARE_EVENT_TABLE();

};


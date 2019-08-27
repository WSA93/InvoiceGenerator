/***************************************************************
 * Name:      InvoiceGeneratorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "InvoiceGeneratorMain.h"
#include "InvoiceGenerator.h"
#include <wx/msgdlg.h>
#include <wx/notifmsg.h>

//(*InternalHeaders(InvoiceGeneratorFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(InvoiceGeneratorFrame)
const long InvoiceGeneratorFrame::ID_BUTTON1 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT1 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT2 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT3 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT4 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT5 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT6 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT7 = wxNewId();
const long InvoiceGeneratorFrame::ID_STATICTEXT8 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL3 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL4 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL5 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL6 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL7 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL8 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL1 = wxNewId();
const long InvoiceGeneratorFrame::ID_SPINCTRL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(InvoiceGeneratorFrame,wxFrame)
    //(*EventTable(InvoiceGeneratorFrame)
    //*)
END_EVENT_TABLE()

InvoiceGeneratorFrame::InvoiceGeneratorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(InvoiceGeneratorFrame)
    Create(parent, wxID_ANY, _("Maritek Invoice"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(700,500));
    SetForegroundColour(wxColour(0,0,160));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    Button1 = new wxButton(this, ID_BUTTON1, _("GENERATE INVOICE"), wxPoint(264,432), wxSize(176,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxColour(0,0,160));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("KPT/UNIT-3/KPT"), wxPoint(136,48), wxSize(152,18), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("CONTAINER SERVICES"), wxPoint(136,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("DETENTIONS"), wxPoint(136,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("IMPORTS 40\' CONTAINERS"), wxPoint(136,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("IMPORTS 20\' CONTAINEERS"), wxPoint(136,240), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("REJECTED CONTAINERS"), wxPoint(136,288), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("KPT/UNIT-3/PQ"), wxPoint(136,336), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("KPT/MATCO-1/KPT"), wxPoint(136,384), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("0"), wxPoint(440,136), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL3"));
    SpinCtrl3->SetValue(_T("0"));
    wxFont SpinCtrl3Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl3->SetFont(SpinCtrl3Font);
    SpinCtrl4 = new wxSpinCtrl(this, ID_SPINCTRL4, _T("0"), wxPoint(440,184), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL4"));
    SpinCtrl4->SetValue(_T("0"));
    wxFont SpinCtrl4Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl4->SetFont(SpinCtrl4Font);
    SpinCtrl5 = new wxSpinCtrl(this, ID_SPINCTRL5, _T("0"), wxPoint(440,232), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL5"));
    SpinCtrl5->SetValue(_T("0"));
    wxFont SpinCtrl5Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl5->SetFont(SpinCtrl5Font);
    SpinCtrl6 = new wxSpinCtrl(this, ID_SPINCTRL6, _T("0"), wxPoint(440,280), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL6"));
    SpinCtrl6->SetValue(_T("0"));
    wxFont SpinCtrl6Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl6->SetFont(SpinCtrl6Font);
    SpinCtrl7 = new wxSpinCtrl(this, ID_SPINCTRL7, _T("0"), wxPoint(440,328), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL7"));
    SpinCtrl7->SetValue(_T("0"));
    wxFont SpinCtrl7Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl7->SetFont(SpinCtrl7Font);
    SpinCtrl8 = new wxSpinCtrl(this, ID_SPINCTRL8, _T("0"), wxPoint(440,376), wxDefaultSize, 0, 0, 10, 0, _T("ID_SPINCTRL8"));
    SpinCtrl8->SetValue(_T("0"));
    wxFont SpinCtrl8Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl8->SetFont(SpinCtrl8Font);
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxPoint(440,40), wxDefaultSize, 0, 0, 50, 0, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("0"));
    wxFont SpinCtrl1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl1->SetFont(SpinCtrl1Font);
    SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL2, _T("0"), wxPoint(440,88), wxDefaultSize, 0, 0, 50, 0, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("0"));
    wxFont SpinCtrl2Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    SpinCtrl2->SetFont(SpinCtrl2Font);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnButton1Click1);
    Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl3Change);
    Connect(ID_SPINCTRL4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl4Change);
    Connect(ID_SPINCTRL5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl5Change);
    Connect(ID_SPINCTRL6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl6Change);
    Connect(ID_SPINCTRL7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl7Change);
    Connect(ID_SPINCTRL8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl8Change);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl1Change1);
    Connect(ID_SPINCTRL2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&InvoiceGeneratorFrame::OnSpinCtrl2Change1);
    //*)
}

InvoiceGeneratorFrame::~InvoiceGeneratorFrame()
{
    //(*Destroy(InvoiceGeneratorFrame)
    //*)
}

void InvoiceGeneratorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

///---------------------------------------------------------------------------------///

int q0 = 0;
int q1 = 0;
int q2 = 0;
int q3 = 0;
int q4 = 0;
int q5 = 0;
int q6 = 0;
int q7 = 0;

void InvoiceGeneratorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void InvoiceGeneratorFrame::OnSpinCtrl1Change1(wxSpinEvent& event)
{
   q0 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl2Change1(wxSpinEvent& event)
{
  q1 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl3Change(wxSpinEvent& event)
{
   q2 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl4Change(wxSpinEvent& event)
{
   q3 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl5Change(wxSpinEvent& event)
{
   q4 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl6Change(wxSpinEvent& event)
{
   q5 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl7Change(wxSpinEvent& event)
{
   q6 = event.GetInt();
}

void InvoiceGeneratorFrame::OnSpinCtrl8Change(wxSpinEvent& event)
{
   q7 = event.GetInt();
}

void InvoiceGeneratorFrame::OnButton1Click1(wxCommandEvent& event)
{
   wxNotificationMessage message;
   InvoiceGenerator invGen;

   invGen.inputQuantities(q0,q1,q2,q3,q4,q5,q6,q7);
   invGen.billCalculation();
   invGen.generateInvoice();

   message.SetMessage("Please wait invoice is opening...");
   message.Show(3);

   system(invGen.fileName().c_str());
   Close();
}

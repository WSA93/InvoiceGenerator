/***************************************************************
 * Name:      InvoiceGeneratorMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef INVOICEGENERATORMAIN_H
#define INVOICEGENERATORMAIN_H

//(*Headers(InvoiceGeneratorFrame)
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class InvoiceGeneratorFrame: public wxFrame
{
    public:

        InvoiceGeneratorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~InvoiceGeneratorFrame();

    private:

        //(*Handlers(InvoiceGeneratorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnSpinCtrl1Change(wxSpinEvent& event);
        void OnSpinCtrl2Change(wxSpinEvent& event);
        void OnSpinCtrl3Change(wxSpinEvent& event);
        void OnSpinCtrl4Change(wxSpinEvent& event);
        void OnSpinCtrl5Change(wxSpinEvent& event);
        void OnSpinCtrl6Change(wxSpinEvent& event);
        void OnSpinCtrl7Change(wxSpinEvent& event);
        void OnSpinCtrl8Change(wxSpinEvent& event);
        void OnSpinCtrl1Change1(wxSpinEvent& event);
        void OnSpinCtrl2Change1(wxSpinEvent& event);
        //*)

        //(*Identifiers(InvoiceGeneratorFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_SPINCTRL3;
        static const long ID_SPINCTRL4;
        static const long ID_SPINCTRL5;
        static const long ID_SPINCTRL6;
        static const long ID_SPINCTRL7;
        static const long ID_SPINCTRL8;
        static const long ID_SPINCTRL1;
        static const long ID_SPINCTRL2;
        //*)

        //(*Declarations(InvoiceGeneratorFrame)
        wxSpinCtrl* SpinCtrl4;
        wxSpinCtrl* SpinCtrl1;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxStaticText* StaticText8;
        wxSpinCtrl* SpinCtrl7;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxSpinCtrl* SpinCtrl3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxSpinCtrl* SpinCtrl2;
        wxSpinCtrl* SpinCtrl5;
        wxStaticText* StaticText4;
        wxSpinCtrl* SpinCtrl6;
        wxSpinCtrl* SpinCtrl8;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // INVOICEGENERATORMAIN_H

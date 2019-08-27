/***************************************************************
 * Name:      InvoiceGeneratorApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-06-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "InvoiceGeneratorApp.h"

//(*AppHeaders
#include "InvoiceGeneratorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(InvoiceGeneratorApp);

bool InvoiceGeneratorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	InvoiceGeneratorFrame* Frame = new InvoiceGeneratorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

#include"InvoiceGenerator.h"

InvoiceGenerator::InvoiceGenerator()
{
   current = time(0);
   date = localtime(&current);
   total = 0.0;
   comission = 0.0;
   finalTotal = 0.0;
}

Invoice invoice[8];

void InvoiceGenerator::inputQuantities(int q0,int q1,int q2,int q3,int q4,int q5,int q6,int q7)
{
    invoice[0].route = "KPT/UNIT-3/KPT";
    invoice[0].quantity = q0;
    invoice[0].rate = 9524;
    invoice[0].ammount = 0;

    invoice[1].route = "Container Services";
    invoice[1].quantity = q1;
    invoice[1].rate = 300;
    invoice[1].ammount = 0;

    invoice[2].route = "Detentions";
    invoice[2].quantity = q2;
    invoice[2].rate = 4000;
    invoice[2].ammount = 0;

    invoice[3].route = "Imports (40' Containers)";
    invoice[3].quantity = q3;
    invoice[3].rate = 15000;
    invoice[3].ammount = 0;

    invoice[4].route = "Imports (20' Containers)";
    invoice[4].quantity = q4;
    invoice[4].rate = 9524;
    invoice[4].ammount = 0;

    invoice[5].route = "Rejected Containers";
    invoice[5].quantity = q5;
    invoice[5].rate = 9524;
    invoice[5].ammount = 0;

    invoice[6].route = "KPT/UNIT-3/PQ";
    invoice[6].quantity = q6;
    invoice[6].rate = 12381;
    invoice[6].ammount = 0;

    invoice[7].route = "KPT/MATCO-1/KPT";
    invoice[7].quantity = q7;
    invoice[7].rate = 9524;
    invoice[7].ammount = 0;
}

void InvoiceGenerator::billCalculation()
{
   invoice[0].ammount = invoice[0].quantity * invoice[0].rate;
   invoice[1].ammount = invoice[1].quantity * invoice[1].rate;
   invoice[2].ammount = invoice[2].quantity * invoice[2].rate;
   invoice[3].ammount = invoice[3].quantity * invoice[3].rate;
   invoice[4].ammount = invoice[4].quantity * invoice[4].rate;
   invoice[5].ammount = invoice[5].quantity * invoice[5].rate;
   invoice[6].ammount = invoice[6].quantity * invoice[6].rate;
   invoice[7].ammount = invoice[7].quantity * invoice[7].rate;

   total = invoice[0].ammount + invoice[1].ammount + invoice[2].ammount + invoice[3].ammount +
   invoice[4].ammount + invoice[5].ammount + invoice[6].ammount + invoice[7].ammount;

   comission = (total * 5) / 100;
   finalTotal = total + comission;
}

 string InvoiceGenerator::displayCurrentDate()
 {
    string day = "";
    string month = "";
    string returnDate = "";

    if(date->tm_mday < 10)
    {
      day = "0" + patch::to_string(date->tm_mday) + "/";
    }
    else
    {
      day = patch::to_string(date->tm_mday) + "/";
    }

    if(1+date->tm_mon < 10)
    {
      month = "0" + patch::to_string(1+date->tm_mon) + "/" + patch::to_string(1900+date->tm_year);
    }
    else
    {
      month = patch::to_string(1+date->tm_mon) + "/" + patch::to_string(1900+date->tm_year);
    }

    return "Date: " + day + month;
}

string InvoiceGenerator::displayBillPeriod()
{
    string returnPeriod = "";

    // For first bill of the year
    if(date->tm_mday >= 1 && date->tm_mday <= 15 && 1+date->tm_mon == 1)
    {
       returnPeriod = "From 16/12 To 31/12 " + patch::to_string(1900+date->tm_year-1);
    }

    else if(date->tm_mday >= 16 && date->tm_mday <= 31)
    {
        if(1+date->tm_mon < 10)
        {
           returnPeriod = "From 01/0" + patch::to_string(1+date->tm_mon) + " To 15/0" + patch::to_string(1+date->tm_mon) + " " + patch::to_string(1900+date->tm_year);
        }
        else
        {
           returnPeriod = "From 01/" + patch::to_string(1+date->tm_mon) + " To 15/" + patch::to_string(1+date->tm_mon) + " " + patch::to_string(1900+date->tm_year);
        }
    }

    else if((date->tm_mday >= 1 && date->tm_mday <= 15) &&
           (1+date->tm_mon-1 == 4 || 1+date->tm_mon-1 == 6 || 1+date->tm_mon-1 == 9 ||
            1+date->tm_mon-1 == 11))  // For months having 30 days
    {
        if(1+date->tm_mon-1 < 10)
        {
          returnPeriod = "From 16/0" + patch::to_string(1+date->tm_mon-1) + " To 30/0" + patch::to_string(1+date->tm_mon-1) + " " + patch::to_string(1900+date->tm_year);
        }
        else
        {
          returnPeriod = "From 16/" + patch::to_string(1+date->tm_mon-1) + " To 30/" + patch::to_string(1+date->tm_mon-1) + " " + patch::to_string(1900+date->tm_year);
        }
    }

    else if((date->tm_mday >= 1 && date->tm_mday <= 15) &&
           (1+date->tm_mon-1 == 1 || 1+date->tm_mon-1 == 3 || 1+date->tm_mon-1 == 5 ||
            1+date->tm_mon-1 == 7 || 1+date->tm_mon-1 == 8 || 1+date->tm_mon-1 == 10))// For months having 31 days
    {
        if(1+date->tm_mon < 10)
        {
          returnPeriod = "From 16/0" + patch::to_string(1+date->tm_mon-1) + " To 31/0" + patch::to_string(1+date->tm_mon-1) + " " + patch::to_string(1900+date->tm_year);
        }
        else
        {
          returnPeriod = "From 16/" + patch::to_string(1+date->tm_mon-1) + " To 31/" + patch::to_string(1+date->tm_mon-1) + " " + patch::to_string(1900+date->tm_year);
        }
    }

    else if((1+date->tm_mon-1 == 2) && (date->tm_mday >= 1 && date->tm_mday <= 15))  // For February
    {
       returnPeriod = "From 16/0" + patch::to_string(1+date->tm_mon-1) + " To 28/0" + patch::to_string(1+date->tm_mon-1) + " " + patch::to_string(1900+date->tm_year);
    }

    return returnPeriod;

}

string InvoiceGenerator::displayInvoiceNo()
{
    int invNo;

    ifstream ifn;
    ifn.open("C:\\InvoiceGenerator\\MainFolder\\InvoiceNo\\InvoiceNo.txt");
    while(ifn >> invNo)
    {

    }
    ifn.close();

    ofstream ofn;
    ofn.open("C:\\InvoiceGenerator\\MainFolder\\InvoiceNo\\InvoiceNo.txt", ios::app);
    ofn << "\n";
    ofn << invNo+1;
    ofn.close();

    invoiceNo = patch::to_string(invNo+1);
    return "Invoice No: MR-" + invoiceNo + "/" + patch::to_string(1900+date->tm_year);
}

string InvoiceGenerator::displayTotalInWords()
{
   string words[] =
    {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ",
    "Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen ","Twenty ",
    "Twenty One ","Twenty Two ","Twenty Three ","Twenty Four ","Twenty Five ","Twenty Six ","Twenty Seven ","Twenty Eight ","Twenty Nine ","Thirty ",
    "Thirty One ","Thirty Two ","Thirty Three ","Thirty Four ","Thirty Five ","Thirty Six ","Thirty Seven ","Thirty Eight ","Thirty Nine ","Forty ",
    "Forty One ","Forty Two ","Forty Three ","Forty Four ","Forty Five ","Forty Six ","Forty Seven ","Forty Eight ","Forty Nine ","Fifty ",
    "Fifty One ","Fifty Two ","Fifty Three ","Fifty Four ","Fifty Five ","Fifty Six ","Fifty Seven ","Fifty Eight ","Fifty Nine ","Sixty ",
    "Sixty One ","Sixty Two ","Sixty Three ","Sixty Four ","Sixty Five ","Sixty Six ","Sixty Seven ","Sixty Eight ","Sixty Nine ","Seventy ",
    "Seventy One ","Seventy Two ","Seventy Three ","Seventy Four ","Seventy Five ","Seventy Six ","Seventy Seven ","Seventy Eight ","Seventy Nine ","Eighty ",
    "Eighty One ","Eighty Two ","Eighty Three ","Eighty Four ","Eighty Five ","Eighty Six ","Eighty Seven ","Eighty Eight ","Eighty Nine ","Ninety ",
    "Ninety One ","Ninety Two ","Ninety Three ","Ninety Four ","Ninety Five ","Ninety Six ","Ninety Seven ","Ninety Eight ","Ninety Nine "};

   string num1 = "";
   string return1 = "";
   string return2 = "";
   string return3 = "";
   string return4 = "";
   num1 = patch::to_string(round(finalTotal));
   string a = patch::to_string(num1[1]);
   string b = patch::to_string(num1[2]);
   string c = a+b;

    istringstream buffer(c);
    int value;
    buffer >> value;

    if(num1.length() == 6)
    {
      for(int i=1; i<10; ++i)
      {
        if(num1[0]-48 == i)
        {
            return1 = words[i] + "Hundred ";
        }
      }

        if(value == 0)
        {
            return2 = "Thousand ";
        }
        else
        {
            for(int i=1; i<100; ++i)
            {
               if(value == i)
               {
                 return2 =  words[i] + "Thousand ";
               }
            }

        }


        if(num1[3]-48 == 0)
        {
          return3 =  "";
        }
        else
        {
          for(int i=1; i<10; ++i)
          {
            if(num1[3]-48 == i)
            {
              return3 = words[i] + "Hundred ";
            }
          }
        }

        a = patch::to_string(num1[4]);
        b = patch::to_string(num1[5]);
        c = a+b;

        istringstream buffer1(c);
        buffer1 >> value;


        if(value == 0)
        {
            return4 = "Only.";
        }
        else
        {
           for(int i=1; i<100; ++i)
           {
              if(value == i)
              {
                return4 =  words[i] + "Only.";
              }
           }

        }
    }

    else if(num1.length() == 5)
    {
        a = patch::to_string(num1[0]);
        b = patch::to_string(num1[1]);
        c = a+b;

        istringstream buffer2(c);
        buffer2 >> value;


        for(int i=1; i<100; ++i)
        {
            if(value == i)
            {
                return1 = words[i] + "Thousand ";
            }
        }

        if(num1[2]-48 == 0 && num1[3]-48 == 0 && num1[4]-48 == 0)
        {
            return2 = "Only.";
        }

        for(int i=1; i<10; ++i)
        {
            if(num1[2]-48 == i)
            {
                return3 =  words[i] + "Hundred ";
            }
        }

        a = patch::to_string(num1[3]);
        b = patch::to_string(num1[4]);
        c = a+b;

        istringstream buffer3(c);
        buffer3 >> value;

        for(int i=1; i<100; ++i)
        {
            if(value == i)
            {
               return4 =  words[i] + "Only.";
            }
        }

    }
        return "RUPEES: " + return1 + return2 + return3 + return4;
}

string InvoiceGenerator::fileName()
{
    string returnFileName = "";
    returnFileName = "Invoice_" + invoiceNo + ".docx";

    return "C:\\InvoiceGenerator\\MainFolder\\Invoices\\" + returnFileName;
}

void InvoiceGenerator::generateInvoice()
{
          WordProcessingCompiler& l_compiler = WordProcessingCompiler::getInstance();
          l_compiler.compile("C:\\InvoiceGenerator\\MainFolder\\Template\\Invoice.docx" , "C:\\InvoiceGenerator\\MainFolder\\Template\\Invoice.dfw");

          WordProcessingMerger& l_merger = WordProcessingMerger::getInstance();

          l_merger.load("C:\\InvoiceGenerator\\MainFolder\\Template\\Invoice.dfw");

          l_merger.setClipboardValue("Table1", "Date", displayCurrentDate() + "\n" + displayInvoiceNo());
          l_merger.paste("Table1");

          l_merger.setClipboardValue("Table2", "Period", displayBillPeriod());
          l_merger.paste("Table2");

          if(invoice[0].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[0].route);

             if(invoice[0].quantity < 10)
             {
                string temp = patch::to_string(invoice[0].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[0].quantity);
             }

                l_merger.setClipboardValue("Table22", "Rate", invoice[0].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[0].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[1].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[1].route);

             if(invoice[1].quantity < 10)
             {
                string temp = patch::to_string(invoice[1].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[1].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[1].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[1].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[1].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[2].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[2].route);

             if(invoice[2].quantity < 10)
             {
                string temp = patch::to_string(invoice[2].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[2].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[2].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[2].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[2].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[3].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[3].route);

             if(invoice[3].quantity < 10)
             {
                string temp = patch::to_string(invoice[3].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[3].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[3].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[3].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[3].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[4].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[4].route);

             if(invoice[4].quantity < 10)
             {
                string temp = patch::to_string(invoice[4].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[4].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[4].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[4].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[4].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[5].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[5].route);

             if(invoice[5].quantity < 10)
             {
                string temp = patch::to_string(invoice[5].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[5].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[5].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[5].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[5].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[6].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[6].route);

             if(invoice[6].quantity < 10)
             {
                string temp = patch::to_string(invoice[6].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[6].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[6].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[6].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[6].ammount);
                l_merger.paste("Table22");
          }

          if(invoice[7].quantity != 0)
          {
             l_merger.setClipboardValue("Table22", "Description", invoice[7].route);

             if(invoice[7].quantity < 10)
             {
                string temp = patch::to_string(invoice[7].quantity);
                l_merger.setClipboardValue("Table22", "Quantity", "0" + temp);
             }
             else
             {
                l_merger.setClipboardValue("Table22", "Quantity", invoice[7].quantity);
             }

                l_merger.setClipboardValue("Table22", "Quantity", invoice[7].quantity);
                l_merger.setClipboardValue("Table22", "Rate", invoice[7].rate);
                l_merger.setClipboardValue("Table22", "Amou", invoice[7].ammount);
                l_merger.paste("Table22");
          }


             l_merger.setClipboardValue("Table3", "SubTotal", total);
             l_merger.setClipboardValue("Table3", "Comision", round(comission));
             l_merger.setClipboardValue("Table3", "Total",    round(finalTotal));
             l_merger.setClipboardValue("Table3", "InWords", displayTotalInWords());
             l_merger.paste("Table3");

             l_merger.save(fileName().c_str());
}

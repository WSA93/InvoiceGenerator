#ifndef INVOICE_GENERATOR_H
#define INVOICE_GENERATOR_H
#define BILL_GENERATOR_H
#include"WordProcessingCompiler.h"
#include"WordProcessingMerger.h"
#include<ctime>
#include<math.h>
#include<string>
#include<sstream>
#include<fstream>
#include<windows.h>
using namespace std;
using namespace DocxFactory;

class InvoiceGenerator
{
    public:
           InvoiceGenerator();
           void inputQuantities(int,int,int,int,int,int,int,int);
           void billCalculation();
           void generateInvoice();
           string displayCurrentDate();
           string displayBillPeriod();
           string displayInvoiceNo();
           string displayTotalInWords();
           string fileName();

    private:
            time_t current;
            tm* date;
            long double total;
            long double comission;
            long double finalTotal;
            string invoiceNo;
};
#endif // INVOICE_GENERATOR_H

struct Invoice
{
   string route;
   int quantity;
   int rate;
   int ammount;
};

namespace patch   // Function to convert any data type to string.
{
      template < typename T > string to_string(const T& n)
      {
          ostringstream stm ;
          stm << n ;
          return stm.str() ;
      }
}


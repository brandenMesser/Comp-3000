/* Name: Branden Messer
 * filename: hw3.cpp
 * Compiler: g++ -o hw3 hw3.cpp
 * Sample usage: ./hw3
 */


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	// Varibles for hw3.
	 double loanAm;
	 double interRate;
	 double inter;
         double totalInter;
	 double principle;
	 double monthsPay;
	 double beforePay;
	 double rate;
         int months = 0;         
			
	//I used this to set my decimals to 2.                            	            
	 cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);

	//Enter loan Amount. 
	 cout << "Loan Amount: ";
         cin >> loanAm;       			   	               			     
	
	//Enter the inter rate.
	 cout << "Interest Rate (% per year): ";
	 cin >> interRate;
                           			   		      		      	
	//Enter the monthly payments.
	 cout << "Monthly Payments: ";
	 cin >> monthsPay;
	                            			   		      		      		         
	                            			   		      		      		            
	//Making the top of the table.
	 cout << "******************************************************" << endl;
	 cout <<  "       Amortization Table" << endl;
	 cout << "******************************************************" << endl;
	
	 cout << left << setw(10) << "Month" << left << setw(10) << "Balance" << left << setw(10) << "Payment" << left << setw(10)  << "Rate" << left << setw(10) << "Interest" << left << setw(10) << "Principal" << endl;
     	//I used this if statement to get the first line of value 
	
	 if (months == 0) {
	 cout << left << setw(10) << months << "$" << left << setw(10) << loanAm << left << setw(10) << "N/A" << left << setw(10)   << "N/A" << left << setw(10) << "N/A" <<  left << setw(10)  << "N/A" << endl;
		months++;                            			   		      		      		            	     }             			   		      		      		            	                  				           			   		      		      		            	      
	//I used this if statement to get the rest of the values                           			   		      		      		            	                  					                  	                else {
                           			   		      		      		            	                  					                  	          	          		      	   	      		//This while loop will get me all the values until the last line.
	
	 while (loanAm * rate + loanAm > monthsPay) {
		 rate = (interRate/12)/100; //Used this to calculate rate.
	         beforePay = loanAm; 
                 loanAm = (loanAm - monthsPay) + (rate * loanAm);
		 inter = beforePay * rate; //used this to get the inter.
	         principle = beforePay - loanAm; //Used this to get the priniciple.
	

	//This if statement is used incase someone make a loan impossibe to pay back by the regular payment.
	
	 if (inter >= monthsPay) {
		 cout << endl; 
		 cout << "Error: The interest can't be larger or the same size as the payment." << endl;
		 cout << "So you decide to give it back with interest." << endl;
		 cout << endl;
	       	 break;
	
	//To set up the rest of the table.			
	}
	 cout << left << setw(10) << months << "$" << left << setw(10)  << loanAm << "$" << left << setw(10)  << monthsPay << left << setw(10)  << interRate/12 << "$" << left << setw(10)  <<  inter << "$" << left << setw(10)  << principle << endl;

	 months++; //Keep track of months.
	 totalInter += inter; //Keep the total inter.
	 }
	
	//For the last line.
	
	while(loanAm != 0) {
		rate = (interRate/12)/100; //Same as before.
		inter = monthsPay * rate; //Same as before.
		monthsPay = loanAm + inter; //To get whats left.
		principle = loanAm; 
		loanAm = 0;

	//The final payment line
	 cout << left << setw(10) << months << "$" << left << setw(10) <<  loanAm << "$" << left << setw(10) <<  monthsPay << left << setw(10) << left << setw(10) <<  interRate/12 << "$" << left << setw(10) << inter << "$" << left << setw(10)  << principle << endl;
	
	 totalInter += inter;//Still keeping track.
	
	}
	
//The last part of the table.
	
cout << "******************************************************" << endl;
cout << endl;
cout << "It takes " << months << " months to pay off the loan." << endl;
cout << "Total interest paid is: " << "$" << totalInter << endl;
	
return 0;
}                            			   		      		      		            	                  					                  	          	          		      	   	      		   		            		                        		      		                                 		      		                                                                                                            		      		                     	             	       	                           		   		            		                                                   				      		                     	             	             	       	      			                   	            	   

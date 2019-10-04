//GROUP 8 ~ PR AIRLINES BY PR CODES
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h> // for strcpy
#include <string>
#include <unistd.h> //sleep function
#include <windows.h> // WinApi header file
#include <ctime>

using namespace std;
////////////////////////////////////////////////////////////////////////////////
int hours = 7; //timer for STANDBY
int minutes = 60;//timer for STANDBY
int seconds = 60;//timer for STANDBY
int count=0; //global variables
int counter=10; //global variables
double miles=0;// miles points
double points = 0.5; // 1km = 0.5pts
string U_input; // user input seat
int seatChoosen;
int busSeat= 120;
int ecoSeat= 80;
int Rows = 7; //for tSeats
int col = 5; //for seat
typedef char* IntArrayPtr;// seat class
IntArrayPtr *arrayS = new IntArrayPtr[Rows]; //seat class
void seatSelect();

void abroad(); //display schedule of all international flights
void local(); //display schedule of all local flights
void time(); // local time
void delayStand();
void displayClock(); // main
void adminMenu();
void timer();

int choiceA; // Baggage
int choiceD; // Baggage
int luggageP; // calculation
int luggagePR; // calculation
int payments; // calculation overall payment
int tprice; // cost
int Price; // cost
////////////////////////////////////////////////////////////////////////////////
class Admin
{
  private :
  string username;
  string password;
public:
    void login_page();
};
////////////////////////////////////////////////////////////////////////////////
class localBooking //class  for LOCAL FLIGHT
{
  protected:  //protected members
    int lref; // reference no. for flight cancellation
    char flightLocal[10],ArrivalT[7],DepartureT[7];
    long int date; //date of destination
    int select; //switch case for airlines
    int arr; // ARRIVAL
    int dep; // DEPARTURE
  //  int TicketPrice;
  friend class payment;
  friend class seats;
  public://public member functions
        void l_ref() // member card
          {
            count++; // counter as for increment
            lref=count; // reference no. is equals to existing booked ticket
          }
////////////////////////////////////////////////////////////////////////////////
int travelDetailL() // function declaration and definition for domestic journey
{       time();
        cout << endl;
        cout << setw(2) << "\n\tPlease, enter the date in the following format ! (DDMMYYYY). " << "Please enter a valid date." <<  endl;
        cout << setw(2)  << "\tDate        :: ";
        cin >> date;
        cout << endl;

        cout << setw(2) << "\t1.KUALA LUMPUR [ KL ] \t2.PENANG [ PG ] \t3.KUANTAN [ KT ] \t4.LANGKAWI [ LG ]" << endl << endl;
        cout << setw(2)  << "\tPLEASE ENTER YOUR DEPARTURE DESTINATION   " << endl;
        cout << setw(2)  << "\tDestination :: ";
        cin >> dep;

        cout << endl;
        cout << setw(2)  << "\tPLEASE ENTER YOUR ARRIVAL DESTINATION     " << endl;
        cout << setw(2)  << "\tArrival     :: ";
        cin >> arr;
        system("CLS");
        cout << endl;
        // MANY TO MANY //MIX MATCH //FOLLOWED SET METHOD(PROBABILITY) T0 DISPLAY LOCAL COUNTRIES.FOR better understanding this is how it works, LOCAL={(1,1),(1,2),(1,3),(1,4),(2,1),(2,2),(2,3),(2,4),(3,1),(3,2),(3,3),(3,4),(4,1),(4,2),(4,3),(4,4)}
        // The repeating digits such (1,1) & etc will be removed to avoid the same ARRIVAL and DEPARTURE inputs.
        if((dep==1 && arr==2) || (dep==2 && arr==1))
        //KL - PG [(1,2)]  ,PG - KL [(2,1)]
        {
            cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
            cout << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
            cout << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "1) AIR ASIA\tAK100\t\tKL - PG \t08.00 -> 11.00\t\tRM80\n";
            cout << setw(2)  << "2) MALINDO \tCA300\t\tKL - PG \t14.00 -> 17.00\t\tRM90\n";
            cout << setw(2)  << "3) MAS     \tMH500\t\tKL - PG \t19.00 -> 22.00\t\tRM70\n" <<endl;
            cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }

else if((dep==1 && arr==3) || (dep==3 && arr==1))
        //KL - KT [(1,3)] , KT - KL [(3,1)]
        {
            cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS"  << endl;
            cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
            cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
            cout << setw(2)  << "1) AIR ASIA\tAK110\t\tKL - KT \t08.00 -> 11.00\t\tRM80\n";
            cout << setw(2)  << "2) MALINDO \tCA310\t\tKL - KT \t14.00 -> 17.00\t\tRM90\n";
            cout << setw(2)  << "3) MAS     \tMH510\t\tKL - LT \t19.00 -> 22.00\t\tRM70\n";
            cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if((dep==1 && arr==4) || (dep==4 && arr==1))
        //KL - LG [(1,4)] , LG - KL [(4,1)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) AIR ASIA\tAK120\t\tKL - LG \t08.00 -> 11.00\t\tRM80\n";
          cout << setw(2)  << "2) MALINDO \tCA320\t\tKL - LG \t14.00 -> 17.00\t\tRM90\n";
          cout << setw(2)  << "3) MAS     \tMH520\t\tKL - LG \t19.00 -> 22.00\t\tRM70\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if((dep==2 && arr==3) || (dep==3 && arr==2))
        //PG - KT [(2,3)] , KT - PG [(3,2)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) AIR ASIA\tAK130\t\tPG - KT \t08.00 -> 11.00\t\tRM80\n";
          cout << setw(2)  << "2) MALINDO \tCA330\t\tPG - KT \t14.00 -> 17.00\t\tRM90\n";
          cout << setw(2)  << "3) MAS     \tMH530\t\tPG - KT \t19.00 -> 22.00\t\tRM70\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if((dep==2 && arr==4) || (dep==4 && arr==2))
        //PG - LG [(2,4)] , LG - PG [(4,2)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" <<  endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) AIR ASIA\tAK140\t\tPG - LG \t08.00 -> 11.00\t\tRM80\n";
          cout << setw(2)  << "2) MALINDO \tCA340\t\tPG - LG \t14.00 -> 17.00\t\tRM90\n";
          cout << setw(2)  << "3) MAS     \tMH540\t\tPG - LG \t19.00 -> 22.00\t\tRM70\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if((dep==3 && arr==4) || (dep==4 && arr==3))
        //KT - LG [(3,4)] , LG - KT [(4,3)]
        {
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" <<  endl;
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "1) AIR ASIA\tAK250\t\tKT - LG \t08.00 -> 11.00\t\tRM80\n";
           cout << setw(2)  << "2) MALINDO \tCA350\t\tKT - LG \t14.00 -> 17.00\t\tRM90\n";
           cout << setw(2)  << "3) MAS     \tCA550\t\tKT - LG \t19.00 -> 22.00\t\tRM70\n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(arr==dep)// For (1,1),(2,2),(3,3),(4,4)
        {
            cout << setw(2)  << "\n\tARRIVAL and DEPARTURE locations can't be same.\n\t Please, Try again with a new input\n\n\n" << endl;
            return  travelDetailL(); //returns to the locations of local flight
        }
        else
        {
            cout << setw(2)  <<"\n\tInvalid input had been entered\n\tPlease, Try again\n\n\n" << endl;
            return  travelDetailL();
        }

}
////////////////////////////////////////////////////////////////////////////////
    int  selectFlightL() //function declaration and definition for selecting flight
        {   cout << setw(2)  << "\n\tEnter your choice :: ";
            cin >> select;
            system("CLS");
            switch(select) // switch case selection
            {
              case 1://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type     :: ";
                    cout << setw(2)  << "AIR ASIA"<<endl;
                    strcpy(flightLocal,"AIR ASIA");//copy to string
                    cout << setw(2)  << "\tDeparture Time   :: 08:00"<<endl;
                    cout << setw(2)  << "\tArrival Time     :: 11:00"<<endl;
                    Price=80;
                    miles = 8500.00;
                    cout << setw(2)  << "\tMiles Point      :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price     :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalT,"8:00"); //copy to string
                    strcpy(DepartureT,"11:00");// copy to string
                    break;

              case 2://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type     :: ";
                    cout << setw(2)  << "MALINDO"<<endl;
                    strcpy(flightLocal,"MALINDO");//copy to string
                    cout << setw(2)  << "\tDeparture Time   :: 14:00"<<endl;
                    cout << setw(2)  << "\tArrival Time     :: 17:00"<<endl;
                    Price=90;
                    miles = 5820.00;
                    cout << setw(2)  << "\tMiles Point      :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price     :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalT,"14:00");//copy to string
                    strcpy(DepartureT,"17:00");//copy to string
                    break;

              case 3://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type     :: ";
                    cout << setw(2)  << "MAS"<<endl;
                    strcpy(flightLocal,"MAS");//copy to string
                    cout << setw(2)  << "\tDeparture Time   :: 19:00" << endl;
                    cout << setw(2) <<  "\tArrival Time     :: 22:00" << endl;
                    Price=70;
                    miles = 6565.00;
                    cout << setw(2)  << "\tMiles Point      :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price     :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalT,"19:00");//copy to string
                    strcpy(DepartureT,"22:00");//copy to string
                    break;

default://condition
              cout << setw(2)  <<"\n\tInvalid input had been entered\nTry again\n\n\n" << endl;
                    return selectFlightL();
            }
        }
};
////////////////////////////////////////////////////////////////////////////////
class interBooking //class  for inter FLIGHT
{
protected://protected members
    int iref; // future reference for flight cancellation
    char flightInter[10],ArrivalTIN[7],DepartureTIN[7];
    long int dateIN; //date of journey
    int selectIN; //switch case for airlines
    int arrIN; // ARRIVAL
    int depIN; //DEPARTURE
    friend class payment;
      friend class seats;
  //  float TicketPriceI;
public://public member functions
    void i_ref()
    {
        count++; // increment variable
        iref=count;
    }
////////////////////////////////////////////////////////////////////////////////
  int travelDetailI() // function declaration and definition for domestic journey
  {
       time();
        cout << setw(2) << "\n\tPlease, enter the date in the following format ! (DDMMYYYY). " << "Please enter a valid date." <<  endl;
        cout << setw(2)  << "\tDate :: ";
        cin >> dateIN;
        cout << endl;

        cout << setw(2)  << "\t1.KUALA LUMPUR [ KL ] \t2.PENANG [ PG ] \t3.LANGKAWI [ LG ]" << endl << endl;
        cout << setw(2)  << "\tPLEASE ENTER YOUR DEPARTURE DESTINATION :: " << endl;
        cout << setw(2)  << "\tDestination :: ";
        cin >> depIN;
        cout << endl;

        cout << setw(2)  << "\t4.MILAN [ MP ] \t5.MANCHESTER [ MN ] \t6.IBIZA [ IZ ]" << endl << endl;
        cout << setw(2)  << "\tPLEASE ENTER YOUR ARRIVAL DESTINATION   :: " << endl;
        cout << setw(2)  << "\tArrival     :: ";
        cin >> arrIN;
        cout << endl;
        system("CLS");
        // MANY TO MANY //MIX MATCH //FOLLOWED SET METHOD(PROBABILITY) T0 DISPLAY LOCAL COUNTRIES.FOR better understanding this is how it works, INTERNATIONAL={(1,4),(1,5),(1,6),(2,4),(2,5),(2,6),(3,4),(3,5),(3,6)}
        // The repeating digits such (1,1) & etc will be removed to avoid the same ARRIVAL and DEPARTURE inputs.
        if(depIN==1 && arrIN==4)
        //KL - MP [(1,4)]  ,MP - KL [(4,1)]
        {
        cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
        cout << setw(2)  << "\t\t\tAVAILABILITY OF INTERNATIONAL FLIGHTS"   << endl;
        cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
        cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
        cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
        cout << setw(2)  << "1) EMIRATES\tED100\t\tKL - MP \t06.00 -> 12.00\t\tRM9000\n";
        cout << setw(2)  << "2) QATAR   \tQT300\t\tKL - MP \t14.00 -> 20.00\t\tRM8000\n";
        cout << setw(2)  << "3) EITHAD  \tER500\t\tKL - MP \t22.00 -> 05.00\t\tRM6000\n";
        cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==1 && arrIN==5)
        //KL - MN [(1,5)] , MN -KL [(5,1)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) EMIRATES\tED110\t\tKL - MN \t06.00 -> 12.00\t\tRM9000\n";
          cout << setw(2)  << "2) QATAR   \tQT310\t\tKL - MN \t14.00 -> 20.00\t\tRM8000\n";
          cout << setw(2)  << "3) EITHAD  \tER510\t\tKL - MN \t22.00 -> 05.00\t\tRM6000\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==1 && arrIN==6)
        //KL - IZ [(1,6)] , LG - KL [(6,1)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) EMIRATES\tED120\t\tKL - IZ \t06.00 -> 12.00\t\tRM9000\n";
          cout << setw(2)  << "2) QATAR   \tQT320\t\tKL - IZ \t14.00 -> 20.00\t\tRM8000\n";
          cout << setw(2)  << "3) EITHAD  \tER520\t\tKL - IZ \t22.00 -> 05.00\t\tRM6000\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==2 && arrIN==4)
        //LG - MP [(2,4)] , MP - LG [(4,2)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) EMIRATES\tED130\t\tPG - MP \t06.00 -> 12.00\t\tRM9000\n";
          cout << setw(2)  << "2) QATAR   \tQT330\t\tPG - MP \t14.00 -> 20.00\t\tRM8000\n";
          cout << setw(2)  << "3) EITHAD  \tER530\t\tPG - MP \t22.00 -> 05.00\t\tRM6000\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==2 && arrIN==5)
        //LG - MN [(2,5)] , MN - LG [(5,2)]
        {
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
          cout << setw(2)  << "1) EMIRATES\tED140\t\tPG - MN \t06.00 -> 12.00\t\tRM9000\n";
          cout << setw(2)  << "2) QATAR   \tQT340\t\tPG - MN \t14.00 -> 20.00\t\tRM8000\n";
          cout << setw(2)  << "3) EITHAD  \tER540\t\tPG - MN \t22.00 -> 05.00\t\tRM6000\n";
          cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==2 && arrIN==6)
        //LG - IZ [(2,6)] , IZ - LG [(6,2)]
         {
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "1) EMIRATES\tED150\t\tPG - IZ \t06.00 -> 12.00\t\tRM9000\n";
           cout << setw(2)  << "2) QATAR   \tQT350\t\tPG - IZ \t14.00 -> 20.00\t\tRM8000\n";
           cout << setw(2)  << "3) EITHAD  \tER550\t\tPG - IZ \t22.00 -> 05.00\t\tRM6000\n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==3 && arrIN==4)
        //PG - MP [(3,4)] , PG - MP [(4,3)]
         {
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";

          cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "1) EMIRATES\tED160\t\tLG - MP \t06.00 -> 12.00\t\tRM9000\n";
           cout << setw(2)  << "2) QATAR   \tQT360\t\tLG - MP \t14.00 -> 20.00\t\tRM8000\n";
           cout << setw(2)  << "3) EITHAD  \tER560\t\tLG - MP \t22.00 -> 05.00\t\tRM6000\n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==3 && arrIN==5)
        //PG - MN [(3,5)] , PG - MN [(5,3)]
         {
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "1) EMIRATES\tED170\t\tLG - MN \t06.00 -> 12.00\t\tRM9000\n";
           cout << setw(2)  << "2) QATAR   \tQT370\t\tLG - MN \t14.00 -> 20.00\t\tRM8000\n";
           cout << setw(2)  << "3) EITHAD  \tER570\t\tLG - MN \t22.00 -> 05.00\t\tRM6000\n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------";
        }
        else if(depIN==3 && arrIN==6)
        //PG - IZ [(3,6)] , PG - IZ [(6,3)]
         {
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "\t\t\tAVAILABILITY OF LOCAL FLIGHTS" << endl;
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "   Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------\n";
           cout << setw(2)  << "1) EMIRATES\tED180\t\tLG - IZ \t06.00 -> 12.00\t\tRM9000\n";
           cout << setw(2)  << "2) QATAR   \tQT380\t\tLG - IZ \t14.00 -> 20.00\t\tRM8000\n";
           cout << setw(2)  << "3) EITHAD  \tER580\t\tLG - IZ \t22.00 -> 05.00\t\tRM6000\n";
           cout << setw(2)  << "-----------------------------------------------------------------------------------";
         }
        else if(arrIN==depIN)// For (1,1),(2,2),(3,3),(4,4)
        {
            cout << setw(2)  << "\nARRIVAL and DEPARTURE locations cannot be the same.\n Please, try again with a new input\n\n\n" << endl;
            return  travelDetailI(); //returns to the locations of local flight
        }
        else if (depIN<4)
        { system("CLS");
            cout << setw(2)  <<"\nInvalid input had been entered\nTry again\n\n\n" << endl;

            return  travelDetailI();
        }
        else if (arrIN>3 && arrIN<6)
        { system("CLS");
            cout << setw(2)  <<"\nInvalid input had been entered\nTry again\n\n\n" << endl;
            return  travelDetailI();
        }
        else
        { system("CLS");
            cout << setw(2)  <<"\nInvalid input had been entered\nTry again\n\n\n" << endl;
            return  travelDetailI();
        }
  }
////////////////////////////////////////////////////////////////////////////////
int  selectFlightI() //function declaration and definition for selecting flight
  {   cout << setw(2)  << "\n\tEnter your choice :: ";
      cin >> selectIN;
      system("CLS");
      switch(selectIN) // switch case selection
              {
              case 1://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type       :: ";
                    cout << setw(2)  << "EMIRATES"<<endl;
                    strcpy(flightInter,"EITHAD");//copy to string
                    cout << setw(2)  << "\tDeparture Time     :: 06:00"<<endl;
                    cout << setw(2)  << "\tArrival Time       :: 12:00"<<endl;
                    Price=9000;
                    miles = 9880.00;
                    cout << setw(2)  << "\tMiles Point        :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price       :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalTIN,"06:00"); //copy to string
                    strcpy(DepartureTIN,"12:00");// copy to string
                    break;

              case 2://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type       :: ";
                    cout << setw(2)  << "QATAR"<<endl;
                    strcpy(flightInter,"QATAR");//copy to string
                    cout << setw(2)  << "\tDeparture Time     :: 14:00"<<endl;
                    cout << setw(2)  << "\tArrival Time       :: 17:05"<<endl;
                    Price=8000;
                    miles = 9870.00;
                    cout << setw(2)  << "\tMiles Point        :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price       :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalTIN,"14:00");//copy to string
                    strcpy(DepartureTIN,"20.00");//copy to string
                    break;

              case 3://condition
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\t :: FLIGHT SELECTED ::"<<endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout << setw(2)  << "\n\tAirline Type        :: ";
                    cout << setw(2)  << "EITHAD" << endl;
                    strcpy(flightInter,"EMIRATES");//copy to string
                    cout << setw(2)  << "\tDeparture Time      :: 19:00" << endl;
                    cout << setw(2)  << "\tArrival Time        :: 22:05" << endl;
                    Price=6000;
                    miles = 8787.00;
                    cout << setw(2)  << "\tMiles Point         :: "<<miles*points <<" pts"<<endl;
                    cout << setw(2)  << "\tTicket Price        :: " <<"RM "<< Price << endl;
                    cout << setw(2)  << "<><><><><><><><><><><><><><><><><><><><>"<<endl;
                    strcpy(ArrivalTIN,"22:00");//copy to string
                    strcpy(DepartureTIN,"05:00");//copy to string
                    break;

              default://condition
              cout << setw(2)  <<"\nInvalid input had been entered\nPlease,Try again\n\n\n" << endl;
                    return selectFlightI();
                  }
   }
};
////////////////////////////////////////////////////////////////////////////////
class seats
{
  public :
 // user input seat
  friend class passenger;
    void create ()
    {
      ofstream seats ("seats.txt");
      if (seats.is_open())
      {
        for (int i = 0; i < Rows; i++)
        {    //int z= i+1;
            //arrayS[i][0]=z+'0';
          arrayS[i][0]=i+1+'0';
          for (int j = 1; j < col; j++)
          {
            //to get the seats to be A B C D
            arrayS[i][j]='A'+j-1;
          }
        }
        seats.close();
        inTxtFile();
      }
      else cout << setw(2)  << "\tUnable to open file";
    }
  void inTxtFile()
  {
    ofstream seats ("seats.txt");
    if (seats.is_open())
    {
      for (int i=0; i<Rows; i++)
      {
        for(int j=0; j<col; j++)
        {
          seats << arrayS[i][j]<<" ";
        }
        seats <<endl;
      }
      seats.close();
    }
  }
  void print ()
  {
    ifstream seats;
    seats.open ("seats.txt");
     if (!seats)
       cout << setw(2)  << "\tError opening data file.\n";
       else
       {
        cout << setw(2)  <<"\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
      cout << setw(2)  <<"\t\t\t  SEAT SELECTION\n";
      cout << setw(2)  <<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
         for (int i = 0; i < Rows; i++)
         {
           for (int j = 0; j < col; j++)
           {
             seats >> arrayS[i][j] ;
             cout <<"\t";
             cout << arrayS[i][j] << " ";
             cout <<"\t";
         }
         cout << endl;
         cout <<"\n";
       }
      seats.close();
    }
  }
  string UserInput ()
  {
    while (true)
    {
      string U_input;
      cout <<endl;
      cout << setw(2)  << "\t ENTER THE DESIRED SEAT NUMBER.EXAMPLE : 1A OR 1B"<<endl;
      cout << setw(2)  << "\t Economy Class - RM 80     Business Class - RM 120 "<<endl;
      cout << setw(2)  << "\t For Business Class, choose 'D' from row (1-7)"<<endl;
      cout << setw(2)  << "\t Choice  ::  ";
      cin >> U_input;

    if(U_input[0]>'7' || U_input[0]<'1' || U_input[1]>'D' || U_input[1]<'A')
        {
        cout<<"\t\nInvalid Seat Number\n";
        system("CLS");
        print();
        return UserInput();
        }
        else if((U_input[0]<'7') && (U_input[1]=='D'))
        {
            cout << setw(2)  << "\tBusiness Class Seats has been selected.\n";
            seatChoosen=busSeat;
            cout << setw(2)  << "\tSeat Price = RM " << busSeat << endl;
        }
        else{
            cout << setw(2)  << "\tEconomy Class Seats has been selected.\n";
            seatChoosen=ecoSeat;
            cout << setw(2)  << "\tSeat Price = RM " << ecoSeat << endl;
        }
     if (MarkSeat(U_input));
     if (fullHouse(U_input));
     //enter the part to check if the thing we entered is full or  not
    return U_input;
  }
  } //gets user input
  int MarkSeat (string s)
  {
    int Row=-1,col=-1;
    //find the row no of the user seat
    for(int i=0;i<7;i++)
    {
      if(arrayS[i][0]==s[0])
      Row=i;
    }
     //find the column no of user seat
    for(int j=0;j<5;j++)
    {
      if(arrayS[Row][j]==s[1])
      col=j;
    }
    //check whether seat is already occupied or not.
    if(col==-1)
    {
    cout << setw(2) <<"\t This seat is already occupied\n";
    sleep(1);
    system("CLS");
    print();
    UserInput();
    return 1;
    }
    else{
    sleep(1);
    cout << setw(2) << "\tSeat is being updated ...."<<endl;
    system("CLS");
    arrayS[Row][col]='x';
    inTxtFile ();
    print();
    sleep(2);
    cout << setw(2) << "\tSeat has been updated ...."<<endl;
    return 1;
   }
  }//marks seat
 int fullHouse(string)
 {
   int count=0;
   for(int i=0;i<7;i++){
     for(int j=1;j<5;j++)
     if(arrayS[i][j]=='X')
       count++;
   }
   if(count==28)
   {
     return 1;
   }
   return 0;
 };
void checkfile()
{
  ifstream seats ;
  seats.open ("seats.txt");
  if (seats.tellg() != -1)
  {
    cout << setw(2)  << "\tFile not empty " <<seats.tellg() <<" "<<endl;
    print ();
    string s = UserInput ();
    fullHouse(s );
  }
  else
  {
    cout << setw(2)  << "\tFile is empty "<<seats.tellg() <<" "<<endl;
    create();
    print ();
    string s = UserInput ();
  }
  seats.close();
}
};
void run()
{
  seats kerusi;
   for (int i = 0; i<Rows; i++)
   {
    arrayS[i] = new char[col];
   }
  kerusi.checkfile();
    for (int i = 0; i < Rows; i++)
      delete[] arrayS[i];
      delete[] arrayS;
   seats();
}
////////////////////////////////////////////////////////////////////////////////
class Baggage // BAGGAGE
{
public:
  int weight;
friend class payment; // for calculTION purpose
void weightage()
{
  system("cls");
  time();
  system("color 20");
  cout << setw(2)  <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout << setw(2)  <<"\tBAGGAGE SELECTION FOR DEPARTURE FLIGHT " << endl;
  cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout << setw(2)  <<"\tYour fair includes 7kg of cabin baggage allowance."<<endl;
  cout << setw(2)  <<"\tExtra charges apply to oversized or overeight cabin baggage"<< endl;
  cout << setw(2)  <<"\tYou may prebook your checked baggage now to enjoy best rates!"<<endl;

  cout <<endl<<endl;

  sleep(0.5);
  cout << setw(2)  << "\t|+++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
  cout << setw(2)  << "\t|\tBaggage Type \t\tPrice             |"<<endl;
  cout << setw(2)  << "\t|+++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
  cout << setw(2)  << "\t| No checked Baggage (7 KG) \t -                |" <<endl;
  cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
  cout << setw(2)  << "\t| 20 Kilograms (KG)  \t      RM 25               |" <<endl;
  cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
  cout << setw(2)  << "\t| 30 Kilograms (KG)  \t      RM 45               |" <<endl;
  cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
  cout << setw(2)  << "\t| 40 Kilograms (KG)  \t      RM 65               |" <<endl;
  cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
  cout << setw(2)  << "\t| 50 Kilograms (KG)  \t      RM 85               |" <<endl;
  cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
  cout << setw(2)  << "\tThe maximum baggage type is 50 KG.Please your choice. " <<endl;
  cout << setw(2)  << "\tCHOICE OF BAGGAGE (7,20,30,40,50) :: ";
  cin >> choiceD;

  switch(choiceD)
  {
    case 7 : cout<<"\a";
             sleep(0.1);
             break;
    case 20 : cout<<"\a";
              sleep(0.1);
              break;
    case 30 : cout<<"\a";
              sleep(0.1);
              break;
    case 40 : cout<<"\a";
              sleep(0.1);
              break;
    case 50 : cout<<"\a";
              sleep(0.1);
              break;
   default :
            cout<<"\a";
            cout << setw(2)  << "Invalid Input . Please try again !" << endl;
            return weightage();
  }
sleep(0.5);
system("CLS");
system("color 20");
cout << setw(2)  <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout << setw(2)  <<"\tBAGGAGE SELECTION FOR ARRIVAL FLIGHT " << endl;
cout << setw(2)  <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout << setw(2) <<"\tYour fair includes 7kg of cabin baggage allowance."<<endl;
cout << setw(2)  <<"\tExtra charges apply to oversized or overeight cabin baggage"<< endl;
cout << setw(2)  <<"\tYou may prebook your checked baggage now to enjoy best rates!"<<endl;

cout <<endl<<endl;
sleep(0.5);
cout << setw(2)  << "\t|+++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
cout << setw(2)  << "\t|\tBaggage Type \t\tPrice             |"<<endl;
cout << setw(2)  << "\t|+++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
cout << setw(2)  << "\t| No checked Baggage (7 KG) \t -                |" <<endl;
cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
cout << setw(2)  << "\t| 20 Kilograms (KG)  \t      RM 25               |" <<endl;
cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
cout << setw(2)  << "\t| 30 Kilograms (KG)  \t      RM 45               |" <<endl;
cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
cout << setw(2)  << "\t| 40 Kilograms (KG)  \t      RM 65               |" <<endl;
cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
cout << setw(2)  << "\t| 50 Kilograms (KG)  \t      RM 85               |" <<endl;
cout << setw(2)  << "\t|-------------------------------------------------|" << endl;
cout << setw(2)  << "\tThe maximum baggage type is 50 KG " <<endl;
cout << setw(2)  << "\tCHOICE OF BAGGAGE (7,20,30,40,50) :: ";
cin >> choiceA;
      switch(choiceA)
      {
        case 7 : cout<<"\a";
                 sleep(0.1);
                 break;
        case 20 : cout<<"\a";
                  sleep(0.1);
                  break;
        case 30 : cout<<"\a";
                  sleep(0.1);
                  break;
        case 40 : cout<<"\a";
                  sleep(0.1);
                  break;
        case 50 : cout<<"\a";
                  sleep(0.1);
                  break;
       default :
                cout<<"\a";
                cout << setw(2)  << "Invalid Input . Please try again !" << endl;
                return weightage();
      }

      sleep (0.5);
      cout << endl << endl;
      cout << setw(2)  << "\tYour Baggage selection for both Arrival and Departure has been Successful updated" << "\n";
      sleep (1);
    //  system ("pause");
}
};
////////////////////////////////////////////////////////////////////////////////
class passenger:public localBooking,public interBooking, public Baggage,public seats
{
protected:
  int num;
  char ch;
  char firstname[10000];
  char lastname[10000];
  int age;
  char address[10000];
  char nationality[10000];
  int gender;
  char city[10000];
  char country[10000];
  int phone;

public:
  void passDetails(int x)
  {   if(x==1)//if else for domestic and international booking selection
      { travelDetailL();//function call
        selectFlightL();//function call
      }
        else
        {  travelDetailI();//function call1353
           selectFlightI();//function call
        }
  cout<<setw(40)<<"\n\n   :: Please enter the required information for passenger number ::"<<endl;

  cout << setw(2) <<"\tPassenger First Name          :  ";
  cin.ignore();
  cin.getline(firstname,10000);
  cout << endl;

  cout << setw(2) <<"\tPassenger Last Name           :  ";
  //cin.ignore();
  cin.getline(lastname,10000);
  cout<<endl;

  cout << setw(2) <<"\tPassenger Age                 :  ";
  //cin.ignore();
  cin>>age;
  cout<<endl;

  cout << setw(2) <<"\tPassenger Address             :  ";
  cin.ignore();
  cin.getline(address,10000);
//  cin >> address;
  cout<<endl;

  cout << setw(2) <<"\tPassenger Nationality         :  ";
  cin.ignore();
  cin.getline(nationality,10000);
  //cin >> nationality;
  cout<<endl;

  cout << setw(2) <<"\tPassenger City                :  ";
  cin.ignore();
  cin.getline(city,10000);
  //cin >> city;
  cout<<endl;

  cout << setw(2) <<"\tPassenger Country             :  ";
  cin.ignore();
  cin.getline(country,10000);
  //cin >> country;
  cout<<endl;

  cout << setw(2) <<"\tPassenger Contact (11 Digits) :  ";
  //cin.ignore();
  cin>>phone;
  cout<<endl;

}
////////////////////////////////////////////////////////////////////////////////

int genderChoice() //gender option for the user when inserting personal info
{
    cout << setw(2)  << "\n\tGender:\n\tMale-press   : 1              :: \n\tFemale-press : 2              :: ";
    cin >> gender;
    if(gender>2)//condition
    {
        cout << setw(2)  << "\n\n\tWrong input entered.\n\tTry again\n\n" << endl;
        return genderChoice();//function call
    }
}
////////////////////////////////////////////////////////////////////////////////

int getlref() // local reference no. ( member card )
{
  return lref;
}

////////////////////////////////////////////////////////////////////////////////

int getiref() //international reference no.
{
  return iref;
}
////////////////////////////////////////////////////////////////////////////////

void extraDetailsLocal() //DETAILS BASED ON LOCAL BOOKING
{
  cout <<"\n";
  time();
  cout << endl;
  cout <<"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
  cout <<"\tTicketNo*       :" << lref << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tFlight          :" << flightLocal << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tPassenger Name  :" << firstname << " " << lastname << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tDeparture Date  :" << date << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tDeparture Time  :" << DepartureT << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tArrival Time    :" << ArrivalT << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tBaggage Depart  :" << choiceD  << " KG" << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tBaggage Arrive  :" << choiceA  << " KG" << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tSeat number     :" << U_input << endl;
  cout <<"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
  cout<<endl << endl;
  cout <<"PLEASE BE AWARE, THAT THE * TICKET NO * CAN BE USED TO CANCEL"<<endl;
  cout <<"THE TICKET, ONE MONTH BEFORE THE ORGINAL DEPARTURE DATE."<<endl;
  cout <<"TO CANCEL THE TICKET, PLEASE GO THE THE MAIN MENU AND CLICK "<<endl;
  cout <<"*CANCEL TICKET* . THANK YOU " << endl;
}
////////////////////////////////////////////////////////////////////////////////

void extraDetailsInter() //DETAILS BASED ON INTERNATIONAL BOOKING
{
  time();
  cout << endl;
  cout <<"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
  cout <<"\tTicketNo*       :" << iref << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tFlight          :" << flightInter << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tPassenger Name  :" << firstname << " " << lastname << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tDeparture Date  :" << dateIN << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tDeparture Time  :" << DepartureTIN << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tArrival Time    :" << ArrivalTIN << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tBaggage Depart  :" << choiceD  << " KG" << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tBaggage Arrive  :" << choiceA  << " KG" << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tMiles Points    :" << miles*points << "pts" << endl;
  cout <<"--------------------------------------------------------"<<endl;
  cout <<"\tSeat number     :" << U_input << endl;
  cout <<"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
  cout<<endl << endl;
  cout <<"PLEASE BE AWARE, THAT THE * TICKET NO * CAN BE USED TO CANCEL"<<endl;
  cout <<"THE TICKET, ONE MONTH BEFORE THE ORGINAL DEPARTURE DATE."<<endl;
  cout <<"TO CANCEL THE TICKET, PLEASE GO THE THE MAIN MENU AND CLICK "<<endl;
  cout <<"*CANCEL TICKET* . THANK YOU " << endl;
}

};
////////////////////////////////////////////////////////////////////////////////

class payment//class for payment
{
protected://protected members
    int choice1; // choice based on the payment method
    int bank; // type of bank choosen
    int card; // card number
    int date; // expiry date
    int cvv; // the code behind the card
    char userId[100]; // user id is for the online banking
    char password[100];
public://public members functions
    void payDetail()//function declaration and definition for payment method
    {
      system("CLS");
        time();
        cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
        cout << "\t\t\t PAYMENT METHOD " << endl;
        cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
        cout << "\n\n\n\tHow would you like to pay ?\n";
        cout << "\n\t\t1. Debit Card \n\t\t2. Credit Card \n\t\t3. Online Banking";
        cout << "\n\n\tEnter your choice        : ";
        cin >> choice1;
        switch(choice1)//switch case
        {
        case 1://condition
        system("CLS");
          time();
          cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
          cout << "\t\t\t PAYMENT METHOD " << endl;
          cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
            cout << "\n\t\tPlease, enter the following payment details";
            cout << "\n\t\tEnter card no.       : ";
            cin >> card;

            cout << "\n\t\tEnter expiry date    : ";
            cin >> date;

            cout << "\n\t\tEnter CVV no.        : ";
            cin >> cvv;

                  if (choiceA == 7) {luggageP = 0;}

                  if (choiceA == 20){luggageP = 25;}

                  if(choiceA == 30) {luggageP = 45;}

                  if(choiceA == 40) {luggageP = 65;}

                  if(choiceA == 50) {luggageP = 85;}

                  if (choiceD == 7) {luggagePR = 0;}

                  if (choiceD == 20){luggagePR = 25;}

                  if(choiceD == 30) {luggagePR = 45;}

                  if(choiceD == 40) {luggagePR = 65;}

                  if(choiceD == 50) {luggagePR = 85;}

                  tprice = luggageP + luggagePR;
                  payments=tprice+Price+30+seatChoosen;

                  cout << "\n\t\tPayment (Inc. Tax)   : " << "RM " << payments;
                  cout <<endl;
                  cout <<"\n\t\tPayment will be deducted from your account in awhile.\n" <<endl;
                  sleep(2.0);
                  MessageBox(NULL, "TRANSACTION SUCCESSFUL.", " PAYMENT ", MB_OK);
                  Beep(523.2511,500);  // 523.2511 hertz (C5) for 500 milliseconds
                  Beep(587.3295,500);
                  Beep(659.2551,500);
                  Beep(698.4565,500);
                  Beep(783.9909,500);
                  sleep(2);
                  break;
        case 2://condition
        system("CLS");
          time();
          cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
          cout << "\t\t\t PAYMENT METHOD " << endl;
          cout << "\t^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v"<<endl;
            cout << "\n\t\tPlease, enter the following payment details";
            cout << "\n\t\tEnter card no.       : ";
            cin >> card;

            cout << "\n\t\tEnter expiry date    : ";
            cin >> date;

            cout << "\n\t\tEnter password       : ";
            cin >> password;
                  if (choiceA == 7) {luggageP = 0;}

                  if (choiceA == 20){luggageP = 25;}

                  if(choiceA == 30) {luggageP = 45;}

                  if(choiceA == 40) {luggageP = 65;}

                  if(choiceA == 50) {luggageP = 85;}

                  if (choiceD == 7) {luggagePR = 0;}

                  if (choiceD == 20){luggagePR = 25;}

                  if(choiceD == 30) {luggagePR = 45;}

                  if(choiceD == 40) {luggagePR = 65;}

                  if(choiceD == 50) {luggagePR = 85;}

                    tprice = luggageP + luggagePR;
                    payments=tprice+Price+30+seatChoosen;

                    cout << "\n\t\tPayment (Inc. Tax)    : " << "RM " << payments;
                    cout <<endl;
                    cout <<"\n\t\tPayment will be deducted from your account in awhile.\n" <<endl;
                  sleep(2.0);
                  MessageBox(NULL, "TRANSACTION SUCCESSFUL.", " PAYMENT ", MB_OK);
                  Beep(523.2511,500);  // 523.2511 hertz (C5) for 500 milliseconds
                  Beep(587.3295,500);
                  Beep(659.2551,500);
                  Beep(698.4565,500);
                  Beep(783.9909,500);
                  sleep(2);
                  break;
        case 3://condition
        system("CLS");
            cout << "\n\n"<<endl;
            cout <<"\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout <<"\t\t\tBanks Available: "<<endl;
            cout <<"\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
            cout <<"\t\t\t1.MayBank"<<endl;
            cout <<"\t\t\t2.HSBC Bank"<<endl;
            cout <<"\t\t\t3.STANDARD CHARTERED Bank "<<endl;
            cout <<"\t\t\t4.CIMB Clicks "<<endl;
            cout <<"\t\t\t5.HONG LEONG Bank" << endl;
            cout <<"\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";

            cout << endl<<endl;
            cout << "\n\t\tPlease, enter the following payment details\n";
            cout << "\n\t\tSelect your bank(1-5)       : ";
            cin >> bank;

            cout << "\n\t\tPlease, enter your user ID : ";
            cin.ignore();
            cin.getline(userId,100);
          //  cin >> userId;

            cout << "\n\t\tPlease enter your password : ";
            cin.ignore();
            cin.getline(password,100);
          //  cin >> password;
                if (choiceA == 7) {luggageP = 0;}

                if (choiceA == 20){luggageP = 25;}

                if(choiceA == 30) {luggageP = 45;}

                if(choiceA == 40) {luggageP = 65;}

                if(choiceA == 50) {luggageP = 85;}

                if (choiceD == 7) {luggagePR = 0;}

                if (choiceD == 20){luggagePR = 25;}

                if(choiceD == 30) {luggagePR = 45;}

                if(choiceD == 40) {luggagePR = 65;}

                if(choiceD == 50) {luggagePR = 85;}

              tprice = luggageP + luggagePR;
              payments=tprice+Price+30+seatChoosen;

              cout << "\n\t\tPayment (Inc. Tax)   : " << "RM " << payments;
              cout <<endl;
              cout <<"\n\t\tPayment will be deducted from your account in awhile.\n" <<endl;
              sleep(2.0);
            MessageBox(NULL, "TRANSACTION SUCCESSFUL.", " PAYMENT ", MB_OK);
            Beep(523.2511,500);  // 523.2511 hertz (C5) for 500 milliseconds
            Beep(587.3295,500);
            Beep(659.2551,500);
            Beep(698.4565,500);
            Beep(783.9909,500);
            sleep(2);
            break;
        default://condition
            cout << "\n\tWrong input entered.\nPlease,Try again\n\n";
            system("CLS");
            return payDetail();
        }
    }

};
////////////////////////////////////////////////////////////////////////////////

void  createfile(passenger p)//opens local file
{  ofstream fin("LocalFlight.txt",ios::binary|ios::app);
   fin.write((char*)&p,sizeof(p));//writing to file
   fin.close();//closing file
}
////////////////////////////////////////////////////////////////////////////////

void createFilei(passenger p)//opening a file for international booking
{  ofstream fin("internationalFlight.txt",ios::binary|ios::app);
   fin.write((char*)&p,sizeof(p));//writing to file
   fin.close();//closing file
}
////////////////////////////////////////////////////////////////////////////////
void cancelticket(int x)//function to cancel ticket
{  passenger p;
    int f=0;
   ifstream fout("LocalFlight.txt",ios::binary|ios::app);//for reading file
   ofstream fin("LocalFlight1.txt",ios::binary|ios::app);//for writing to a new file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getlref()!=x)//checking pnr
      fin.write((char *)&p,sizeof(p));//writing to file
      else
     {
         p.extraDetailsLocal();//display details
         cout<<"\n\t\tYour Above ticket is being canceled:\n" << "\t\tAmount refunded: RM 200\n";
         f++;//incrementing f if pnr found
     }
     fout.read((char *)&p,sizeof(p));//reading another record from file
   }
   if(f==0)//if f==0,pnr not found
    cout<<"\t\tTicket not found\n";
   fout.close();//closing file
   fin.close();//closing file
   remove("LocalFlight.txt");//deleting old file
   rename("LocalFlight1.txt","LocalFlight.txt");//renaming new file

}
////////////////////////////////////////////////////////////////////////////////

void checkticket(int x)//function to check or ticket
{  passenger p;
   int f=0;
   ifstream fout("LocalFlight.txt",ios::binary);//opening file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getlref()==x)//checking ref
     {p.extraDetailsLocal();//display details
      //cout<<"\nYour ticket"<<endl;
      f++;//incrementing f if tickrt found
      break;
     }
     fout.read((char *)&p,sizeof(p));//reading another record from the same file

   }
   fout.close();//closing file
   if(f==0)//if f==0, pnr not found
   cout<<"\t\tTicket not found"<<endl;

}
////////////////////////////////////////////////////////////////////////////////
void createfilei(passenger p)//opening a file for international booking
{  ofstream fin("internationalFlight.txt",ios::binary|ios::app);
   fin.write((char*)&p,sizeof(p));//writing to file
   fin.close();//closing file
}
////////////////////////////////////////////////////////////////////////////////
void cancelticketi(int x)//function to cancel ticket (x-local or international)
{  passenger p;
   int f=0;
   ifstream fout("internationalFlight.txt",ios::binary|ios::app);//opening file
   ofstream fin("internationalFlight1.txt",ios::binary|ios::app);//writing to a new file
   fout.read((char *)&p,sizeof(p));//reading old file
   while(fout)
   {
     if(p.getiref()!=x)//checking pnr
      fin.write((char *)&p,sizeof(p));//writing to new file;
      else
     {
         p.extraDetailsInter();//display details
         cout<<"\t\tYour Above ticket is being deleted:\n"<<"\t\tAmount refunded: RM 200\n";
         f++;//incre  menting f if REF found
     }
     fout.read((char *)&p,sizeof(p));//reading another record from old file
   }
   if(f==0)//if f==0,pnr not found
    cout<<"\n\t\tTicket not found\n";
   fout.close();//closing file
   fin.close();//closing file
   remove("internationalFlight.txt");//deleting old file
   rename("internationalFlight1.txt","internationalFlight.txt");//renaming new file

}
////////////////////////////////////////////////////////////////////////////////
void checkticketi(int x)//function to check ticket
{  passenger p;
   int f=0;
   ifstream fout("internationalFlight.txt",ios::binary);//opening file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getiref()==x)//checking pnr
     {p.extraDetailsInter();//display details
    //  cout<<"\nYour ticket"<<endl;
      f++;//incrementing f if REF found
      break;
     }
     fout.read((char *)&p,sizeof(p));//reading another record from the file

   }
   fout.close();//closing file
   if(f==0)//if f==0, REF not found
   cout<<"\t\tTicket not found"<<endl;

}
////////////////////////////////////////////////////////////////////////////////
void intro()
{
  system("color 80");
  cout << "\n\n\t\t\t\t\t\t\t";
  time();
cout <<"\n\n "<< endl;
cout << setw(2) <<"\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;

cout << setw(2) <<"\t\t      $$$$$$$$$$$$$$$$$$$$$$$$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$$$$$$$$$$$$$$$$$$$$$$"<< endl;

cout << setw(2) <<"\t\t              $$$$$$$$$$$$$$$$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$$$$$$$$$$$$$$$"<< endl;

cout << setw(2) <<"\t\t                    $$$$$$$$$$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$$$$$$$$$"<< endl;

cout << setw(2) <<"\t\t                         $$$$$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$$$$"<< endl;

cout << setw(2) <<"\t\t                            $$";
cout << setw(2) <<" ";
cout << setw(2) <<  "$$"<< endl;


cout << "\n\n";
cout << "\t\t\t\t  PR AIRLINE MANAGEMENT SYSTEM " << endl;
}
////////////////////////////////////////////////////////////////////////////////
void local()
{
  system("color 1f");
  cout << endl;
  time();
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
  cout << " Airline \tFlight.No\tDestination\tTime\t\t\tPrice  \n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
  cout << " AIR ASIA\tAK100\t\tKL - PG \t08.00 -> 11.00\t\tRM80\n";
  cout << " AIR ASIA\tAK200\t\tPG - KL \t08.00 -> 11.00\t\tRM80\n";
  cout << " MALINDO \tCA300\t\tKL - PG \t14.00 -> 17.00\t\tRM90\n";
  cout << " MALINDO \tCA400\t\tPG - KL \t14.00 -> 17.00\t\tRM90\n";
  cout << " MAS     \tMH500\t\tKL - PG \t19.00 -> 22.00\t\tRM70\n";
  cout << " MAS     \tMH600\t\tPG - KL \t19.00 -> 22.00\t\tRM70\n";

  cout << " AIR ASIA\tAK110\t\tKL - KT \t08.00 -> 11.00\t\tRM50\n";
  cout << " AIR ASIA\tAK210\t\tKT - KL \t08.00 -> 11.00\t\tRM50\n";
  cout << " MALINDO \tCA310\t\tKL - KT \t14.00 -> 17.00\t\tRM60\n";
  cout << " MALINDO \tCA410\t\tKT - KL \t14.00 -> 17.00\t\tRM60\n";
  cout << " MAS     \tMH510\t\tKL - LT \t19.00 -> 22.00\t\tRM90\n";
  cout << " MAS     \tMH610\t\tKT - KL \t19.00 -> 22.00\t\tRM90\n";

  cout << " AIR ASIA\tAK120\t\tKL - LG \t08.00 -> 11.00\t\tRM90\n";
  cout << " AIR ASIA\tAK220\t\tLG - KL \t08.00 -> 11.00\t\tRM90\n";
  cout << " MALINDO \tCA320\t\tKL - LG \t14.00 -> 17.00\t\tRM70\n";
  cout << " MALINDO \tCA420\t\tLG - KL \t14.00 -> 17.00\t\tRM70\n";
  cout << " MAS     \tMH520\t\tKL - LG \t19.00 -> 22.00\t\tRM80\n";
  cout << " MAS     \tMH620\t\tLG - KL \t19.00 -> 22.00\t\tRM80\n";

  cout << " AIR ASIA\tAK130\t\tPG - KT \t08.00 -> 11.00\t\tRM50\n";
  cout << " AIR ASIA\tAK230\t\tKT - PG \t08.00 -> 11.00\t\tRM50\n";
  cout << " MALINDO \tCA330\t\tPG - KT \t14.00 -> 17.00\t\tRM60\n";
  cout << " MALINDO \tCA430\t\tKT - PG \t14.00 -> 17.00\t\tRM60\n";
  cout << " MAS     \tMH530\t\tPG - KT \t19.00 -> 22.00\t\tRM90\n";
  cout << " MAS     \tMH630\t\tKT - PG \t19.00 -> 22.00\t\tRM90\n";

  cout << " AIR ASIA\tAK140\t\tPG - LG \t08.00 -> 11.00\t\tRM40\n";
  cout << " AIR ASIA\tAK240\t\tLG - PG \t08.00 -> 11.00\t\tRM40\n";
  cout << " MALINDO \tCA340\t\tPG - LG \t14.00 -> 17.00\t\tRM50\n";
  cout << " MALINDO \tCA440\t\tLG - PG \t14.00 -> 17.00\t\tRM50\n";
  cout << " MAS     \tMH540\t\tPG - LG \t19.00 -> 22.00\t\tRM70\n";
  cout << " MAS     \tMH640\t\tLG - PG \t19.00 -> 22.00\t\tRM70\n";


  cout << " AIR ASIA\tAK250\t\tKT - LG \t08.00 -> 11.00\t\tRM60\n";
  cout << " AIR ASIA\tAK250\t\tLG - KT \t08.00 -> 11.00\t\tRM60\n";
  cout << " MALINDO \tCA350\t\tKT - LG \t14.00 -> 17.00\t\tRM80\n";
  cout << " MALINDO \tCA350\t\tLG - KT \t14.00 -> 17.00\t\tRM80\n";
  cout << " MAS     \tCA550\t\tKT - LG \t19.00 -> 22.00\t\tRM55\n";
  cout << " MAS     \tCA650\t\tLG - KT \t19.00 -> 22.00\t\tRM55\n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
  //sleep(0.5);
}
////////////////////////////////////////////////////////////////////////////////
void abroad()
{
  system("color 1f");

   cout << endl;
   time();

  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
  cout << " Airline\tFlight.No\tDestination\t\tTime\t\tPrice  \n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
  cout << " EMIRATES\tED100\t\tKL - MP \t06.00 -> 12.00\t\tRM4800\n";
  cout << " EMIRATES\tED200\t\tMP - KL \t06.00 -> 12.00\t\tRM4800\n";
  cout << " QATAR   \tQT300\t\tKL - MP \t14.00 -> 20.00\t\tRM8000\n";
  cout << " QATAR   \tQT400\t\tMP - KL \t14.00 -> 20.00\t\tRM8000\n";
  cout << " EITHAD  \tER500\t\tKL - MP \t22.00 -> 05.00\t\tRM6000\n";
  cout << " EITHAD  \tER600\t\tMP - KL \t22.00 -> 05.00\t\tRM6000\n";

  cout << " EMIRATES\tED110\t\tKL - MN \t06.00 -> 12.00\t\tRM5660\n";
  cout << " EMIRATES\tED210\t\tMN - KL \t06.00 -> 12.00\t\tRM5660\n";
  cout << " QATAR   \tQT310\t\tKL - MN \t14.00 -> 20.00\t\tRM7000\n";
  cout << " QATAR   \tQT410\t\tMN - KL \t14.00 -> 20.00\t\tRM7000\n";
  cout << " EITHAD  \tER510\t\tKL - MN \t22.00 -> 05.00\t\tRM5300\n";
  cout << " EITHAD  \tER610\t\tMN - KL \t22.00 -> 05.00\t\tRM5300\n";

  cout << " EMIRATES\tED120\t\tKL - IZ \t06.00 -> 12.00\t\tRM8000\n";
  cout << " EMIRATES\tED220\t\tIZ - KL \t06.00 -> 12.00\t\tRM8000\n";
  cout << " QATAR   \tQT320\t\tKL - IZ \t14.00 -> 20.00\t\tRM7900\n";
  cout << " QATAR   \tQT420\t\tIZ - KL \t14.00 -> 20.00\t\tRM7900\n";
  cout << " EITHAD  \tER520\t\tKL - IZ \t22.00 -> 05.00\t\tRM6500\n";
  cout << " EITHAD  \tER620\t\tIZ - KL \t22.00 -> 05.00\t\tRM6500\n";

  cout << " EMIRATES\tED130\t\tLG - MP \t06.00 -> 12.00\t\tRM7000\n";
  cout << " EMIRATES\tED230\t\tMP - LG \t06.00 -> 12.00\t\tRM7000\n";
  cout << " QATAR   \tQT330\t\tLG - MP \t14.00 -> 20.00\t\tRM4500\n";
  cout << " QATAR   \tQT430\t\tMP - LG \t14.00 -> 20.00\t\tRM4500\n";
  cout << " EITHAD  \tER530\t\tLG - MP \t22.00 -> 05.00\t\tRM8000\n";
  cout << " EITHAD  \tER630\t\tMP - LG \t22.00 -> 05.00\t\tRM8000\n";

  cout << " EMIRATES\tED140\t\tLG - MN \t06.00 -> 12.00\t\tRM7800\n";
  cout << " EMIRATES\tED240\t\tMN - LG \t06.00 -> 12.00\t\tRM7800\n";
  cout << " QATAR   \tQT340\t\tLG - MN \t14.00 -> 20.00\t\tRM8000\n";
  cout << " QATAR   \tQT440\t\tMN - LG \t14.00 -> 20.00\t\tRM8000\n";
  cout << " EITHAD  \tER540\t\tLG - MN \t22.00 -> 05.00\t\tRM5400\n";
  cout << " EITHAD  \tER640\t\tMN - LG \t22.00 -> 05.00\t\tRM5400\n";

  cout << " EMIRATES\tED150\t\tLG - IZ \t06.00 -> 12.00\t\tRM9000\n";
  cout << " EMIRATES\tED250\t\tIZ - LG \t06.00 -> 12.00\t\tRM9000\n";
  cout << " QATAR   \tQT350\t\tLG - IZ \t14.00 -> 20.00\t\tRM8000\n";
  cout << " QATAR   \tQT450\t\tIZ - LG \t14.00 -> 20.00\t\tRM8000\n";
  cout << " EITHAD  \tER550\t\tLG - IZ \t22.00 -> 05.00\t\tRM8000\n";
  cout << " EITHAD  \tER650\t\tIZ - LG \t22.00 -> 05.00\t\tRM8000\n";

  cout << " EMIRATES\tED160\t\tPG - MP \t06.00 -> 12.00\t\tRM8500\n";
  cout << " EMIRATES\tED260\t\tMP - PG \t06.00 -> 12.00\t\tRM8500\n";
  cout << " QATAR   \tQT360\t\tPG - MP \t14.00 -> 20.00\t\tRM7600\n";
  cout << " QATAR   \tQT460\t\tMP - PG \t14.00 -> 20.00\t\tRM7600\n";
  cout << " EITHAD  \tER560\t\tPG - MP \t22.00 -> 05.00\t\tRM9800\n";
  cout << " EITHAD  \tER660\t\tMP - PG \t22.00 -> 05.00\t\tRM9800\n";

  cout << " EMIRATES\tED170\t\tPG - MN \t06.00 -> 12.00\t\tRM9800\n";
  cout << " EMIRATES\tED270\t\tMN - PG \t06.00 -> 12.00\t\tRM9800\n";
  cout << " QATAR   \tQT370\t\tPG - MN \t14.00 -> 20.00\t\tRM8800\n";
  cout << " QATAR   \tQT470\t\tMN - PG \t14.00 -> 20.00\t\tRM8800\n";
  cout << " EITHAD  \tER570\t\tPG - MN \t22.00 -> 05.00\t\tRM7800\n";
  cout << " EITHAD  \tER670\t\tMN - PG \t22.00 -> 05.00\t\tRM7800\n";

  cout << " EMIRATES\tED180\t\tPG - IZ \t06.00 -> 12.00\t\tRM8900\n";
  cout << " EMIRATES\tED280\t\tIZ - PG \t06.00 -> 12.00\t\tRM8900\n";
  cout << " QATAR   \tQT380\t\tPG - IZ \t14.00 -> 20.00\t\tRM7800\n";
  cout << " QATAR   \tQT480\t\tIZ - PG \t14.00 -> 20.00\t\tRM7800\n";
  cout << " EITHAD  \tER580\t\tPG - IZ \t22.00 -> 05.00\t\tRM9900\n";
  cout << " EITHAD  \tER680\t\tIZ - PG \t22.00 -> 05.00\t\tRM9900\n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
//  sleep(0.5);
}
////////////////////////////////////////////////////////////////////////////////
void time()
{
  cout << "\n";
   // current date/time based on current system
   time_t now = time(0);
      // convert now to string form
   char* dt = ctime(&now);

   cout << "\t\t\tMALAYSIA TIME :: " << dt << endl << endl;

}
/////////////////////////////////////////////////////////////////////////////////
class authentication
{
public:
  void login()
  {
          int count;
          string user,pass,u,p;
          system("cls");
          cout <<"\n\n\n";
          cout <<"\t\t<><><><><><><><><><><><><><><><><><><><><><>\n";
          cout<<"\t\t\t MEMBER LOGIN \n";
          cout <<"\t\t<><><><><><><><><><><><><><><><><><><><><><>\n\n";
          cout<<"\t\t\tMEMBER USERNAME :: ";
          cin>>user;
          cout <<endl;
          cout<<"\t\t\tMEMBER PASSWORD :: ";
          cin>>pass;

          ifstream input("login.txt");
          while(input>>u>>p)
          {
                  if(u==user && p==pass)

                  {
                          count=1;
                          system("cls");
                  }
          }
          input.close();
          if(count==1)
          {
                  cout <<"\n\n\n\n";
                  cout<<"\n\t\tGREETINGS "<< " "<<user<<"\n\t\tLOGIN SUCCESSFUL ! \n\t\tWe're glad that you have choosen PD airlines.\n";
                  cin.get();
                  //cin.get();
                  sleep(1);

          }
          else
          {       cout <<"\n\n\n\n";
                  cout<<"\n\t\tLOGIN ERROR\n\t\tPLEASE CHECK YOUR USERNAME AND PASSWORD\n";
                  test();


          }
  }

  void registr()
  {

          string reguser,regpass,ru,rp;
          system("cls");
          cout << endl <<endl;
          cout <<"\n\n\n";
          cout <<"\t<><><><><><><><><><><><><><><><><><><><><><>\n";
          cout<<"\t\t MEMBER REGISTRATION \n";
          cout <<"\t<><><><><><><><><><><><><><><><><><><><><><>\n";
          cout<<"\tEnter new username :";
          cin>>reguser;
          cout<<"\n\tEnter new password :";
          cin>>regpass;

          ofstream reg("login.txt",ios::app);
          reg<<reguser<<' '<<regpass<<endl;
          system("cls");
          cout<<"\n\tRegistration Successful\n";
          cout <<"\tPlease activate your account"<<endl;
          sleep(3);
        //  login();
  }

  void forgot()
  {
          int ch;
          system("cls");
          cout <<"\n\n\n";
          cout <<"\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
          cout<<"\t\tForgotten your Username or Password ? \n";
          cout <<"\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
          cout<<"\t1.Search your id by username"<<endl;
          cout<<"\t2.Search your id by password"<<endl;
          cout<<"\t3.Main menu\n"<<endl;
          cout<<"\tEnter your choice :: ";
          cin>>ch;
          switch(ch)
          {
                  case 1:
                  {
                          int count=0;
                          string searchuser,su,sp;
                          cout<<"\n\tEnter your remembered username :";
                          cin>>searchuser;

                          ifstream searchu("login.txt");
                          while(searchu>>su>>sp)
                          {
                                  if(su==searchuser)
                                  {
                                          count=1;
                                  }
                          }
                          searchu.close();
                          if(count==1)
                          {
                                  cout<<"\n\n\tHurray,your account have been found\n";
                                  cout<<"\n\tYour password is "<<sp;
                                  cin.get();
                                  cin.get();
                                  system("cls");

                          }
                          else
                          {
                                  cout<<"\n\tSorry, Your userID is not found in our system\n";
                                  cout<<"\n\tPlease kindly contact our system administrator for more details \n";
                                  cin.get();
                                  cin.get();

                          }
                          break;
                  }
                  case 2:
                  {
                          int count=0;
                          string searchpass,su2,sp2;
                          cout<<"\n\tEnter the remembered password :";
                          cin>>searchpass;

                          ifstream searchp("login.txt");
                          while(searchp>>su2>>sp2)
                          {
                                  if(sp2==searchpass)
                                  {
                                          count=1;
                                  }
                          }
                          searchp.close();
                          if(count==1)
                          {
                                  cout<<"\n\tYour password is found in the system \n";
                                  cout<<"\n\tYour username : "<<su2;
                                  cin.get();
                                  cin.get();
                                  system("cls");

                          }
                          else
                          {
                                  cout<<"\tSorry, We cannot find your password in our database \n";
                                  cout<<"\n\tKindly contact your administrator for more information\n";
                                  cin.get();
                                  cin.get();
                          }

                          break;
                  }
                  case 3:
                  {
                          system("CLS");
                          test();
                          system("CLS");
                          cin.get();
                  }
                  default:
                          cout<<"\tSorry, You have entered the wrong choice. Kindly, try again"<<endl;
          }
  }
  void test()
  {
    system("CLS");
    system("color f0");
    sleep(0.1);

              int choice;
              cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
              cout<<"\t         MEMBER LOGIN PAGE                           \n\n";
              cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><\n";
                    cout<<"\t1.LOGIN"<<endl;
                    cout<<"\t2.REGISTER"<<endl;
                    cout<<"\t3.FORGOT PASSWORD (or) USERNAME"<<endl;
                    cout<<"\t4.EXIT"<<endl;
                    cout<<"\n\tENTER YOUR CHOICE :";
                    cin>>choice;
                    cout<<endl;
                    switch(choice)
                    {
                            case 1: cout<< setw(2) <<"\a";
                                    system("CLS");
                                    login();
                                    break;

                            case 2: cout<< setw(2) <<"\a";
                                    system("CLS");
                                    registr();
                                    system("CLS");
                                    test();
                                    break;

                            case 3: system("CLS");
                                    forgot();
                                    system("CLS");
                                    test();
                                    cout<< setw(2) <<"\a";
                                    system("CLS");
                                    break;

                            case 4: cout<< setw(2) <<"\a";
                                    system("CLS");
                                    test();
                                    cout<<"\tThanks for using PD Airline Management System\n\n";
                                    break;

                            default:test();
                                    system("CLS");
                                    cout<<"\tInvalid Input, Please try again\n"<<endl;
                                    system("CLS");

                    }


  }

};
////////////////////////////////////////////////////////////////////////////////
int main()//main function
{
   intro();
   sleep(2.0);
   system("cls");
   system("color 5E");
   Admin a;
    class authentication l1;
    class localBooking d1;
    class interBooking i1;
    class passenger p1;
    class payment p2;
    int ch,ch1,n;            // choice selected by user
    char input;              // values entered by the user
    do                       // loop do-while
    {
      system("CLS");
  //  cout << "\n\n \t\tFLIGHT MANAGEMENT SYSTEM" << endl << endl;
    cout <<"\t  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout <<"\t                    MAIN MENU" << endl;
    cout <<"\t  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "\n\n\t\t\t1.Book Flight \n\t\t\t2.Cancel Fight \n\t\t\t3.Check Ticket \n\t\t\t4.Flight schedule Local \n\t\t\t5.Flight schedule International \n\t\t\t6.Admin Priviledges \n\t\t\t7.Exit" << endl;
    cout << endl;
    cout <<"\t  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n\t\t Please enter your choice: ";
    cin >> ch;

switch(ch)//witch case
      {
        case 1://condition
        system("CLS");
            cout << "\t------------------------------------------------------"<<endl;
            cout << "\t\t\t MAIN MENU" << endl;
            cout << "\t------------------------------------------------------"<<endl;
            cout << "\n\n\t\t1.Local Fights \n\t\t2.International Flights \n\t\t3.Exit to main menu" << endl;
            cout << "\n\t\tPlease choose your option (1-3)" << endl;
            cout << "\t------------------------------------------------------"<<endl;
            cout << "\t CHOICE :: ";
            cin >> ch1;
            system("CLS");
              switch(ch1)//inner switch case
              {
                   case 1://for booking domestic ticket
                        system("CLS");
                        system("color 30");
                        l1.test(); //login
                        system("color 30");
                        p1.l_ref();
                        system("CLS");
                        p1.passDetails(1);//function calls
                        p1.genderChoice();
                        system("CLS");
                        run();
                        p1.weightage();
                        system("CLS");
                        system("color E0");
                        p2.payDetail();
                        system("CLS");
                        p1.extraDetailsLocal();
                        createfile(p1);//call to create file
                        break;
                   case 2: //for booking international ticket
                           system("CLS");
                           system("color 30");
                           l1.test();
                           system("color 30");
                           p1.i_ref();
                           system("CLS");
                           p1.passDetails(2);//function calls
                           p1.genderChoice();
                           system("CLS");
                           run();
                           p1.weightage();
                           system("CLS");
                           system("color E0");
                           p2.payDetail();
                           system("CLS");
                           p1.extraDetailsInter();
                           createfilei(p1);//call to create file
                           break;
                        case 3: main();
                   default://wrong input
                    cout << "\t\tWrong input entered\nTry again\n\n\n" << endl;
                    cout<< setw(2) <<"\a";
                    return main();
              }
          break;
          case 2:
              //for canceling ticket
                            system("CLS");
              cout << "\t------------------------------------------------------"<<endl;
              cout << "\t\t\t TICKET CANCELLATION" << endl;
              cout << "\t------------------------------------------------------"<<endl;
              cout << "\n\t\t1.Local Fights \n\t\t2.International Flights" << endl;
              cout << "\t------------------------------------------------------"<<endl;
                 cout << "\n\t\tPlease enter your option : ";
                 cin >> ch1;
                 cout<<endl;
                  if(ch1==1)
                {
                   cout << "\t\tPlease enter your TICKET no.: " ;
                   cin>>n;
                   cout <<endl;
                   cancelticket(n);//function call for domestic booking cancellation
                }
                 else if(ch1==2)
               {  cout << "\t\tPlease enter your TICKET no.: ";
                  cin>>n;
                  cout<<endl;
                  cancelticketi(n);//function call for international cancellation
               }
               else
               {
                   cout << "\t\tWrong input entered\n\t\tTry again\n\n\n";
                   cout<< setw(2) <<"\a";
                   return main();
               }
               break;
          case 3://for displaying booked ticket details
          system("CLS");
                  cout << "\t------------------------------------------------------"<<endl;
                  cout << "\t\t\t CHECK DETAILS" << endl;
                  cout << "\t------------------------------------------------------"<<endl;
                  cout << "\n\t\t1.Local Fights  \n\t\t2.International Flights " << endl;
                  cout << "\t------------------------------------------------------"<<endl;
                  cout << "\n\t\tPlease enter your option : ";
                  cin >> ch1;
                  if(ch1==1)
                  {
                    cout << "\n\t\tPlease enter your Ticket no. : ";
                  cin>>n;
                  system("CLS");
                  checkticket(n);
                  }//function call to display domestic ticket details
                  else if(ch1==2)
                  {  cout << "\n\t\tPlease enter your Ticket no. : " << endl;
                     cin>>n;
                     system("CLS");
                     checkticketi(n);//function call to display domestic ticket details
                  }
                   else
               {
cout << "\n\t\tWrong input entered.\n\t\tTry again\n\n\n";
                   cout<< setw(2) <<"\a";
                   return main();
               }
               break;
            case 4 :system("CLS");

                    local();
                    system("pause");
                    cout<< setw(2) <<"\a";
                    system("CLS");
                    return main();

            case 5 :system("CLS");
                    abroad();
                    system("pause");
                    cout<< setw(2) <<"\a";
                    system("CLS");
                    return main();

            case 6 :system("CLS");
                    a.login_page();
                    adminMenu();
                    cout<< setw(2) <<"\a";
                    return main();
            case 7:
      system("CLS");
      cout<<"\n\n\n\n\n\n\n\t\t\t\tTHANK YOU FOR USING PD AIRLINES "<<endl;
      Beep(523.2511,500);  // 523.2511 hertz (C5) for 500 milliseconds
      Beep(587.3295,500);
      Beep(659.2551,500);
      Beep(698.4565,500);
      Beep(783.9909,500);
      return 0;
          default://for wrong input
            cout << "\tWrong input entered\nTry again.\n\n\n\n" << endl;
            return main();
      }
    cout<<"\n\n\tDo you wish to continue:(y/Y)"<<endl;
    cout << "\tCHOICE :: ";
    cin >> input;
  }while(input=='Y' || input=='y');//condition for do while loop
return 0;
}

void Admin:: login_page()
{
  system("color 3f");
  string username;
  string password;
  int loading = 0;

  system("cls");
  system("color 1f");
  do
  {
    cout <<"\n\n\n\n\n\n\n";
    cout <<"\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout <<"\t\t ADMINISTRATOR AUTHENTICATION PAGE\n";
    cout <<"\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout<<"\a\n\n\t\t\tENTER USERNAME: ";
    cin>>username;
    if (username == "admin" || username == "ADMIN")
    {
            cout<<"\a\t\t\tENTER PASSWORD: ";
            cin>>password;

            if (password == "1234")
            {
                for(int i = 0; i < 1; i++)
                    {
                        system("cls");
                        cout<<endl;
                        cout << "\a\n\n\n\n\n\n\n\n\n\t\t\tAccess Granted...\n";
                        Sleep(200);system("cls");Sleep(200);


                    }
            }
                    else
                    {
                        for(int i = 0; i < 3; i++)
                            {
                                system("cls");
                                cout<<endl;
                                cout << "\a\n\n\n\n\n\n\n\n\n\t\t\tAccess Aborted...\n";
                                Sleep(200);system("cls");Sleep(200);
                            }
                    }
            }
    else
    {
        cout<<"\t\t\t Invalid Username. Try again! " <<endl;
        sleep(1.0);
        system("cls");
    }
  } while (password != "1234");
  while (loading <= 100)
{
cout << setw(2) << "\n\n\n\n\n\n\n\n\n\t\t::... Please Wait While The System Initialize ...::\n";
cout<<"\t\t\t\t\t" << loading << "%";
//Sleep(20);
system ("cls");
loading ++;
}
return adminMenu();
}
void displayClock()
{
    // system call to clear the screen
    system("cls");
    cout <<"\n\n\n\n\n\n\n";
    cout << setfill(' ') << setw(55) << "\t\t PD AIRLINES IS IN STANDBY MODE         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout <<" \n\n\t PD AIRLINES WILL BE OPERATED FROM 6.00 A.M. TO 10.00 P.M. EVERY DAY  "<<endl<<endl;
}
void timer()
{
    while (true)
    {
        displayClock();
        sleep(1);
        // increment seconds
        seconds--;
        // if seconds reaches 60
        if (seconds == 0)
         {
            // increment minutes
            minutes--;
            // if minutes reaches 60
            if (minutes == 0)
            {
                // DECrement hours
                hours--;

                minutes = 60;
            }
            seconds = 60;
        }
    }
    //main();
}
void delayStand()
{

  timer();
  main();
}
void adminMenu()
{
  int a;
  system("CLS");
//  cout << "\n\n \t\tFLIGHT MANAGEMENT SYSTEM" << endl << endl;
cout <<"\t  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
cout <<"\t                    MAIN MENU" << endl;
cout <<"\t  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
cout <<"\t  1) STANDBY MODE \n";
cout <<"\t  2) DELAY ANNOUNCEMENT \n";
cout <<"\t  3) EXIT TO MAIN MENU \n";
cout << "\n\t PLEASE ENTER YOUR CHOICE : ";
cin >> a;
if (a==1)
{
  if(MessageBox(NULL, "SYSTEM WILL BE OPERATED 8 HOURS FROM NOW ", "STANDBY MODE",  MB_YESNOCANCEL) == IDYES)
  {
    delayStand();
  }
  else
  {
    system("CLS");
    main();
  }
}
if (a==2)
{
  system("CLS");
  system("color B0");
  cout <<"\n\n\n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
  cout << "\t\t\t DELAY ANNOUNCEMENT " << endl;
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
  cout << "   Airline\tFlight.No\tDestination\tTime Changes \n\n";
  cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
  cout << "1) EMIRATES\tED150\t\tPG - IZ \t07.00 -> 13.00\n";
  cout << "2) QATAR   \tQT360\t\tLG - MP \t15.00 -> 21.00\n\n\n\n";
  system("PAUSE");
  return adminMenu();
}
if(a==3)
  {
    system("CLS");
    main();
  }
else
  {
    return adminMenu();
  }
}

//calculation FOR seat

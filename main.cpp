#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//class for storing the slot number,Registration_number and age.
class Parking_lot
{
  public:int age;
          int slot;
          string registration_number;
  
};


int main() {
  string line;

  //object of array
  Parking_lot park[1000];
  ifstream myfile ("input.txt");
  vector<string>commands; //for splitting the command into string array
  
  // vacant varibale used for vacant slots.
  int vacant=0;
  
  //reading the input.txt file
  if (myfile.is_open())
  {  int total_Slot_Number = 0;

    //assign slots according to count variable.
    int count=1;
    while ( getline (myfile,line) )
    {
     
    istringstream iss(line);

    //Actual splitting of commands in commands vector.
    for(string s;iss>>s;)
    { 
      commands.push_back(s);
    }
    
    //For creating total slots.
    if(commands[0]=="Create_parking_lot")
    {
      stringstream convert_to_int(commands[1]);
      convert_to_int >> total_Slot_Number;
      cout<<"Created parking of "<<total_Slot_Number<<" slots"<<endl;
      commands.clear();
    }


    //After creating parking slots.
    //Further commands will excute from else part.
    else{
      
      for(int i=count;i<=total_Slot_Number;i++)
      {
        if(commands[0]=="Park")
        {  
          stringstream geek(commands[3]);
          int x1=0;
          geek>>x1;

          //checking if any vacant slot is present or not.
          if(vacant>0)
          {
            for(int k=1;k<=total_Slot_Number;k++)
           {
             if(park[k].registration_number=="vacant")
             {
              park[k].age=x1;
              park[k].slot=k;
              park[k].registration_number=commands[1];
              cout<<"Car with vehicle registration number "<<park[k].registration_number<<" has been parked at slot number "<<park[k].slot<<endl;
              break;
             }
           }
          }
          else
          {
          park[i].age=x1;
          park[i].slot=i;
          park[i].registration_number=commands[1];
          cout<<"Car with vehicle registration number "<<park[i].registration_number<<" has been parked at slot number "<<park[i].slot<<endl;
          }
        }
        
        //Will execute the command "Slot_numbers_for_driver_of_age"
         if(commands[0]=="Slot_numbers_for_driver_of_age")
        { 
          count--;
          for(int j=1;j<=total_Slot_Number;j++)
          {
            int x2;
            stringstream geek(commands[3]);
            geek>>x2;
          
            if(x2==park[j].age)
            {
            cout<<park[j].slot<<", ";
            
            }
          }cout << "\b\b ";
          cout<<endl;
         }
        

        //Will execute the command "Slot_number_for_car_with_number"

        if(commands[0]=="Slot_number_for_car_with_number")
        {
          count--;
          for(int j=1;j<=total_Slot_Number;j++)
          {
          
            if(commands[1]==park[j].registration_number)
            {

            cout<<park[j].slot<<", ";
            }
          }cout << "\b\b ";
          cout<<endl;
        }
        //Will execute the command "Leave"

        if(commands[0]=="Leave")
        {
            int leave_slot;
            stringstream geek(commands[1]);
            geek>>leave_slot;
            cout<<"slot number "<<leave_slot<<" vacted, the car with vehicle registration number "<<park[leave_slot].registration_number<<" left the space, the driver of the car was of age "<<park[leave_slot].age<<endl;
            park[leave_slot].age=0;
            park[leave_slot].slot=0;
            park[leave_slot].registration_number="vacant";
          vacant++; 

        }

        //Will execute the command //"Vehicle_registration_number_for_driver_of_age"

        if("Vehicle_registration_number_for_driver_of_age"==commands[0])
        {
          count--;
          int Final_age;
          stringstream convert_to_int(commands[1]);
          convert_to_int>>Final_age;
          for(int j=1;j<=total_Slot_Number;j++)
          {
          
          if(Final_age==park[j].age)
          {
            cout<<park[j].registration_number;
          }
          }
          cout<<endl;
        }
        
        commands.clear();
        count++;
        break;

      }
      
    if(count>total_Slot_Number){
       cout<<"Slots full";
    }
      
    }
    
    
    
   
    }
    myfile.close();
  }
   

  return 0;
}
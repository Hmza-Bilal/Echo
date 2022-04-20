/* The following Code takes a .asm file as an argument , Thanks to 
"https://stackoverflow.com/questions/30141000/c-how-to-pass-command-line-argument-to-read-txt-file/30141375"
and creates a hack file of binary with no symbols */



#include<iostream>
#include "Translation_Table.cpp"
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<bitset>
#include<unordered_map>
#include<algorithm>
#include<sstream>


using namespace std;
ofstream file("BinaryConverted.hack",ios::trunc);



void Binary_Conversion(int num)
{
        int arr[16];           
    for (int i = 0; i < 16; i++)
    {
        arr[i] = 0;
    }
    for (int i = 15; i >= 0; i--) // Applying loop and then Coverting the Value in Binary
    {
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                arr[i] = 0;
            }
            else
            {
                arr[i] = 1;
            }
            num = num/2;
            i--;
        }
    }
    for (int i = 0; i < 16; i++) // Code to Print Array
    {
        file << arr[i];
    }  
    file << "\n";
}

string Remove_Space(string e)
{
    e.erase(remove(e.begin(),e.end(),' '),e.end()); //Function to Erase Spaces
    return e; // Help taken from "https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/"
}


int main(int argc , char* argv[]){
    Translator_Table t;
    string a , temp, t_dest;
    string A_symbol = "@";
    string dot = ".";
    string del1 = ";";
    string del2 = "=";
    string del3 = "/";
    size_t position = 0;
    string del0;              
    string filename;
    filename = argv[1];
    fstream in(filename);
    while (!in.eof())
    {
        getline(in,a);
        
        if (a.find('*') != string::npos || a.find('/') != string::npos)
        {

            if (a[0] == '/' || a.find('*') != string::npos)
            {
                continue;
            }
            a = Remove_Space(a);
            a = a.substr(0,a.find('/'));

            // Above check is to Remove Comments(Single and Multi Line) and Spaces
        }
        else
        {

            a = Remove_Space(a); // removes Spaces if no Comment
        }
        // A Instruction
        if (a.find(A_symbol) != string::npos)
        {
            
            while (position=a.find(A_symbol) != string::npos)
            {
                temp = a.substr(0,position);   //This Code Checks for A instruction till @ sign
                a.erase(0,A_symbol.length());  
            
                int i = stoi(a);  // Convert String in Integer, Function used
                Binary_Conversion(i);
            }
        }
        // C Instruction
         if (a.find(del2) != string::npos) // Check for = Symbol if present then it is C instruction
        {
            file << "111";
            while (position=a.find(del2) != string::npos)
            {
                del0 = a.substr(0,a.find(del2));
                t_dest = t.DestConvert(del0);       //Temporary Variable Initialized for storage of Binary
                a.erase(0,a.find(del2)+1);
                file << t.CompConvert(a);
                file << t_dest;
            
                file << "000";             // As there is No jmp so Last 3 bits will be 000
                file << "\n";
            } 
        } 
        if (a.find(del1) != string::npos)
        {
            file << "111"; //Reserving Frirst three bits of C instruction
            while (position=a.find(del1) != string::npos)
            {
                del0 = a.substr(0,a.find(del1));  // From start of Instruction Sting Starts till ; is Located
                file << t.CompConvert(del0);
            
                file << "000";           // Dest has 000 Bits in Instruction
                a.erase(0,a.find(del1)+1);  //Removing the string till ';' is located
                file << t.JumpConvert(a) << "\n";
            }
        }
       
    }
    in.close();
    file.close();
    return 0;
}


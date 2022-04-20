#include <iostream>
#include <map>

using namespace std;

class SymbolTable{
private:
    map<string , int> SymbolsTable;
public:
    SymbolTable()
    {
        SymbolsTable["R0"] = 0;
        SymbolsTable["R1"] = 1;
        SymbolsTable["R2"] = 2;
        SymbolsTable["R3"] = 3;
        SymbolsTable["R4"] = 4;
        SymbolsTable["R5"] = 5;
        SymbolsTable["R6"] = 6;
        SymbolsTable["R7"] = 7;
        SymbolsTable["R8"] = 8;
        SymbolsTable["R9"] = 9;
        SymbolsTable["R10"] = 10;
        SymbolsTable["R11"] = 11;
        SymbolsTable["R12"] = 12;
        SymbolsTable["R13"] = 13;
        SymbolsTable["R14"] = 14;
        SymbolsTable["R15"] = 15;
        SymbolsTable["SP"] = 0;
        SymbolsTable["LCL"] = 1;
        SymbolsTable["ARG"] = 2;
        SymbolsTable["THIS"] = 3;
        SymbolsTable["THAT"] = 4;
        SymbolsTable["SCREEN"] = 16384;
        SymbolsTable["KBD"] = 24576;
    }
    int symbolConvert(string symbol)
    {
        if (SymbolsTable.find(symbol) != SymbolsTable.end())
        {
            return SymbolsTable[symbol];
        }
        else
        {
            return 0;
        } 
    }
    void addEntry(string s, int value)
    {
        // Adds symbol and then gives value to it.
        if (SymbolsTable.find(s) == SymbolsTable.end())
        {
            SymbolsTable[s] = value;
        }  
    }
    
};
class Translator_Table{
private:
    map<string , string> dest;
    map<string , string> cmp;
    map<string , string> jmp;
public: 
    Translator_Table()
    {
        dest[""] = "000";
        dest["M"] = "001";
        dest["D"] = "010";
        dest["MD"] = "011";
        dest["A"] = "100";
        dest["AM"] = "101";
        dest["AD"] = "110";
        dest["AMD"] = "111";
    
        cmp["0"] = "0101010";
        cmp["1"] = "0111111";
        cmp["-1"] = "0111010";
        cmp["D"] = "0001100";
        cmp["A"] = "0110000";
        cmp["!D"] = "0001101";
        cmp["!A"] = "0110001";
        cmp["-D"] = "0001111";
        cmp["-A"] = "0110011";
        cmp["D+1"] = "0011111";
        cmp["A+1"] = "0110111";
        cmp["D-1"] = "0001110";
        cmp["A-1"] = "0110010";
        cmp["D+A"] = "0000010";
        cmp["D-A"] = "0010011";
        cmp["A-D"] = "0000111";
        cmp["D&A"] = "0000000";
        cmp["D|A"] = "0010101";
        cmp["M"] = "1110000";
        cmp["!M"] = "1110001";
        cmp["-M"] = "1110011";
        cmp["M+1"] = "1110111";
        cmp["M-1"] = "1110010";
        cmp["D+M"] = "1000010";
        cmp["D-M"] = "1010011";
        cmp["M-D"] = "1000111";
        cmp["D&M"] = "1000000";
        cmp["D|M"] = "1010101";
        //JMP Table implementation
        jmp[""] = "000";
        jmp["JGT"] = "001";
        jmp["JEQ"] = "010";
        jmp["JGE"] = "011";
        jmp["JLT"] = "100";
        jmp["JNE"] = "101";
        jmp["JLE"] = "110";
        jmp["JMP"] = "111";
    }
    string DestConvert(string destString)
    {
        if (dest.find(destString) != dest.end())
        {
            return dest[destString];
        }
        else
        {
            exit(1);
        }  
    }
    string CompConvert(string compString)
    {
        if (cmp.find(compString) != cmp.end())
        {
            return cmp[compString];
        }
        else
        {
            exit(1);
        }  
    }
    string JumpConvert(string jmpString)
    {
        if (jmp.find(jmpString) != jmp.end())
        {
            return jmp[jmpString];
        }
        else
        {
            exit(1);
        }  
    }
};
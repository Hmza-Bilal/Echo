/* The Following Table is based from  "https://github.com/francoiswnel/Hack-Assembler/blob/master/CodeTranslator.cpp" 
       where the table is coded with other tables. The Functions Have been Understood and Also taken from the Site */




#include <iostream>
#include <map>

using namespace std;

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
    string DestConvert(string destString)                    // Converts dest in string
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
    string CompConvert(string compString)                // Converts comp in string
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
    string JumpConvert(string jmpString)               // Converts jmp in string
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
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<fstream>
#include "compilerVersion.hh"

#define FILE "compiler.txt"

int main()
{
  compilerVersion my_compiler("MinGW","8.1.0");

  //Print message
  my_compiler.show_compiler_version();
  
  std::ofstream fileOut;
  fileOut.open(FILE);
  if (fileOut.is_open()) {
    fileOut << "Compiler: " << my_compiler.compiler_name() << std::endl;
    fileOut << " Version: " << my_compiler.compiler_number() << std::endl;
    fileOut.close();
  } 
  else {
    std::cerr << "Error: can't open " << FILE << std::endl;
    exit(EXIT_FAILURE);
  }
 
  return(EXIT_SUCCESS); //end of program
}
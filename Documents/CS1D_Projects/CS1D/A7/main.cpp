#include "BrowserClass.h"
#include "BrowserClass.cpp"
#include <fstream>
#include <iostream>

int main() {
  BrowserClass browser;

  //set open browser.txt
  std::ifstream inputFile("browser.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error: Failed to open browser.txt\n";
    return 1;
  }

  // read input file and do the browsing stuff 
  std::string line;
  while (std::getline(inputFile, line)) {
    if (line == "9999") {
      browser.pressBack();
    } else if (line == "9998") {
      browser.pressForward();
    } else {
      browser.visitNewWeb(line);
    }
  }

  // put the browsing history in the output file and print the output if executed correctly 
 	browser.writeOutput();

  std::cout << "Browsing history saved to output.txt\n";

  return 0;
}

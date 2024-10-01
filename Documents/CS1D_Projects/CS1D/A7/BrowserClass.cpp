#include "BrowserClass.h"
#include <fstream>
#include <iostream>


BrowserClass::BrowserClass() {
    // constructor

}//end fucntion

//-----------------------------


void BrowserClass::visitNewWeb(const std::string& website) {
    backStack.push_back(website);

   //clearing front stack when you visi the new website
	forwardStack.clear();

}//end function


//------------------------------

void BrowserClass::pressBack() {
  if (!backStack.empty()) {
    forwardStack.push_back(backStack.back());
    backStack.pop_back();
  }
}

//-------------------------------

void BrowserClass::pressForward() {
    if (!forwardStack.empty()) {
        backStack.push_back(forwardStack.back());
        forwardStack.pop_back();
    }
}

//-------------------------------
void BrowserClass::writeOutput() {
  std::ofstream output("output.txt");
  if (!output.is_open()) {
    std::cerr << "Error: Failed to open output file\n";
    return;
  }

  //if stattemnt to see if backward is empty 
  if (backStack.empty()) {
    output << "9999 - backward stack empty\n";
  } else {
    for (auto it = backStack.rbegin(); it != backStack.rend(); ++it) {
      output << *it << " - " << *it << '\n'; // print web
    }
  }

  // if to see if forward is empty
  if (forwardStack.empty()) {
    output << "9998 - forward stack empty\n";
  }

  output.close(); //close file
}

//error w writeoutput or main?


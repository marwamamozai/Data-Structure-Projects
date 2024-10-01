#ifndef BROWSERCLASS_H
#define BROWSERCLASS_H

#include <string>
#include <vector>

class BrowserClass {
	public:
    BrowserClass();
    void visitNewWeb(const std::string& website); //user will visit new web page 
    void pressBack();
    void pressForward();
    void writeOutput();

	private:
    std::vector<std::string> backStack;
    std::vector<std::string> forwardStack;
};



#endif // BROWSERCLASS_H

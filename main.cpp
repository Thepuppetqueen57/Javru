#include <iostream>
#include <string>
#include "lib/jvrl.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are taken
    if (argc != 2) {
        cerr << "Usage: javru <arg> (file extension is optional)" << std::endl;
        return 1;
    }

    // Convert argv[1] to a string
    string arg = argv[1];

    if (arg.size() > 5 && arg.substr(arg.size() - 5) == ".java") {
        arg = arg.substr(0, arg.size() - 5);
    }

    // Call the cmdd function from the library
    int cmdd_result = cmdd(arg);

    // Check the result of cmdd
    if (cmdd_result != 0) {
        cerr << "cmdd function failed. Exiting program." << endl;
        return cmdd_result;
    }

    // Call the run execution function
    int runresult = run_class(arg);

    // Check if the run command was successful
    if (runresult != 0) {
        cerr << "Error: Failed to execute the java command." << endl;
        return runresult;
    }

    // Call the delete function
    int deleteresult = delete_file(arg);

    // Check if the delete command was successful
    if (deleteresult != 0) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return deleteresult;
    }

    return 0;
}

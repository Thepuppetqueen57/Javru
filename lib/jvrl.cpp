#include "jvrl.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to execute a command to compile Java or Kotlin
int cmdd(string& arg, const string& language) {
    // Construct the command string for compilation
    string cmd;
    if (language == "java") {
        cmd = "javac " + arg + ".java";
    } else if (language == "kotlin") {
        cmd = "kotlinc " + arg + ".kt -include-runtime -d " + arg + ".jar";
    }

    // Execute the compile command
    int result = system(cmd.c_str());

    // Check if the compile command was successful
    if (result != 0) {
        cerr << "Error: Failed to execute the compile command." << endl;
        return 1;
    }

    return 0;
}

// Function to run the Java or Kotlin class
int run_class(const string& arg, const string& language) {
    string runcmd;
    if (language == "java") {
        runcmd = "java " + arg;
    } else if (language == "kotlin") {
        runcmd = "java -jar " + arg + ".jar";
    }
    int result = system(runcmd.c_str());

    if (result != 0) {
        cerr << "Error: Failed to execute the run command." << endl;
        return 1;
    }

    return 0;
}

// Function to delete the generated class or jar file
int delete_file(const string& arg, const string& language) {
    string deletecmd;
    if (language == "java") {
        deletecmd = "del " + arg + ".class";
    } else if (language == "kotlin") {
        deletecmd = "del " + arg + ".jar";
    }
    int result = system(deletecmd.c_str());

    if (result != 0) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return 1;
    }

    return 0;
}

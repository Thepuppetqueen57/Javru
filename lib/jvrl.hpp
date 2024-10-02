#ifndef JVRL_HPP
#define JVRL_HPP

#include <string>
#include <iostream>
#include <cstdlib>

// Function to execute a command to compile Java or Kotlin
inline int cmdd(std::string& arg, const std::string& language) {
    // Construct the command string for compilation
    std::string cmd;
    if (language == "java") {
        cmd = "javac " + arg + ".java";
    } else if (language == "kotlin") {
        cmd = "kotlinc " + arg + ".kt -include-runtime -d " + arg + ".jar";
    }

    // Execute the compile command
    int result = system(cmd.c_str());

    // Check if the compile command was successful
    if (result != 0) {
        std::cerr << "Error: Failed to execute the compile command." << std::endl;
        return 1;
    }

    return 0;
}

// Function to run the Java or Kotlin class
inline int run_class(const std::string& arg, const std::string& language) {
    std::string runcmd;
    if (language == "java") {
        runcmd = "java " + arg;
    } else if (language == "kotlin") {
        runcmd = "java -jar " + arg + ".jar";
    }
    int result = system(runcmd.c_str());

    if (result != 0) {
        std::cerr << "Error: Failed to execute the run command." << std::endl;
        return 1;
    }

    return 0;
}

// Function to delete the generated class or jar file
inline int delete_file(const std::string& arg, const std::string& language) {
    std::string deletecmd;

#ifdef _WIN32 // Check if we are on a Windows system
    if (language == "java") {
        deletecmd = "del " + arg + ".class";
    } else if (language == "kotlin") {
        deletecmd = "del " + arg + ".jar";
    }
#else // Assume a Unix-like system if not Windows
    if (language == "java") {
        deletecmd = "rm " + arg + ".class";
    } else if (language == "kotlin") {
        deletecmd = "rm " + arg + ".jar";
    }
#endif

    int result = system(deletecmd.c_str());

    if (result != 0) {
        std::cerr << "Error: Failed to execute the delete command." << std::endl;
        return 1;
    }

    return 0;
}

#endif // JVRL_HPP
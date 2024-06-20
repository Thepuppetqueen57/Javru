#ifndef JVRL_HPP
#define JVRL_HPP

#include <string>

int cmdd(std::string& arg, const std::string& language);
int run_class(const std::string& arg, const std::string& language);
int delete_file(const std::string& arg, const std::string& language);

#endif // JVRL_HPP

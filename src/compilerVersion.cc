#include<iostream>
#include<string>
#include "compilerVersion.hh"


compilerVersion::compilerVersion(const std::string& sys_compiler, const std::string& sys_version) {
   this->compiler = sys_compiler;
   this->version = sys_version;
}

void compilerVersion::show_compiler_version() {
    std::cout << "Compiler: " << compiler << std::endl;
    std::cout << " Version: " << version << std::endl;
}       

std::string compilerVersion::compiler_name() {
    return this->compiler;
}

std::string compilerVersion::compiler_number() {
    return this->version;
}

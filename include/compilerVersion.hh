#ifndef _MY_PROJECT_INCLUDE_COMPILERVERSION_HH_
#define _MY_PROJECT_INCLUDE_COMPILERVERSION_HH_

class compilerVersion {
    private:
        std::string compiler;
        std::string version;
    public: 
        compilerVersion(const std::string&, const std::string&);
        void show_compiler_version();
        std::string compiler_name();
        std::string compiler_number();     
};

#endif // _MY_PROJECT_INCLUDE_COMPILERVERSION_HH_          
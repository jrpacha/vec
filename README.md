# vec: an example of using the C++ language's class "vector"

This repo has been built up using the template:

## my_C++_project_template: template for my C/C++ projects using CMake

### Instructions for Linux/Mac

Let us assume that the project folder is `myProject`, and project's run file is `foo`. Then:

1. In `myProject/CMakeLists.txt`, change `"myProjectRunFile"`, at

    `set(program "myProjectRunFile")`

   (on the 2nd line), by
  
    `set(program "foo")`

2. Put your source files in the project's **src** folder, i.e., `myProject/src`

3. Put yout include files in the project's **include** folder, i.e., `myProject/include`

4. To build the project:
    1. First create a `build`folder and `cd` to  it,

       ```zsh
        JohnDoe@unix~/myProject $ mkdir build; cd build
       ```

    2. Next, invoke cmake

       ```zsh
        JohnDoe@unix:~/myProject/build $ cmake -DCMAKE_BUILD_TYPE=Debug<or Release> .. 
       ```

    3. And then, build the project using the generated makefile

       ```zsh
        JohnDoe@unix:~/myProject/build $ make 
       ```

    4. Optionally,

       ```zsh
        JohnDoe@unix:~/myProject/build $ make run
       ```

       will execute the program and save the output files to `myProject/run` folder.

5. The run file, `foo`, will be placed in `myProject/bin/Debug` (or in
   `myProject/bin/Release`), depending upon the build type specified at step **4.2**
   above.

6. To clean the project: from the same directory type,

      ```zsh
        JohnDoe@unix:~/myProject/build $ make clean
       ```

### Instructions for Windows

After setting the project's run file (see point **1** of the instructions for
Linux in the preceeding section), you can use `CMake-gui` to generate the
Makefile form that `CMakeLists.txt`. More information at
[CMake.org](https://cmake.org)

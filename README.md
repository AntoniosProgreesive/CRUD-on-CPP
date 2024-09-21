This is a CRUD (Create, Read, Update, Delete) system in C++ language, where records are stored in a file on disk.

_______________________________________________________________________________________

Installation and Development Environment
  Install C++ Compiler:

    Linux: Install g++ with the command:
      bash

      Code:
        sudo apt-get install g++


    Windows: Use MinGW or install Visual Studio that includes the C++ compiler.


    MacOS: Install Xcode via the App Store or only command line tools with the command:
      bash

      Code:
        xcode-select --install


IDE option:
  You can use an IDE such as Visual Studio Code, CLion, or Code::Blocks to write and run your code.

    Project Objectives:
      We will create a program that can:
          Add a new record.
          Read (Show/Search) a specific record.
          Edit an existing record.
          Delete a record.
          List of all records.


    Structure of the Record:
      Let's say we want to manage Customer information with the following fields:
          ID: A unique identification number (int)
          Name: The name of the client (string)
          Age: The age of the client (int)

Implementation of the Programme

_______________________________________________________________

Inclusion and Editorial:
Use the file: main.cpp.

In the terminal, go to the folder where the file is located and run:
  bash

  Code:
    g++ crud.cpp -o crud
    

Execution:
  After writing, run the program:
    bash
    
    Code:
      ./crud
      

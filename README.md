## pipex
42 project: Recreate the UNIX behavior of piping commands using system calls (pipe, fork, dup2, execve, etc.)

##  Project Description
The goal of pipex is to create a program that reproduces the behavior of shell piping:  

    - It takes an input file.

    - Executes cmd1 using the contents of the input file.

    - Pipes the output of cmd1 into cmd2.

    - Writes the final output to an output file.

##  Mandatory Objectives

        ./pipex file1 cmd1 cmd2 file2

Meaning:

        - Open file1 for reading.

        - Execute cmd1, reading from file1.

        - Pipe cmd1 output into cmd2.

        - Execute cmd2.

        - Write cmd2 output into file2.

## Bonus Part

    • Handle multiple pipes.
            $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

        should behave like:
            < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

    • Support « and » when the first parameter is "here_doc".
            $> ./pipex here_doc LIMITER cmd cmd1 file

        should behave like:
            cmd << LIMITER | cmd1 >> file


## How to use

1. Compile:

            make

    for bonus:


            make bonus

2. Run

            ./pipex file1 "cmd1" "cmd2" file2

    Bonus:  

            ./pipex file1 "cmd1" ... "cmdn" file2


# repository
## Interpreter
In this repo, you will find a C++ brainfuck interpreter (brainfuck.cpp). to use it, compile with any C++ compiler(I used C++20) and calling the brainfuck.exe will load the file brainfuck.code in the same folder. Otherwise, you can specify it:
./brainfuck.exe test.code

## Brainfuck Program
The little brainfuck program I did (brainfuck.code) is a simple program where you enter a letter and it returns the ASCII value. Does not work for special letters beyond 127 (UTF-8 or else) only ASCII.



# debug feature
I included a little debug feature in the interpreter, eventually, it will be a toggleable option in

writing debughere in the code will show the debug and ask to continue the execution or quit the program.



# code convention

## Indentation
I tried to Indent all the loops (unless they were in a known function, see the lasts if statements called) So It's easy to understant, sometimes I would indent only for comments, so I know what the comment refers to.

## comments
throughout my code, trying to make it as readable as possible, I wrote a lot of comments and //index specifies the index on the tape we should be at.

## functions
in seperate file, I have some pieces of code to "act" as fonction, in the copy-paste way, were ifstatement.code contains some brainfuck code that act as a if-else statement. To use it, I copy pasted it in my main code. where there were "variables": x and y in that case, I replaced with the values I wanted to use.
for example:
\+ x times, meant in my code if I wanted x to be 5, I would do +++++.

in those functions, you need to make sure, you are in a spot where it is a cell containing 0 (unless you optimized like I did with the if statement) and everything to the right is also containing 0.
that way, if a function needs a local variable, it should be at the beginning so if it calls another function, it will just move to the right, that's why my global variables are at the beginning of the program.

## file extension
I wrote my files with a .code extension, but it is meaningless, you could choose any or none. I did this to organise my files.

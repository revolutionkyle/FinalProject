# FinalProject: Cryptography Hangman
Capstone programming project for CSCI111.

## Input/Output
In [main.cpp lines 45,57,65,71,95-96](/main.cpp) I used input and output to the screen to ask the user for appropriate input crucial to playing a hangman style guessing game. The output to the screen is very basic but gets all needed information to and from the user. 
## Control Flow
In [main.cpp lines 32-39,83-90,100-112,122-134](/main.cpp) I used many important if and else if statements to build off of all possible user inputs, like whether they want easy mode, or hard mode and deciding how many tries they should get, or which file should the words encrypted, be drawn from.
## Iteration
In [main.cpp lines 46-72,52-58,98-114,124-128,](/main.cpp) and in [encrypt.cpp lines 6-9](encrypt.cpp) I used all 3 main types of loops. I used a while loop for the whole game to ask the user if they would want to play again, and also used it for the number of tries a person got. I used for loops to loop through my random string, to encrypt the word that is seen when playing the game.
## Data Structures
In [main.cpp lines 52-62](/main.cpp) and [encrypt.cpp line 5](/encrypt.cpp) I use vectors of charachters to loop through and store the shifted letter that is outupt to the screen. I ultimately use these just as a letter storage system to loop through and keep track of what is happening to each letter as I am encrypting it.
## Function
in [main.cpp lines 12-16,78-158](/main.cpp) and [encrypt.cpp lines 4-11](/encrypt.cpp) I have 6 functions, 5 in int main and 1 in my encrypt class I made. These functions have a mixed range of return types like void, bool, std::string, and std::vector<char>. I use mostly pass by value but in the function numtries, which sets the number of attempts the user gets, I pass by reference an integer that becomes my comparison for my loop that gets the users attempt.
## FileIO
In [main.cpp lines 116-136](/main.cpp) I use my function getword, whose only purpose is to deal with FileIO which reads in words from text files that I made and uses a randomly generated number to decide which line to draw from. Also in [main.cpp lines 17-18](/main.cpp) The sizes of these files is set so any new words the user would like to add on their own branch, only need to change either of those 2 numbers.
## Class
in [encrypt.h lines 6-14](/encrypt.h) I create an encryption class with 1 variable and 1 function. This is a very basic class whose purpose is to encrypt a given string. This is the most important function in my program so it deserved it's own class. The implementation of the class comes in [main.cpp line 42](/main.cpp) with the use of the encryptword function.

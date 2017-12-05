//Author: Kyle Hammer
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"encrypt.h"

bool playagain();
std::string getword(int,std::string);
std::string difficulty();
encrypt encryptedword;
bool testequivalence(char,char);
void numtries(std::string, int&);
const int EASYMODESIZE = 67;
const int HARDMODESIZE = 19; //subject to change sizes of the files to draw the encryption from.
int main()
{ std::string word;
  std::vector<char> tempword;
  std::string newword;
  int tries;
  do{ 
  std::srand( time(NULL) );
  int randomNumber;
  randomNumber = std::rand() % 26;
  int randomNumber2 = std::rand();  
  std::string diff = difficulty();
  numtries(diff,tries);

  if(diff == "easy.txt")
  {
    randomNumber2 = randomNumber2 % EASYMODESIZE;
  }
  if(diff == "hard.txt")
  {
    randomNumber2 = randomNumber2 % HARDMODESIZE;
  }
  
  word = getword(randomNumber2,diff);
  tempword = encryptedword.encryptword(word,randomNumber);
  std::string newword(tempword.begin(),tempword.end());
  int iterator=0;
  std::cout<<newword<<std::endl;
  while(iterator<tries)
  { std::string attempt;
    std::cout<<"What do you think this word is?"<<std::endl;
    std::cin>>attempt;
    if(attempt!=word)
    {
    for(int i=0; i<word.length();i++)
    {
        bool encrypt = testequivalence(attempt[i],word[i]);
        if(encrypt == true)
        {
            std::cout<<attempt[i]<<" was a correct decryption for " <<newword[i] <<"." <<std::endl;
        }

    }
    iterator++;
    }
    if(attempt == word)
    {
    std::cout<<"Congratulations you decrypted " << newword << " as " << word << std::endl;
    break;
    }
  }
  if(iterator==tries)
  {
    std::cout<< "DOH! your word was " << word << std::endl;
  }
  
  }while(playagain());

return 0;
}
bool playagain()
{ char input;
  std::cout << "Do you wish to play again? Y/N" << std::endl;
  std::cin >> input;

  if(input =='y'||input=='Y')
  {
    return true;
  }
  else
  {
    return false;
  }
}
std::string difficulty()
{ char diff;
  char restart;
    std::cout<<"Would you like to play easy or hard mode?(E-Easy and you get 7 tries ,H-Hard and you get 5 tries)" << std::endl;
    std::cin>>diff;
    restart = 'Y';
    while(restart=='Y')
    {   
        if(diff=='E'||diff=='e')
        {
            return "easy.txt";
        }
        else if(diff=='H'||diff=='h')
        {
            return "hard.txt";
        }
        else
        {
            std::cout<< "That isn't a valid answer!" << std::endl;
            restart = 'Y';
        }
    }

}
std::string getword(int a,std::string filename)
{ std::fstream file;
  file.open(filename.c_str());
  std::string word;
  std::string retry;
  std::string line;
  if(file.is_open())
  { 
    for(int i=0;i<a;i++)
    { 
        getline(file,word);

    }
    return word;
  }
  else
  {
   return "ISAIDTOGIVEMEAVALIDFILE";
  }
  file.close();  
}
bool testequivalence(char a, char b)
{
    if(a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void numtries(std::string word,int& a)
{
    if(word=="easy.txt")
    {
        a=7;
    }
    if(word=="hard.txt")
    {
        a=5;
    }
}

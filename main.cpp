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
std::string difficulty(int&);
encrypt encryptedword;

const int EASYMODESIZE = 67;
const int HARDMODESIZE = 19; //subject to change sizes of the files to draw the encryption from.
int main()
{ std::string word;
  std::vector<char> tempword;
  std::string newword;
  int numtries;
  do{ 
  std::srand( time(NULL) );
  int randomNumber;
  randomNumber = std::rand() % 26;
  int randomNumber2 = std::rand();  
  std::string diff = difficulty(numtries);

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
  std::cout<<newword<<std::endl;
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
std::string difficulty(int& a)
{ char diff;
  char restart;
    std::cout<<"Would you like to play easy or hard mode?(E-Easy and you get 5 tries ,H-Hard and you get 3 tries)" << std::endl;
    std::cin>>diff;
    restart = 'Y';
    while(restart=='Y')
    {   
        if(diff=='E'||diff=='e')
        {
            return "easy.txt";
            a=5;
        }
        else if(diff=='H'||diff=='h')
        {
            return "hard.txt";
            a=3;
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

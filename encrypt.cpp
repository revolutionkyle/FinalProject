#include"encrypt.h"


std::vector<char> encrypt::encryptword(std::string word, int a)
{ std::vector<char> encrypt;
  for(int i=0;i<word.size();i++)
  {
    encrypt.push_back(char(((int(word[i])+a)% 26) +97));
  }
  return encrypt;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

void ParseOneFile(std::ifstream * );
bool isWordWrong(std::string *);


const char LOWER_VOWELS[] = {"aeiou.,"};
const char BIG_VOWELS[]   = {"AEIOU.,"};



// ------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  std::ifstream fsBuf;;
  
  // first check to have some input passed to argv
  if (argc < 2)
    {
      // tell user to add a filename
      std::cout << "You must enter name and address of file" << std::endl;
    }
  else
    {
      // we have some files to search for mistakes
      argv++; // fisrt argument is name of program
      for (int index{1} ; index < argc ; index++ , argv++)
	{
	  // try to open file
	  fsBuf.open(*argv);
	  if ( fsBuf.is_open() )
	    {
	      // opening file was successful
	      std::cout << "success on opening file " << *argv << ". searching..." << std::endl;
	      // search for mistakes and print them
	      ParseOneFile(&fsBuf);
	      // close the file
	      fsBuf.close();
	    }
	  else // file didnt open
	    std::cout << "error opening file " << *argv << std::endl;
	}
    }
  

  // say goodbye
  std::cout << "End of typo check program\nTehran, EE, AUT ;)) " << std::endl;
  return 0;
}
// End of main ----------------------------------------------------------------------------------


// check one word for mistake
bool isWordWrong(std::string *word)
{
  int lowerUndesigred{0};

  // for every charachter in word
  for (char x: *word)
    {
      lowerUndesigred   = ( !strchr(LOWER_VOWELS,x)  ) ? lowerUndesigred+1   :  0 ;
            
      if (lowerUndesigred >= 5)
	return true;
    }
  
  
  return false;
}



// get all words in a file and check them one by one
void ParseOneFile(std::ifstream * fsptrInput)
{
  std::string buf; // to transfer each word

  // while End Of File
  while ( ! fsptrInput->eof() ) 
    {
      *fsptrInput >> buf; // read file
      // check:
      if (isWordWrong(&buf)) // the word has a problem : consists of 5 non-lower-vowel 
	std::cout << buf << "#" << std::endl;
    }
}

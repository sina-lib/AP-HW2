#include <iostream>
#include <string>
#include <fstream>
//#include <>

bool get_numbers_from_user(double *array, int *length);
void do_selection_sort_on_array(double *array, int length);
void delete_my_dynamic_array(double *array, int length);
double extractNumberFromString(std::string );

int main()
{
  std::cout << "start of selection sort program" << std::endl;

  double *myArray;
  int arrayLength{0};
  
  get_numbers_from_user(myArray, &arrayLength);

  delete_my_dynamic_array(myArray, arrayLength);
  
  std::cout << "end of selection sort program.\nTehran, EE, AUT ;)" << std::endl;
  return 0;
}


double extractNumberFromString(std::string str)
{
  double k{0},sign{1.0};
  int i{0},pointPlace{0};
  for (auto ch : str)
    {
      	  switch (ch)
	    {
	    case '-':
	      sign = -1.0;
	      break;
	    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
	      k = (k * 10.0) + static_cast<double>( ch - '0' );
	      //cout << "s = " << ch;
	      i++;
	      break;
	    case '.':
	      pointPlace = i-1;
	      break;
	    default:
	      break;
	    };
    };
  
  while (pointPlace--)
    k /= 10.0;
  return k*sign;
}


// Get numbers from user untill zero
bool get_numbers_from_user(double *array, int *length)
{
  // create a file
  std::ofstream myFile{"cache.txt"};
  if (!myFile) // check creation of file
    {
      std::cout << "problem with file" << std::endl; 
      return false;
    }


  // get numbers one by one 
  bool exitStatus{false};
  double a;
  int index{0};
  std::string str;
    do
    {
      std::cin >> a;
      if (a == 0)
	exitStatus = true;
      else
	{
	  myFile << a << '\n';
	}
    } while ( exitStatus == false) ;
    myFile.close();
    // coppy length
    *length = index;
    
    // read and put all numbers to an array
    std::ifstream readBack{"cache.txt"};
    if (!readBack) // check creation of file
    {
      std::cout << "problem with file" << std::endl; 
      return false;
    }
    else
      {
	// we have a corect file
	array = new double[index];

	// make a poimter to start of it
	double *ptrArr{array};

	// transfer numbers from file to array
	std::string str;
	do
	  {
	    std::getline(readBack, str, '\n');
	    std::cout << "reading > " << str << "." << std::endl;
	    *ptrArr++ = extractNumberFromString(str);
	  } while (!readBack.eof());
      }
    
    return true;
}

void do_selection_sort_on_array(double *array, int length)
{
}

void delete_my_dynamic_array(double *array, int length)
{
  delete []array;
}

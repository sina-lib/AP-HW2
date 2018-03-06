#include <iostream>
#include "Queue.h"
#include <stdlib.h>

using std::cout;
using std::endl;


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


Queue::Queue()
{
  cout << "There is no address to initiallize the queue." << endl;;
  isQueueInitiallized = false;
}

Queue::Queue(std::string cFileName)
{
  cout << "initiallizer file name : " << cFileName << endl;
  // try to open and load values from file
  fsInitList.open(cFileName);
  if (!fsInitList.is_open())
    {
      // there was an error with file
      cout << "Error opening file." << endl;
      isQueueInitiallized = false; // to keep track of beeing un-initiallized
    } // end of init without file
  else
    {
      // found a file
      cout << "successfully opened intiallizer file " << endl;

      // read length of list
      fsInitList >> queueLength;
      cout << "Queue length specified in file is " << queueLength << endl;

      // create an array 
      elements = new double[queueLength];

      // coppy all existing values from file to list
      double *vals{elements};
      std::string a;
      int elementIndex{1};
      do
	{
	  // read the value
	  std::getline(fsInitList, a, ',');
	  // transfer to array
	  *(vals++) = extractNumberFromString(a);
	  elementIndex++;
	} while (  (fsInitList.eof()==false) && (elementIndex <= queueLength)  );
      isQueueFull = false;
      writeAddress = elementIndex;
      readAddress = 0;
      
      isQueueInitiallized = true; // keep the state of beeing initialled
    } // end of init with file
}


void Queue::displayQueue(void)
{
  if ( ((writeAddress-1) == readAddress) && (!isQueueFull) )
    {
      cout << "queue is empty" << endl;
    }
  else if (isQueueInitiallized == false)
    {
      cout << "No queue has initiallized." << endl;
    }
  else
    {
      // show queue values by order

      // display length of list
      cout << "Max queue length = " << queueLength << endl;

		   
      // display values
      int index{readAddress};
      int endOfIndex{ (writeAddress == 0) ? readAddress : writeAddress-1 };
      int k{0};
      const double * pElements{elements}; 
      do
	{
	  cout << k++ + 1 << ">  " << *(pElements + index ) << endl;
	  index = ( index == (queueLength-1) ) ? 0 : index+1; 
	} while (index != endOfIndex );
    }
}


/*
   writeAdd -> points to an empty place of list ;  if 0 -> means full
   readAdd -> points to exactly First putted of list ; 
  
 */
bool Queue::enQueue(double inputValue)
{
  if (isQueueFull == true)
    {
      // queue is full
      cout << "Queue is full , cant get the number" << inputValue << endl;
    }
  else if (isQueueInitiallized == true)
    {
      // queue has empty place to add

      // coppy new value
      *( elements + writeAddress - 1) = inputValue;

      // creat new write address
      writeAddress = (writeAddress == queueLength) ? 1 : writeAddress+1 ;

      // check full or not ?
      if  ( (readAddress+1) == writeAddress)
	{
	  // list is full
	  isQueueFull = true;
	  writeAddress = 0;
	}
      // tell user enQueue was successfull
      cout << "succeed to add " << inputValue << " to queue." << endl;
      
      return true;
    }
  else
    {
      // queue is not initiallized
      cout << "queue has not initiallized" << endl;
    }

  
  return false;
}

double Queue::deQueue(void)
{
  if (  ((writeAddress-1) == readAddress) && (!isQueueFull) )
    {
      cout << "deQueue while its empty" << endl;
    }
  else
    {
      double res{0};

      // read the value
      res = *(elements + readAddress);
      
      // calculate next reading address
      if (isQueueFull == true)
	{
	  isQueueFull = false;
	  writeAddress = readAddress + 1;
	}
      // check for empty case
      readAddress = (readAddress == (queueLength-1) ? 0 : readAddress+1);
      return res;
    }
  return 0;
}



#include <iostream>
#include "Queue.h"


int main()
{
  std::cout << "Start of question3 main " << std::endl;
  
  Queue q{"Queue.txt"};

  // Display elements in queue
  q.displayQueue();

  // Inserting elements in Circular Queue
  q.enQueue(15.5);
  q.enQueue(-6);

  q.enQueue(70.07);
  
  q.displayQueue();

  q.enQueue(10);
  q.enQueue(34.3434);
  // deleting elements from circular queue
  std::cout << "Deleted value = " << q.deQueue() << std::endl ;
  std::cout << "Deleted value = " << q.deQueue() << std::endl ;

  q.displayQueue();


  q.enQueue(33.33);
  q.displayQueue();
  q.enQueue(4.04);
  q.enQueue(5.0);
  q.displayQueue();

  for (int a{8}; a>0 ; a--)
    {
      std::cout << "deleting " << q.deQueue() << std::endl;
    }

  q.enQueue(8);
  q.enQueue(90);
  q.displayQueue();
  q.deQueue();
  q.displayQueue();
  
  std::cout << "End of question3 main \nTehran, EE, AUT ;) " << std::endl;
  return 0;
}

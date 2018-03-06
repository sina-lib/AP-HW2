#include <fstream>
#include <string>

class Queue
{
 public:
  // create queue
  Queue();
  Queue(std::string cFileName );
  // show
  void   displayQueue(void);
  // manipulate queue
  bool   enQueue(double );
  double deQueue(void );
 private:
  std::ifstream  fsInitList;
  double         *elements;
  int            queueLength;
  // flags:
  bool  isQueueInitiallized;
  bool  isQueueFull;
  // addresses
  int writeAddress;
  int readAddress;
};

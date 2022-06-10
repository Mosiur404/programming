#include <iostream>
#include <queue>
using namespace std;

struct Process {
  int index;
  int arrivalTime;
  int burstTime;
  int startTime;
  int completionTime;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  int waitingTime() { return this->startTime - this->arrivalTime; };
};

class Scheduler {
private:
  queue<Process> processQueue;
  queue<Process> terminatedQueue;
  unsigned int totalCT, totalTAT, totalWT, totalIdle, counter;

public:
  Scheduler *enqueue(Process prc) {
    this->processQueue.push(prc);
    return this;
  }
  void init() {
    int prevCompletionTime = 0;
    while (!processQueue.empty()) {
      Process *prc = &processQueue.front();

      prc->startTime = prevCompletionTime > prc->arrivalTime
                           ? prevCompletionTime
                           : prc->arrivalTime;
      prc->completionTime = prc->startTime + prc->burstTime;

      // extra
      this->totalCT += prc->completionTime;
      this->totalTAT += prc->turnArroundTime();
      this->totalWT += prc->waitingTime();
      this->totalIdle += prevCompletionTime < prc->arrivalTime
                             ? prc->arrivalTime - prevCompletionTime
                             : 0;
      prevCompletionTime = prc->completionTime;

      processQueue.pop();
      terminatedQueue.push(*prc);
      counter++;
    }
  }
  // extra
  void print() {
    cout << "ID\tArrival\tBurst\tStart\tCompletion\tTAT\tWaiting" << endl;
    while (!this->terminatedQueue.empty()) {
      Process *prc = &terminatedQueue.front();

      cout << "P" << prc->index << '\t' << prc->arrivalTime << '\t'
           << prc->burstTime << '\t' << prc->startTime << '\t'
           << prc->completionTime << "\t\t" << prc->turnArroundTime() << '\t'
           << prc->waitingTime();
      terminatedQueue.pop();
      cout << endl;
    }
    cout << "Total Completion Time: " << this->totalCT << endl;
    cout << "Total Turn Arround Time: " << this->totalTAT << endl;
    cout << "Total Waiting Time: " << this->totalWT << endl;
    cout << "Total Idle Time: " << this->totalIdle << endl;
    cout << "Average Completion Time: " << (float)this->totalCT / this->counter
         << endl;
    cout << "Average Turn Arround Time: "
         << (float)this->totalTAT / this->counter << endl;
    cout << "Average Waiting Time: " << (float)this->totalWT / this->counter
         << endl;
  }

  Scheduler() {
    this->totalCT = 0, this->totalTAT = 0, this->totalWT = 0, this->counter = 0,
    this->totalIdle = 0;
  }
  ~Scheduler() {}
};

int main(int argc, char const *argv[]) {
  Scheduler *fcfs = new Scheduler();

  fcfs->enqueue({1, 0, 2})->enqueue({2, 1, 2});
  fcfs->enqueue({3, 5, 3})->enqueue({4, 6, 4});

  fcfs->init();

  fcfs->print();

  return 0;
}

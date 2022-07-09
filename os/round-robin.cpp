#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Process {
  int index, arrivalTime, burstTime, startTime, completionTime;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  int waitingTime() { return this->startTime - this->arrivalTime; };
};

class Scheduler {
private:
  queue<Process> processQueue;
  queue<Process> readyQueue;
  queue<Process> terminatedQueue;
  unsigned int timeQuantum;
  unsigned int totalCT, totalTAT, totalWT, totalIdle, counter, duration;

public:
  Scheduler *enqueue(Process prc) {
    this->processQueue.push(prc);
    return this;
  }
  Scheduler *init() {
    int prevCompletionTime = 0;
    this->duration = 0;
    while (!processQueue.empty() || !readyQueue.empty()) {
      // cout << "duration " << this->duration << ' ';
      this->checkProcessQueue();
      if (!readyQueue.empty()) {
        Process *prc = &readyQueue.front();

        this->duration += this->min(this->timeQuantum, prc->burstTime);
        readyQueue.pop();
        prc->burstTime = prc->burstTime - this->timeQuantum;

        if (prc->burstTime <= 0)
          this->terminatedQueue.push(*prc);
        else {
          this->checkProcessQueue();
          this->readyQueue.push(*prc);
        }

        cout << 'p' << prc->index << ' ';
      }
    }
    return this;
  }

  Scheduler *checkProcessQueue() {
    while (!processQueue.empty() &&
           processQueue.front().arrivalTime <= this->duration) {
      Process *prc = &processQueue.front();
      processQueue.pop();
      this->readyQueue.push(*prc);
    }
    return this;
  }
  // extra
  int min(int a, int b) { return a > b ? b : a; }
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
    cout << "Average Completion Time: " << (float)this->totalCT / this->counter
         << endl;
    cout << "Average Turn Arround Time: "
         << (float)this->totalTAT / this->counter << endl;
    cout << "Average Waiting Time: " << (float)this->totalWT / this->counter
         << endl;
  }
  Scheduler(int tq = 2) {
    this->timeQuantum = tq;
    this->totalCT = 0, this->totalTAT = 0, this->totalWT = 0, this->counter = 0;
  }
  ~Scheduler() {}
};

int main(int argc, char const *argv[]) {
  Scheduler *roundRobin = new Scheduler(4);
  roundRobin->enqueue({1, 0, 8})->enqueue({2, 1, 6});
  roundRobin->enqueue({3, 3, 3})->enqueue({4, 5, 2});
  roundRobin->enqueue({5, 6, 4});
  roundRobin->init();
  // roundRobin->print();
  return 0;
}
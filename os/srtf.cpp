#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
  int index, arrivalTime, burstTime, remainingBurstTime;
  int startTime = -1, completionTime, lastST = 0, waitingTime = 0;
  int turnArroundTime() { return this->completionTime - this->arrivalTime; };
  Process() {}
  Process(int x, int y, int z)
      : index(x), arrivalTime(y), burstTime(z), remainingBurstTime(z) {}
};

class Compare {
public:
  bool operator()(const Process &p1, const Process &p2) {
    if (p2.remainingBurstTime == p1.remainingBurstTime)
      return p2.arrivalTime < p1.arrivalTime;
    return p2.remainingBurstTime < p1.remainingBurstTime;
  }
};

class Scheduler {
private:
  queue<Process> processQueue;
  priority_queue<Process, vector<Process>, Compare> readyQueue;
  queue<Process> terminatedQueue;
  vector<int> timestamps; // extra
  vector<int> history;    // extra
  unsigned int totalCT, totalTAT, totalWT, totalIdle, counter;
  unsigned int duration = 0;

public:
  Scheduler *enqueue(Process prc) {
    this->processQueue.push(prc);
    return this;
  }

  void init() {
    while (!processQueue.empty() || !this->readyQueue.empty()) {
      this->checkProcessQueue(); // fill the readyQueue initially
      this->handleIdle();
      while (!this->readyQueue.empty()) {
        Process prc = readyQueue.top();
        readyQueue.pop();

        /*  calc start */

        if (prc.startTime == -1) {        // if process is new
          prc.startTime = this->duration; // set start time
          prc.waitingTime += prc.startTime - prc.arrivalTime; // waiting time
        }
        prc.lastST = this->duration; // last start counter(for waiting)

        // after the inital start of process
        if (prc.remainingBurstTime != prc.burstTime)
          prc.waitingTime += prc.lastST - prc.completionTime; // calc waiting

        /* calc end */

        // loop until we find a process with less remaining time
        while (prc.remainingBurstTime > 0) {
          if (!readyQueue.empty() &&
              prc.remainingBurstTime > readyQueue.top().remainingBurstTime)
            break;

          prc.remainingBurstTime--;  // decrease burst time
          this->duration++;          // increase clock time
          this->checkProcessQueue(); // check and update ready queue
        }
        prc.completionTime = this->duration; // update completion time

        if (prc.remainingBurstTime <= 0) {
          this->counter++;
          this->terminatedQueue.push(prc);
        } else
          this->checkProcessQueue()->readyQueue.push(prc);

        // extra
        this->setTimestamp(prc); // gantt chart

        this->totalCT += prc.completionTime;
        this->totalTAT += prc.turnArroundTime();
        this->totalWT += prc.waitingTime;
      }
    }
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

  Scheduler *handleIdle() {
    if (readyQueue.empty()) {
      int dt = processQueue.front().arrivalTime - this->duration;
      this->totalIdle += dt;
      this->duration += dt;
    }
    return this;
  }
  // extra
  void setTimestamp(Process &prc) {
    this->history.push_back(prc.index);
    this->timestamps.push_back(this->duration);
  }

  int min(int a, int b) { return a < b ? a : b; }

  void print() {
    cout << "Gantt Chart: " << endl;
    for (int index : this->history)
      cout << "|  " << 'P' << index << "   ";
    cout << '|' << endl;
    for (int timestamp : this->timestamps)
      cout << timestamp << '\t';
    cout << endl << endl;

    cout << "ID\tArrival\tBurst\tStart\tCompletion\tTAT\tWaiting" << endl;
    while (!this->terminatedQueue.empty()) {
      Process *prc = &terminatedQueue.front();

      cout << "P" << prc->index << '\t' << prc->arrivalTime << '\t'
           << prc->burstTime << '\t' << prc->startTime << '\t'
           << prc->completionTime << "\t\t" << prc->turnArroundTime() << '\t'
           << prc->waitingTime;
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
    this->totalCT = this->totalTAT = this->totalWT = this->counter =
        this->totalIdle = this->duration = 0;

    timestamps.push_back(0); // intial 0
  }
  ~Scheduler() {}
};

int main(int argc, char const *argv[]) {
  Scheduler *srtf = new Scheduler();
  srtf->enqueue({1, 0, 7})->enqueue({2, 2, 4});
  srtf->enqueue({5, 3, 5})->enqueue({3, 4, 1});
  srtf->enqueue({4, 5, 4})->enqueue({6, 25, 2});
  srtf->init();
  srtf->print();
  return 0;
}
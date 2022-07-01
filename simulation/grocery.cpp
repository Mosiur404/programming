#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Customer {
  unsigned int id;
  unsigned int randomNumber;
  unsigned int iAt;
  unsigned int arrivalTime;
  unsigned int randomNumberForServiceTime;
  unsigned int serviceTime;
  unsigned int timeServiceBegins;
  unsigned int waitingTime;
  unsigned int timeServiceEnds;
  unsigned int timeSpentInSystem;
  unsigned int idleTimeForServer;
};

class Solution {
private:
  unsigned int totalInterArrivalTime = 0;
  unsigned int totalArrivalTime = 0;
  unsigned int totalServiceTime = 0;
  unsigned int totalWaitingTime = 0;
  unsigned int totalIdleTime = 0;
  unsigned int totalSpendTimeInSystem = 0;
  unsigned int totalCustomerWait = 0;
  unsigned int totalRunTime = 0;
  int numeberOfCustomers;
  Customer *customers;

public:
  Solution *startSimulating() {
    unsigned int seed = time(0);
    srand(seed);
    unsigned int prevAT = 0, prevTSE = 0;
    for (unsigned int i = 0; i < this->numeberOfCustomers; i++) {
      Customer *current = &this->customers[i];
      current->id = i + 1;
      if (i == 0) {
        // Random digit
        current->randomNumber = 0;
        // Inter Arrival Time
        current->iAt = 0;
      } else {
        current->randomNumber = rand() % 1000 + 1;
        current->iAt = this->generateIAT(current->randomNumber);
      }
      // Random digit for service
      current->randomNumberForServiceTime = rand() % 100 + 1;
      // Arrival Time
      current->arrivalTime = prevAT + current->iAt;
      // Service time
      current->serviceTime =
          this->generateServiceTime(current->randomNumberForServiceTime);
      // Time Service begins (check which one is greater, previous one end or
      // current arrival)
      current->timeServiceBegins = this->max(prevTSE, current->arrivalTime);
      // Waiting time
      current->waitingTime =
          prevTSE > current->arrivalTime ? 0 : current->arrivalTime - prevTSE;
      // Time service end
      current->timeServiceEnds =
          current->timeServiceBegins + current->serviceTime;
      // Time Spent in system
      current->timeSpentInSystem =
          current->timeServiceEnds - current->arrivalTime;
      // Idle Time
      current->idleTimeForServer =
          prevTSE > current->arrivalTime ? 0 : current->arrivalTime - prevTSE;
      // Total
      this->totalInterArrivalTime += current->iAt;
      this->totalArrivalTime += current->arrivalTime;
      this->totalServiceTime += current->serviceTime;
      this->totalWaitingTime += current->waitingTime;
      this->totalSpendTimeInSystem += current->timeSpentInSystem;
      this->totalIdleTime += current->idleTimeForServer;
      if (current->waitingTime) this->totalCustomerWait++;
      this->totalRunTime = current->timeServiceEnds;
      // extra
      prevAT = current->arrivalTime;
      prevTSE = current->timeServiceEnds;
    }
    return this;
  }

  int max(unsigned int a, unsigned int b) { return a > b ? a : b; }

  int generateIAT(int num) {
    if (num >= 0 && num <= 125)
      return 1;
    else if (num >= 126 && num <= 250)
      return 2;
    else if (num >= 251 && num <= 375)
      return 3;
    else if (num >= 376 && num <= 500)
      return 4;
    else if (num >= 501 && num <= 625)
      return 5;
    else if (num >= 626 && num <= 750)
      return 6;
    else if (num >= 751 && num <= 875)
      return 7;
    else if (num >= 876 && num <= 1000)
      return 8;
    return 0;
  }

  int generateServiceTime(unsigned int num) {
    if (num >= 0 && num <= 25)
      return 1;
    else if (num >= 26 && num <= 30)
      return 2;
    else if (num >= 31 && num <= 60)
      return 3;
    else if (num >= 61 && num <= 75)
      return 4;
    else if (num >= 76 && num <= 95)
      return 5;
    else if (num >= 96 && num <= 100)
      return 6;
    return 0;
  }
  // extra
  void print() {
    cout << "ID\tRD1\tIAT\tArrival\tRD2\tService\tTSB\tWaiting\tTSE\tTSS\tITS";
    cout << endl;
    for (int i = 0; i < this->numeberOfCustomers; i++) {
      cout << customers[i].id << '\t' << customers[i].randomNumber << '\t';
      cout << customers[i].iAt << '\t' << customers[i].arrivalTime << '\t';
      cout << customers[i].randomNumberForServiceTime << '\t';
      cout << customers[i].serviceTime << '\t';
      cout << customers[i].timeServiceBegins << '\t';
      cout << customers[i].waitingTime << '\t';
      cout << customers[i].timeServiceEnds << '\t';
      cout << customers[i].timeSpentInSystem << '\t';
      cout << customers[i].idleTimeForServer << endl;
    }
    cout.precision(4);
    cout << "Total Inter Arrival Time: " << this->totalInterArrivalTime << endl;
    cout << "Total Arrival Time: " << this->totalArrivalTime << endl;
    cout << "Total Service Time: " << this->totalServiceTime << endl;
    cout << "Total Waiting Time: " << this->totalWaitingTime << endl;
    cout << "Total Spend Time in System: " << this->totalSpendTimeInSystem;
    cout << endl;
    cout << "Total Idle Time: " << this->totalIdleTime << endl;
    cout << "Total Customer in Wait Queue: " << this->totalCustomerWait << endl;
    cout << endl;
    if (!this->numeberOfCustomers) return;
    cout << "Average waiting time: ";
    cout << (float)this->totalWaitingTime / this->numeberOfCustomers << endl;
    cout << "Probablity customer has to wait in queue: ";
    cout << (float)this->totalCustomerWait / this->numeberOfCustomers * 100;
    cout << "%" << endl;
    cout << "Probablity of idle time: ";
    cout << (float)this->totalIdleTime / this->totalRunTime * 100 << "%";
    cout << endl;
    cout << "Average service time: ";
    cout << (float)this->totalServiceTime / this->numeberOfCustomers << endl;
    cout << "Average time between arrival: ";
    cout << (float)this->totalInterArrivalTime / this->numeberOfCustomers - 1;
    cout << endl;
    if (this->totalWaitingTime)
      cout << "Average waiting time for those who wait: ";
    cout << (float)this->totalWaitingTime / this->totalCustomerWait << endl;
    cout << "Average time customer spent in system: ";
    cout << (float)this->totalSpendTimeInSystem / this->numeberOfCustomers;
    cout << endl;
  }
  Solution(int n = 0) {
    this->numeberOfCustomers = n;
    this->customers = new Customer[this->numeberOfCustomers];
  }
  ~Solution() { delete[] this->customers; }
};
int main(int argc, char const *argv[]) {
  int n;
  cout << "Enter Customer Size: ";
  cin >> n;
  Solution *simulator = new Solution(n);
  simulator->startSimulating()->print();
  delete simulator;
  return 0;
}

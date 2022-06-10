#include <iostream>
using namespace std;
// shortest
int main() {
  int arrivalT[50];
  int BurstTime[50];
  int CompletionTime[50];
  int TurnAroundTime[50];
  int WaitingTime[50];
  int temp[50];
  int ProcessNO[50];
  int n;
  int av_CompletionTime = 0, av_TurnAroundTime = 0, av_WaitingTime = 0;
  //   cout << "Enter the number of Process : ";
  //   cin >> n;
  //   for (int i = 0; i < n; i++) {
  //     cout << "Arrival Time for no " << i + 1 << " Process : ";
  //     cin >> arrivalT[i]; // rd[i]=0 + (rand() % 1000);
  //     cout << "Burst Time for no " << i + 1 << " Process : ";
  //     cin >> BurstTime[i];
  //     ProcessNO[i] = i + 1;
  //   }
  n = 4, arrivalT[0] = 0, arrivalT[1] = 2, arrivalT[2] = 4, arrivalT[3] = 5,
  BurstTime[0] = 7, BurstTime[1] = 4, BurstTime[2] = 1, BurstTime[3] = 4;
  ProcessNO[0] = 1, ProcessNO[1] = 2, ProcessNO[2] = 3, ProcessNO[3] = 4;
  // sort
  for (int step = 1; step < n - 1; step++) {
    for (int i = 1; i < n - step - 1; i++) {
      if (BurstTime[i] > BurstTime[i + 1]) {
        swap(arrivalT[i], arrivalT[i + 1]);
        swap(BurstTime[i], BurstTime[i + 1]);
        swap(ProcessNO[i], ProcessNO[i + 1]);
      }
    }
  }

  cout << " Process  Arrival Time  Burst Time   Completion Time   Turn Around "
          "Time   Waiting Time\n";
  for (int j = 0; j < n; j++) {
    // Completion Time
    CompletionTime[j] = BurstTime[j] + CompletionTime[j - 1];
    CompletionTime[0] = BurstTime[0];
    // Turn Around Time
    TurnAroundTime[j] = CompletionTime[j] - arrivalT[j];
    // Waiting Time
    WaitingTime[j] = TurnAroundTime[j] - BurstTime[j];
    // cout << "\t\t" << ProcessNO[j] << "\t\t" << arrivalT[j] << "\t\t" <<
    // BurstTime[j] << "\t\t" << CompletionTime[j] << "\t\t" <<
    // TurnAroundTime[j] << "\t\t" << WaitingTime[j] << "\n";
  }
  // sort
  for (int step = 1; step < n - 1; step++) {
    for (int i = 1; i < n - step - 1; i++) {
      if (ProcessNO[i] > ProcessNO[i + 1]) {
        swap(ProcessNO[i], ProcessNO[i + 1]);
        swap(arrivalT[i], arrivalT[i + 1]);
        swap(BurstTime[i], BurstTime[i + 1]);
        swap(CompletionTime[i], CompletionTime[i + 1]);
        swap(TurnAroundTime[i], TurnAroundTime[i + 1]);
        swap(WaitingTime[i], WaitingTime[i + 1]);
      }
    }
  }

  for (int j = 0; j < n; j++) {
    cout << "" << ProcessNO[j] << "\t\t" << arrivalT[j] << "\t\t"
         << BurstTime[j] << "\t\t" << CompletionTime[j] << "\t\t"
         << TurnAroundTime[j] << "\t\t" << WaitingTime[j] << "\n";
  }

  for (int l = 0; l < n; l++) {
    av_CompletionTime = av_CompletionTime + CompletionTime[l];
    av_TurnAroundTime = av_TurnAroundTime + TurnAroundTime[l];
    av_WaitingTime = av_WaitingTime + WaitingTime[l];
  }
  cout << "\nAvarage Completion Time :" << (av_CompletionTime / n) << "\n";
  cout << "Avarage Turn Around Time :" << (av_TurnAroundTime / n) << "\n";
  cout << "Avarage Waiting Time :" << (av_WaitingTime / n) << "\n";
  return 0;
}
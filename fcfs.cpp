

/*
FCFS C++ Program

//Make outer do-while loop
//Make a loop that waits for processes to arive in case the list is empty.
//Make a linked list that holds the processes
//Impliment the list using a queue. It is a FIRST IN FIRST OUT data sturcture.
//Make an assignResource function that takes the element at the top of the list
//and sends it to cpu?

*/

//FCFS


/*

Input : process id, arrival time , burst time

Output : Wating time, Turnaround time,Throughput
*/

/*

Functions:

-Take input

-Calculate waiting time, turnaround time,throughput(at the end(throuthput = noOfProcesses/totalExecutionTime))


-Display : process id ,arrival time,burst time,Wating time,Turnaround time,Throughput

*/

/*
Calculating waiting time:

//Will need to keep tally of total time elapsed(totalTimeElapesd)

//Waiting time = totalTimeElapesd-arrivalTime
*/
#include <iostream>
#include <algorithm>




class Process
{
public:

    int processId;
    int arrivalTime;
    int burstTime;
    int watingTime;
    int turnaroundTime;
};

bool ValueCmp(Process const& a, Process const& b)
{
    return a.arrivalTime < b.arrivalTime;
}


int g_totalTimeElapesd{};
void WaitingTime(const int& numberOfProcesses, Process* listOfProcesses)
{
    for (int i{}; i < numberOfProcesses; ++i)
    {
        if (listOfProcesses[i].arrivalTime > g_totalTimeElapesd)
        {
            g_totalTimeElapesd = g_totalTimeElapesd + (g_totalTimeElapesd - listOfProcesses[i].arrivalTime);
        }
        listOfProcesses[i].watingTime = g_totalTimeElapesd - listOfProcesses[i].arrivalTime;
        g_totalTimeElapesd = g_totalTimeElapesd + listOfProcesses[i].burstTime;

    }
}

void turnArroundTime(const int& numberOfProcesses, Process* listOfProcesses)
{
    for (int i{}; i < numberOfProcesses; ++i)
    {
        listOfProcesses[i].turnaroundTime = listOfProcesses[i].burstTime + listOfProcesses[i].watingTime;
    }
}

void sortProcessesAccordingToArrivalTime(const int& numberOfProcesses, Process* listOfProcesses)
{
    std::sort(listOfProcesses, listOfProcesses + numberOfProcesses, ValueCmp);
}




/*
void takeInput(int& numberOfProcesses,int* processId,int* arrivalTime,int* burstTime)
{
    std::cout << "-------------------------------------\n";
    std::cout <<"Enter number of processes: ";
    std::cin >> numberOfProcesses;
    std::cout << "-------------------------------------\n";

    for(int i{};i < numberOfProcesses; ++i)
    {

        std::cout << "Enter process id, arrival time and burst time for process "<<(i + 1)<<" :";
        std::cin >> processId[i] >> arrivalTime[i] >> burstTime[i];
        //std::cout << processId << arrivalTime << burstTime;
    }

    std::cout << "-------------------------------------\n";
}*/

void takeInput(int& numberOfProcesses, Process* listOfProcesses)
{
    

    for (int i{}; i < numberOfProcesses; ++i)
    {
        std::cout << "Process " << i +1 <<" :\n";
        std::cout << "Enter process id :";
        std::cin >> listOfProcesses[i].processId;
        std::cout << "Enter arrival time :";
        std::cin >> listOfProcesses[i].arrivalTime;
        std::cout <<"Enter burst time :";
        std::cin >>  listOfProcesses[i].burstTime;
        //std::cout << processId << arrivalTime << burstTime;
    }

    std::cout << "-------------------------------------\n";
}

void displayOutput(int& numberOfProcesses, Process* listOfProcesses)
{
    std::cout << "\nOutput \n";
    int i{};
    while (i < numberOfProcesses)
    {
        std::cout << "Process with process id " << listOfProcesses[i].processId<< " :\n";
        std::cout << "Wating Time :" << listOfProcesses[i].watingTime << "\n";
        std::cout << "Turn around Time :" << listOfProcesses[i].turnaroundTime << "\n";
        ++i;
    }

}






int main()
{

    int numberOfProcesses{};

    std::cout << "-------------------------------------\n";
    std::cout << "Enter number of processes: ";
    std::cin >> numberOfProcesses;
    std::cout << "-------------------------------------\n";

    Process* listOfProcesses{ new Process[numberOfProcesses]{} };

    //takeInput(numberOfProcesses,processId,arrivalTime,burstTime);
    takeInput(numberOfProcesses, listOfProcesses);
    sortProcessesAccordingToArrivalTime(numberOfProcesses, listOfProcesses);
    WaitingTime(numberOfProcesses, listOfProcesses);
    turnArroundTime(numberOfProcesses, listOfProcesses);
    displayOutput(numberOfProcesses, listOfProcesses);
    return 0;
}
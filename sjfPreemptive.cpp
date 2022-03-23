
/*

Use a counter to count time ellapsed. After every increment check if another job has arived
IF yes check if premption needs to take place.
If yes prempt.That means save the ammount of time that has passed for the 
current process.Reduce it's burst time by the ammount of time that has passed in it's
execution.
sort the processes according to new burst times.
increment counter. Repeat process till all Processes have been completed.


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
    return a.burstTime < b.burstTime;
}


//int g_totalTimeElapesd{};
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

void copyBurstTime(int& numberOfProcesses, Process* listOfProcesses,int* OriginalBurstTime)
{
    int i{};
    while(i != numberOfProcesses)
    {
        OriginalBurstTime[i] =  listOfProcesses[i].burstTime;
        ++i;
    }
}
void findOutput(int& numberOfProcesses, Process* listOfProcesses)
{
    //burst times will be modified. So they need to be coppied into the array
    //Wating time = timer - OriginalBurstTime when burstTime == 0;
    //turnAroundTime = timer when burstTime == 0;

    //Run timer
    //Every run:
        //select processes with arrival time <= timer
        //sort these processes according to burstTime
        //decrement burstTime for process at top of list
        //If burstTime for current process ==0 calculate wating and turnArroundTime
        //Output If burst time == 0
        //increment a counter which keeps track of number of processes processed.
        //If counter == numberOfProceses stop execution.
    int counter{};
    int timer{};
    Process* activeProcesses;
    do
    {      
        //The copy_if coppies those elements form list of processes that have arrivalTime <= timer 
        //A lambda has been used to create the comdition
        //Important things to note :
                //1. the lambda checks every element of the list.
                //So copy_if runs the condition for every element.
                //2.   
        std::copy_if(listOfProcesses,listOfProcesses + numberOfProcesses,activeProcesses,[timer](Process x){x.arrivalTime <= timer});
        std::sort()
    } while (counter != numberOfProcesses);
    

}





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
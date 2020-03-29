#include<stdio.h>
#include <windows.h>

int n;

//Create a structure for processStruct , so that it can be reused
//Defining properties of a single processStruct
struct processStruct
{

int processNumber;

int arrivalTime,burstTime,closingTime,waitTime,turnAroundTime,prs;

int flag;


 }processList[100];
 
 
 //Sorting Algo to arrange the process them from low to high
 void Sorting()
 {
struct processStruct p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

//Using basic sorting algo , comparing the outer element with the inner loop element

if(processList[i].arrivalTime > processList[j].arrivalTime)

{

p = processList[i];

processList[i] = processList[j];

processList[j] = p;

}

}

}
 }
 
 
 setFontColor(int colorID){

    //A member of Windows.h Header
    //GetStdHandle uses Output Handler alternative could be system("color 1e") , which sets console color in DOS/CMD
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);

}
 showTextCenter(char msg[]){

    //Shows text in the center of console



    
         printf("\n\n\t\t\t\t\t\t");

	    printf("%s", msg);
	
    //cout<<msg;

    printf("\n");


}
 
 void setBorders(char c, int n){

    //Set Borders to make the UI look classy!

    printf("\n");
    int i = 1;
    

    for ( i = 1; i <= 120; i++ ){

        if (i%n)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red Color if i is divisible by 4

        else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //Green Color if i is !divisible by 4

          printf("%c", c);
    }

}
 
 int main()
 {
 	
 	
 	//Setup the Title and design
 	system("title SJF With Preemption");
	setBorders('x', 2);
 	showTextCenter("SJF With Preemption");
 	setBorders('x', 2);
 	setFontColor(11);

int i,t=0,b_t=0,peak;

int a[10];

float waitTimeTemp = 0, turnAroundTime = 0, avgWaitTime=0, avgTurnAroundTime=0;

printf("\n\nWhy don't you enter the number of process: ");

scanf("%d",&n);


//Apply Sorting on the processesData
Sorting();

//Initialise Array "a" with burstTime of all the stored Processes
for(int i=0;i<n;i++){

a[i]=processList[i].burstTime;
}

//Randomly Assigning the last Process highest burstTime
processList[9].burstTime = 9999;

//Performing on the arrivalTime
for(t = processList[0].arrivalTime; t <= b_t+1;){

peak = 9;
for(i=0;i<n;i++){

if(processList[i].arrivalTime <= t && processList[i].burstTime < processList[peak].burstTime && processList[i].flag != 1)
{
peak = i;
}
if(processList[peak].burstTime==0 && processList[i].flag != 1){


processList[i].flag = 1;
processList[peak].closingTime=t;processList[peak].burstTime=9999;
printf("P%d completes in %d\n",
processList[i].processNumber,
processList[peak].closingTime);

}
}
t++;
(processList[peak].burstTime)--;
}

//Calculating the average Timings
for(i=0;i<n;i++)
{
processList[i].turnAroundTime=(processList[i].closingTime)-(processList[i].arrivalTime);

avgTurnAroundTime=avgTurnAroundTime+processList[i].turnAroundTime;

processList[i].waitTime=((processList[i].turnAroundTime)-a[i]);

avgWaitTime=avgWaitTime+processList[i].waitTime;
}


//Print the Titles
printf("\n\nPNO\tAT\tCT\tTA\tWTt\n");

//Show the resopective Values under the row
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",
processList[i].processNumber,
processList[i].arrivalTime,
processList[i].closingTime,
processList[i].turnAroundTime,
processList[i].waitTime);
 }
 
//Final Output 
printf("\n\nAverage Turn around Time: %f\t\n\n",avgTurnAroundTime);
printf("Average Waiting Time :\t %f\t\n",avgWaitTime);


}

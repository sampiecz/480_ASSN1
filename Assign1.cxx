/***********************************************************
 CSCI 480 - Assignment 1 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section:  
 TA: 
 Date Due: Sep 06, 2019 
 Purpose: 
 ************************************************************/
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using std::cout;
using std::endl;

int main()
{
  cout << "I am the original process. My PID is " << getpid() << " and my parent's PID is " << getppid() << "." << endl;
  cout << "Now we have the first fork." << endl;

  int something = fork();
  if (something == -1)
  {
    cout << "The first fork failed." << endl;
    exit(1);
  }
  else if(something == 0)
  {
    cout << "I am the child process. My PID is " << getpid() << " my parent's PID is " << getppid() << endl;

    int childPID = fork();

    if (childPID == -1)
    {
      cout << "The second fork failed." << endl;
      exit(1);
    }
    else if (childPID == 0)
    {
      cout << "I am the grandchild process. My PID is " << getgid() << " my parent's PID is " << getppid() << "." << endl;
      cout << "I am going to exit." << endl;
      exit(0);
    }
    else
    {
      cout << "I am the child process. My PID is " << getpid() << " my parent's PID is " << getppid() << "." << endl;
      wait(0);
      exit(0);
    }
  }
  else
  {
    cout << "I am the parent process. My PID is " << getpid() << " my parent's PID is " << getppid() << "." << endl;
    sleep(2);
    cout << "I am going to call ps." << endl;
    system("ps");
    wait(0);
    cout << "I am going to terminate." << endl;
    exit(0);
  }

  return 0;

}

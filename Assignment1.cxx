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
  // 1.
  cout << "My PID is " << getpt() << "." << endl;

  // 2.
  cout << "I am about to call fork()." << endl;

  // 3.
  try
  {
    fork();
  }
  catch (const std::exception& e)
  {
    cout << "The first fork failed." << endl;
    exit(1);
  }

  // 4. 
  cout << "I am the child process." << endl;
  cout << "My PID is " << getpt() << "." << endl;
  cout << "My parent's PID is " << getppid() << endl;

  // b.
  try
  {
    // a.
    fork();
  }
  catch (const std::exception& e)
  {
    // c.
    cout << "The second fork failed." << endl;
    exit(1);
  }

  // d.
  // i.
  cout << "I am the grandchild process." << endl;
  cout << "My PID is " << getgid() << "." << endl;
  cout << "My parent's PID is " << getppid() << "." << endl;

  // ii.
  cout << "I am going to exit." << endl;

  // iii.
  exit(0);

  // i.
  cout << "I am the child process." << endl;
  cout << "My PID is " << getpt() << "." << endl;
  cout << "My parent's PID is " << getppid() << "." << endl;

  // ii.
  wait(0);

  // iii.
  cout << "I am going to exit." << endl;

  // iv.
  exit(0);

  // a.
  cout << "I am the parent process." << endl;
  cout << "My PID is " << getpt() << "." << endl;
  cout << "My parent's PID is " << getppid() << "." << endl;

  // b.
  sleep(2);

  // c.
  cout << "I am going to call ps." << endl;

  // d.
  system("ps");
  
  // e.
  wait(0);

  // f.
  cout << "I am going to terminate." << endl;

  // g.
  exit(0);

}

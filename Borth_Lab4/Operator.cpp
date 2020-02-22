/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
 * Description:  Operator Class will either run the Interactive program for a Hash Table (Closed Hashing)
 * Date: 2/22/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string filename){
  file = filename;
  tagline = "\0";
  review = 0;
}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1-  IsFull\n";
  cout << "2-  AddMovie\n";
  cout << "3-  RemoveMovie\n";
  cout << "4-  Leaf\n";
  cout << "5-  PrintLeaves\n";
  cout << "6-  PrintTreeHeight\n";
  cout << "7-  Preorder\n";
  cout << "8-  Postorder\n";
  cout << "9-  Inorder\n";
  cout << "10- Levelorder\n";
  cout << "11- Exit\n\n> ";
}

void Operator::inputTitle(string parse) {
  tagline = "\0";

  for (int i = 0; i < parse.length(); i++) {
    char ascii = parse.at(i);

    if (int (ascii) >= 97 && int (ascii) <= 122)
      tagline = tagline + parse.at(i);
  }

  if (tagline.length() < 1 && tagline.length() > 6 )
    throw(runtime_error("ERROR! Invalid Username Length.\n"));
}

void Operator::parseTitle(string parse) {
  tagline = "\0";

  for (int i = 0; i < parse.length(); i++) {
    char ascii = parse.at(i);

    if (int (ascii) >= 97 && int (ascii) <= 122)
      tagline = tagline + parse.at(i);
    else
      throw(runtime_error("ERROR! Special Characters Inserted.\n"));
  }

  if (tagline.length() < 1 && tagline.length() > 6 )
    throw(runtime_error("ERROR! Invalid Username Length.\n"));
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";
  ifstream inFile;

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n\n";
  } else {
    int MovieTitleInputFailures = 0;
    int RatingInputFailures = 0;
    while (!inFile.eof( )) {
      inFile >> tagline >> stars;

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        RatingInputFailures++;
      } else {
        try {
          inputTitle(tagline);
        } catch (runtime_error) {
          MovieTitleInputFailures++;
        }
        review = stod(stars);

        newMovie = new Movie(tagline, review);

        try {
          IMDB.add(newMovie);
        } catch (runtime_error) {
          MovieTitleInputFailures++;
        }
        
      }
    }

    if(MovieTitleInputFailures > 0)
      cout << "ERROR! Invalid Input for Movie Titles Detected: " << MovieTitleInputFailures << "\n";

    if(RatingInputFailures > 0)
      cout << "ERROR! Invalid Input for Movie Ratings Detected: " << RatingInputFailures << "\n";
  }

  // Close File.
  inFile.close();

  do {
    printCommands();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printCommands();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. Is Empty - Complete!
        if (option == 1) {
          cout << "\nIs Binary Tree is: ";
          if(IMDB.isFull()) {
            cout << "Full!\n\n";
          } else {
            cout << "NOT Full!\n\n";
          }
        }
        // 2- AddMovie - Complete!
        else if (option == 2) {
          /*
          cout << "\nPreparing to Insert a New Movie...\n";

          cout << "\nEnter user details to be added:\n\n> ";
          cin >> tagline >> pParse;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter user details to be added:\n\n> ";
              cin >> tagline >> pParse;

            } else {
              bool beginInsert = true;
              bool tempLinearPlaced = false;
              bool tempQuadraticPlaced = false;

              try {
                parseTitle(tagline);
              } catch (runtime_error) {
                beginInsert = false;
                tagline = "\0";
                cout << "\nERROR! Invalid Username!\n\n";
                cout << "\n Username must be no more than 6 characters in length.\n";
                cout << "\n Username must not contain special characters (., * , ? ,@ ,#, etc.).\n";
                cout << "\n Username must not contain have any capitalized characters (A, B, C, ..., Z).\n\n";
              }

              try {
                parsePassword(pParse);
              } catch (runtime_error) {
                beginInsert = false;
                pword = "\0";
                cout << "\nERROR! Invalid Password!\n\n";
                cout << "\n Password must be no more than 7 characters in length.\n";
                cout << "\n Password must not contain special characters (., * , ? ,@ ,#, etc.).\n";
                cout << "\n Password must not contain have any capitalized characters (A, B, C, ..., Z).\n";
                cout << "\n Password must contain at least 2 numbers and 3 characters.\n\n";
              }

              if (beginInsert) {
                cout << "\nInserting New User into the records...\n\n";

                try {
                  insertRecord("LinearTable");
                  tempLinearPlaced = placedLinear;
                } catch (runtime_error) {
                  cout << "ERROR! Username Already Exists.\n\n";
                }
                cout << "Linear Probing:\n";
                if(placedLinear)
                  cout << "Record successfully inserted\n\n";
                else
                  cout << "ERROR! cannot place record\n\n";

                try {
                  insertRecord("QuadraticTable");
                  tempQuadraticPlaced = placedQuadratic;
                } catch (runtime_error) {
                  cout << "ERROR! Username Already Exists.\n\n";
                }
                cout << "Quadratic Probing:\n";
                if(placedQuadratic)
                  cout << "Record successfully inserted\n\n";
                else
                  cout << "ERROR! cannot place record\n\n";

                int linearNumOfRecords = 0;

                for (int i = 1; i <= hashTableLength; i++) {
                  if(LinearTable.getEntry(i)->getUsername() != "\0" && LinearTable.getEntry(i)->getPassword() != "\0")
                    linearNumOfRecords++;
                }

                if (linearNumOfRecords > hashTableLoadFactor) {
                  string temptagline = tagline;
                  string tempPword = pword;
                  rehashTables();

                  parseTitle(temptagline);
                  parsePassword(tempPword);

                  if (tempLinearPlaced) {
                    try {
                      insertRecord("LinearTable");
                    } catch (runtime_error) {

                    }
                  }

                  if (tempQuadraticPlaced) {
                    try {
                      insertRecord("QuadraticTable");
                    } catch (runtime_error) {

                    }
                  }
                }

                int quadraticNumOfRecords = 0;

                for (int i = 1; i <= hashTableLength; i++) {
                  if(QuadraticTable.getEntry(i)->getUsername() != "\0" && QuadraticTable.getEntry(i)->getPassword() != "\0")
                    quadraticNumOfRecords++;
                }

                if (quadraticNumOfRecords > hashTableLoadFactor) {
                  string temptagline = tagline;
                  string tempPword = pword;
                  rehashTables();

                  parseTitle(temptagline);
                  parsePassword(tempPword);

                  if (tempLinearPlaced) {
                    try {
                      insertRecord("LinearTable");
                    } catch (runtime_error) {

                    }
                  }

                  if (tempQuadraticPlaced) {
                    try {
                      insertRecord("QuadraticTable");
                    } catch (runtime_error) {

                    }
                  }
                }
              }

              break;
            }
          }
          */
        }
        // 2- RemoveMovie - Complete!
        else if (option == 3) {
          /*
          cout << "\nPreparing to Delete a New Movie...\n";

          cout << "\nEnter user and password to be removed:\n\n> ";
          cin >> tagline >> pParse;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nEnter user and password to be removed:\n\n> ";
              cin >> tagline >> pParse;

            } else {
              bool beginRemove = true;

              try {
                parseTitle(tagline);
              } catch (runtime_error) {
                beginRemove = false;
                tagline = "\0";
                cout << "\nERROR! Invalid Username!\n\n";
                cout << "\n Username must be no more than 6 characters in length.\n";
                cout << "\n Username must not contain special characters (., * , ? ,@ ,#, etc.).\n";
                cout << "\n Username must not contain have any capitalized characters (A, B, C, ..., Z).\n\n";
              }

              try {
                parsePassword(pParse);
              } catch (runtime_error) {
                beginRemove = false;
                pword = "\0";
                cout << "\nERROR! Invalid Password!\n\n";
                cout << "\n Password must be no more than 7 characters in length.\n";
                cout << "\n Password must not contain special characters (., * , ? ,@ ,#, etc.).\n";
                cout << "\n Password must not contain have any capitalized characters (A, B, C, ..., Z).\n";
                cout << "\n Password must contain at least 2 numbers and 3 characters.\n\n";
              }

              if (beginRemove) {
                try {
                  cout << "\nDeleting Defined User from the records...\n\n";

                  hashValue = hashKey(pword);

                  placedLinear = false;
                  int index = hashValue % hashTableLength;
                  int position = 0;

                  while(!placedLinear && position < LinearTable.getLength()) {
                    if(LinearTable.getEntry(index + 1)->getUsername() == tagline &&
                       LinearTable.getEntry(index + 1)->getPassword() == pword) {
                      placedLinear = true;
                      LinearTable.getEntry(index + 1)->setUsername("\0");
                      LinearTable.getEntry(index + 1)->setPassword("\0");
                      //newUser = new User();
                      //LinearTable.replace(index + 1, newUser);
                    } else {
                      index++;
                      position++;
                      index = index % hashTableLength;
                    }
                  }

                  cout << "Linear Probing:\n";
                  if(placedLinear)
                    cout << "Record successfully removed\n\n";
                  else
                    cout << "ERROR! cannot remove record\n\n";

                  placedQuadratic = false;
                  index = hashValue % hashTableLength;
                  position = 0;
                  int exponent = position;

                  while(!placedQuadratic && position < QuadraticTable.getLength()) {
                    if(QuadraticTable.getEntry(index + 1)->getUsername() == tagline &&
                       QuadraticTable.getEntry(index + 1)->getPassword() == pword) {
                      placedQuadratic = true;
                      QuadraticTable.getEntry(index + 1)->setUsername("\0");
                      QuadraticTable.getEntry(index + 1)->setPassword("\0");
                      //newUser = new User();
                      //QuadraticTable.replace(index + 1, newUser);
                    } else {
                      position++;
                      exponent = position^2;
                      index = ( (index % hashTableLength) + exponent ) % hashTableLength;
                    }
                  }

                  cout << "Quadratic Probing:\n";
                  if(placedQuadratic)
                    cout << "Record successfully removed\n\n";
                  else
                    cout << "ERROR! cannot remove record\n\n";
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }
              }

              break;
            }
          }
          */
        }
        // 5- PrintMovies - Complete!
        else if (option == 10) {
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nLevel-Order - ";
            IMDB.levelOrder();
            IMDB.print();
          }
        }
        // 11- Exit - Complete!
        else if (option == 11) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 11);

  tagline = "\0";
  review = 0;

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}

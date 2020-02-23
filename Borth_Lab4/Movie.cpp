/* -----------------------------------------------------------------------------
*
* File Name:  Movie.cpp
* Author: Marco Borth
* Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
* Description:  Movie set and get methods defined here.
* Date: 2/22/20
*
---------------------------------------------------------------------------- */

#include "Movie.h"
#include <string>
using namespace std;

Movie::Movie() {
  title = "\0";
  rating = 0.0;
}

Movie::Movie(const Movie &other) {
  title = other.getTitle();
  rating = other.getRating();
}

Movie::~Movie(){}

Movie::Movie(string alias, double stars) {
  title = alias;
  setRating(stars);
}

void Movie::setTitle(string alias) {
  title = alias;
}

string Movie::getTitle() const {
  return(title);
}

void Movie::setRating(double stars) {
  if(stars >= 0 && stars <= 5)
    rating = stars;
}

double Movie::getRating() const {
  return(rating);
}

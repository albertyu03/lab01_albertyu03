// name(s) and Perm 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
Car::Car() {
  this->manufacturer = NULL;
  this->model = NULL;
  this->zeroToSixtyNs = '0';
  this->headonDragCoeff = '0';
  this->horsepower = '0';
  this->backseatDoors = '0';
  this->seatCount = '0';

}

Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
  this->manufacturer = manufacturerName;
  this->modelName = modelName;
  this->zeroToSixtyNs = perf->zeroToSixtyNs;
  this->headonDragCoeff = perf->headonDragCoeff;
  this->horsepower = perf->horsepower;
  this->backseatDoors = backseatDoorDesign;
  this->seatCount = numSeats;
}
/*
Car::Car(Car const& o) {
  this->manufacturer = *o->
}                                                                          
*/                                             ~                 
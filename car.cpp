// Albert Yu 6603104
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
Car::Car() {
  manufacturer = NULL;
  model = NULL;
  zeroToSixtyNs = '0';
  headonDragCoeff = '0';
  horsepower = '0';
  DoorKind doorP = None;
  backseatDoors = doorP;
  seatCount = '0';

}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
  manufacturerChange(manufacturerName);//f
  modelNameChange(modelName);
  reevaluateStats(perf);
  backseatDoors = backseatDoorDesign;
  seatCount = numSeats;
}

Car& Car::operator=(Car const& o) {
  if(&o == this) {
    return *this;
  }
  manufacturer = NULL;
  model = NULL;
  manufacturerChange(o.getManufacturer());
  modelNameChange(o.getModel());
  reevaluateStats(o.getStats());
  seatCount = o.getSeatCount();
  backseatDoors = o.getBackseatDoors();
  return *this;
}                                                                          
Car::~Car() {
  delete[] manufacturer;
  delete[] model;
}                

char const* Car::getManufacturer() const {
  return manufacturer;
}                
char const* Car::getModel() const {
  return model;
}
PerformanceStats Car::getStats() const {
  PerformanceStats getVeh = PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
  return getVeh;
}
uint8_t Car::getSeatCount() const {
  return seatCount;
}
DoorKind Car::getBackseatDoors() const {
  return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer) {
  delete[] manufacturer; //remove pointer from memory
  manufacturer = new char[strlen(newManufacturer) + 1]; //new spot in memory
  strcpy(manufacturer, newManufacturer);
}
void Car::modelNameChange(char const* const newModelName) {
  delete[] model; //remove pointer from memory
  model = new char[strlen(newModelName) + 1]; //new spot in memory
  strcpy(model, newModelName);
}
void Car::reevaluateStats(PerformanceStats newStats) {
  horsepower = newStats.horsepower;
  zeroToSixtyNs = newStats.zeroToSixtyNs;
  headonDragCoeff = newStats.headonDragCoeff;
}
void Car::recountSeats(uint8_t newSeatCount) {
  seatCount = newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind) {
  backseatDoors = newDoorKind;
}

#include <iostream>
#include <cstring>
#include "2_Car.h"
using namespace std;

void Car::InitMembers(const char* ID, int fuel){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState(){
    cout << "Gamer ID: " << gamerID << endl;
    cout << "Fuel Gauge: " << fuelGauge << "%\n";
    cout << "Current Speed: " << curSpeed << "km/s\n\n";
}

void Car::Accel(){
    if (fuelGauge <= 0) return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;
    
    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
    if (curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

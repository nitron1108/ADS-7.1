// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "train.h"

int main() {
  srand (time (nullptr));
  for (int n = 10; n <= 500; n += 10){
    //все выключены
    Train trainOff;
    for (int i = 0; i < n; i++){
      trainOff.addCar(false);
    }
    trainOff.getLength();
    int offOps = trainOff.getOpCount();

    //все включены
    Train trainOn;
    for (int i = 0; i < n; i++){
      trainOn.addCar(true);
    }
    trainOn.getLength();
    int onOps = trainOn.getOpCount();

    //случайным образом
    Train trainRandoms;
    for (int i = 0; i < n; i++){
      trainRandoms.addCar(rand() % 2);
    }
    trainRandoms.getLength();
    int randomsOps = trainRandoms.getOpCount();

    std::cout
      << n << " "
      << offOps << " "
      << onOps << " "
      << randomsOps << std::endl;  
  }
  return 0;
}

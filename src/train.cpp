// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool lightState) {
  Car* fresh = new Car{lightState, nullptr, nullptr};
  if (!first) {
    first = fresh;
    fresh->next = fresh;
    fresh->prev = fresh;
  } else {
    Car* tail = first->prev;
    fresh->next = first;
    fresh->prev = tail;
    tail->next = fresh;
    first->prev = fresh;
  }
}

int Train::getLength() {
  if (!first) return 0;

  countOp = 0;
  Car* current = first;

  if (!current->light) current->light = true;

  while (true) {
    int forwardSteps = 0;
    Car* runner = current;

    do {
      runner = runner->next;
      ++forwardSteps;
      ++countOp;
    } while (!runner->light);

    runner->light = false;

    const Car* backtrack = runner;
    for (int i = 0; i < forwardSteps; ++i) {
      backtrack = backtrack->prev;
      ++countOp;
    }

    if (backtrack == current && !backtrack->light) {
      return forwardSteps;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}

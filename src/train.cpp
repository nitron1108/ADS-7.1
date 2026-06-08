// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : entryPoint(nullptr), stepCounter(0) {}

void Train::addWagon(bool lampState) {
  Wagon* fresh = new Wagon{lampState, nullptr, nullptr};
  if (!entryPoint) {
    entryPoint = fresh;
    fresh->next = fresh;
    fresh->prev = fresh;
  } else {
    Wagon* tail = entryPoint->prev;
    fresh->next = entryPoint;
    fresh->prev = tail;
    tail->next = fresh;
    entryPoint->prev = fresh;
  }
}

int Train::calculateLength() {
  if (!entryPoint) return 0;

  stepCounter = 0;
  Wagon* current = entryPoint;

  if (!current->lamp) current->lamp = true;

  while (true) {
    int forwardSteps = 0;
    Wagon* runner = current;

    do {
      runner = runner->next;
      ++forwardSteps;
      ++stepCounter;
    } while (!runner->lamp);

    runner->lamp = false;

    const Wagon* backtrack = runner;
    for (int i = 0; i < forwardSteps; ++i) {
      backtrack = backtrack->prev;
      ++stepCounter;
    }

    if (backtrack == current && !backtrack->lamp) {
      return forwardSteps;
    }
  }
}

int Train::getStepCount() const {
  return stepCounter;
}

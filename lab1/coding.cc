#include <iostream>
#include "coding.h"

Coding::Coding() {

}

Coding::~Coding() {

}

unsigned char Coding::encode(unsigned char c) {
  //return static_cast<char>(c + 1);
  return (c+4000);
}

unsigned char Coding::decode(unsigned char c) {
  //return static_cast<char>(c - 1);
  return (c-4000);
}

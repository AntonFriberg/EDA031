/*
Implement a class UMNS (unordered map name server) that uses an unordered map to
store the name/address pairs.
*/
#include <string>
#include <unordered_map>
#include <algorithm>
#include "umns.h"

using namespace std;

UMNS::UMNS() {
}

UMNS::~UMNS() {
}

void UMNS::insert(const HostName& h, const IPAddress& ip) {
  m[h] = ip;
}

bool UMNS::remove(const HostName& h) {
  IPAddress test = lookup(h);
  if (test == NON_EXISTING_ADDRESS) {
    return false;
  } else {
    m.erase(h);
    return true;
  }
}

IPAddress UMNS::lookup(const HostName& h) const {
  auto it = m.find(h);
  if (it != m.end()) {
    return it->second;
  }
  return NON_EXISTING_ADDRESS;
}

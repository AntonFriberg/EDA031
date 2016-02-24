/*
Implement a class MNS (map name server) that uses a map to store the name/address
pairs. The average search time in this implementation will be considerably better than
that for the vector implementation.
*/
#include <string>
#include <map>
#include <algorithm>
#include "mns.h"

using namespace std;

MNS::MNS() {
}

MNS::~MNS() {
}

void MNS::insert(const HostName& h, const IPAddress& ip) {
  m[h] = ip;
}

bool MNS::remove(const HostName& h) {
  IPAddress test = lookup(h);
  if (test == NON_EXISTING_ADDRESS) {
    return false;
  } else {
    m.erase(h);
    return true;
  }
}

IPAddress MNS::lookup(const HostName& h) const {
  auto it = m.find(h);
  if (it != m.end()) {
    return it->second;
  }
  return NON_EXISTING_ADDRESS;
}

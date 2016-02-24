/*
An unordered map is implemented using a hash table. You shall compare this
implementation with your own implementation of a hash table. Implement a class
HNS (hash name server) that uses a hash table — a vector of vector’s — to store the
name/address pairs.
*/
#include <string>
#include <unordered_map>
#include <algorithm>
#include "hns.h"

using namespace std;

HNS::HNS() {
}

HNS::~HNS() {
}

void HNS::insert(const HostName& h, const IPAddress& ip) {
  m[h] = ip;
}

bool HNS::remove(const HostName& h) {
  IPAddress test = lookup(h);
  if (test == NON_EXISTING_ADDRESS) {
    return false;
  } else {
    m.erase(h);
    return true;
  }
}

IPAddress HNS::lookup(const HostName& h) const {
  auto it = m.find(h);
  if (it != m.end()) {
    return it->second;
  }
  return NON_EXISTING_ADDRESS;
}

/*
size_t HNS::host_hash(const HostName& h) {
    return hash<HostName>()(h + "abc");
}
*/

/*size_t ip_hash(const IPAddress& ip) {
    return hash<IPAddress>()(ip);
}
*/

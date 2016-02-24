/*
Implement a class VNS (vector name server) that uses an unsorted vector to store the
name/address pairs. Use the find if algorithm to search for a host name. The third
parameter to the algorithm should be a lambda.
*/
#include <string>
#include <vector>
#include <algorithm>
//#include "nameserverinterface.h"
#include "vns.h"

using namespace std;

VNS::VNS() {
}

VNS::~VNS() {
}

void VNS::insert(const HostName& h, const IPAddress& ip) {
  auto pair = make_pair(h, ip);
  v.push_back(pair);
}

bool VNS::remove(const HostName& h) {
  auto it = find_if
  (v.begin(), v.end(), [h](pair<HostName, IPAddress> p){
    return (p.first == h);
  });
  if (it != v.end()) {
    v.erase(it);
    return true;
  }
  return false;
}

IPAddress VNS::lookup(const HostName& h) const {
  auto it = find_if
  (v.begin(), v.end(), [h](pair<HostName, IPAddress> p){
    return (p.first == h);
  });
  if (it != v.end()) {
    return (it->second);
  } else {
    return NON_EXISTING_ADDRESS;
  }
}

/*class EqualHost {
   public:
     EqualTo( string host ) : value_( value ) { }
     bool operator()(HostName host) const {
       return host == value_.first;
     }
   private:
     const pair<HostName,IPAddress> value_;
   };
   bool IsAnyElementGreaterThanFive( vector<int>& v )
   {
     return find_if( v.begin(), v.end(), GreaterThan(5) )
            != v.end();
   }
*/

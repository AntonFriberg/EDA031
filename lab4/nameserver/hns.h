/*
An unordered map is implemented using a hash table. You shall compare this
implementation with your own implementation of a hash table. Implement a class
HNS (hash name server) that uses a hash table — a vector of vector’s — to store the
name/address pairs.
*/
#ifndef HNS_H
#define HNS_H

#include <string>
#include <unordered_map>
#include <functional>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

namespace std {
    template <>
        class hash<HashEntry>{
        public :
            size_t operator()(const HashEntry &h ) const
            {
                return hash<string>()(h.getValue()) ^
                  hash<unsigned int>()(h.getKey());
            }
    };
};

/*
struct hash_host {
    size_t operator()(const HostName& h) const {
        return std::hash<HostName>()(h); }
};
*/

class HNS : public NameServerInterface {
public:
  HNS();
	~HNS();

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void insert(const HostName&, const IPAddress&);

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName&);

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress lookup(const HostName&) const;

private:
  std::unordered_map<HostName,IPAddress> m;
};

/*
Implementation of Hash Table:
First the values and keys are paired in an object HashEntry.
*/

class HashEntry {
private:
      HostName key;
      IPAddress value;
public:
      HashEntry(HostName key, IPAddress value) {
            this->key = key;
            this->value = value;
      }

      IPAddress getKey() {
            return key;
      }

      HostName getValue() {
            return value;
      }
};

/*
Then we implement the Hash Table via use of vectors and
standard hash functions.
*/
class HashMap {
public:
  HashMap();
  ~HashMap();
  IPAddress lookup(const HostName& h);
  void put(Entry e);
  bool remove(Entry e);
  unsigned int hash(Entry e);
private:
  const int TABLE_SIZE = 128;
  // representation
  struct Entry {
  HostName host;
  IPAddress ip;
  };
  // The hash table
  vector<Entry> entries;
  vector<vector<Entry>> hashtable;
};

HashMap::HashMap() {
  vector<vector<Entry>> hashtable(TABLE_SIZE, vector<Entry>(TABLE_SIZE));
  for (int i = 0; i != TABLE_SIZE; ++i) {
    hashtable.push_back(vector<Entry>()); //Add empty row
  }
}

HashMap::~HashMap()
{
}

IPAddress HashMap::lookup(const HostName& h) {
  unsigned int index = hash(h);
  for (int i=0; i!=table[index].size(); ++i) {
    if (hashtable[index][i].host == h.host) {
      return hashtable[index][i].ip;
    }
  }
  return NON_EXISTING_ADDRESS;
}

void HashMap::put(Entry e) {
  int index = hash(str);
    table[index].push_back(p);
}



#endif

/*
Implement a class VNS (vector name server) that uses an unsorted vector to store the
name/address pairs. Use the find if algorithm to search for a host name. The third
parameter to the algorithm should be a lambda.
*/
#ifndef VNS_H
#define VNS_H

#include <string>
#include <vector>
#include "nameserverinterface.h"

using HostName = std::string;
using IPAddress = unsigned int;

class VNS : public NameServerInterface {
public:
  VNS();
	~VNS();

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
  std::vector<std::pair<std::string, unsigned int>> v; //Vector of pairs
};

#endif

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ipv4 {
	union {
		uint32_t all;
		uint8_t byte[4];
	} data;
	void parse_in(string input) {
		auto first = input.find(".");
		auto second = input.find(".", first+1);
		auto third = input.find(".", second+1);
		// note to self: substr sucks.
		data.byte[3] = stoi(input.substr(0, first));
		data.byte[2] = stoi(input.substr(first+1, second-first-1));
		data.byte[1] = stoi(input.substr(second+1, third-second-1));
		data.byte[0] = stoi(input.substr(third+1));
	}
	string parse_out() {
		return to_string(data.byte[3]) + "." + to_string(data.byte[2]) + "." + to_string(data.byte[1]) + "." + to_string(data.byte[0]);
	}
};

vector<ipv4> ipv4_range(ipv4 first, ipv4 second) {
	auto smallest = min(first.data.all, second.data.all);
	auto largest = max(first.data.all, second.data.all);

	vector<ipv4> ips;
	for (uint32_t i = smallest; i < largest; i++) {
		ipv4 new_ip;
		new_ip.data.all = i;
		ips.push_back(new_ip);
	}

	return ips;
}


int main()
{
	ipv4 f;
	f.parse_in("0.0.0.15");
	ipv4 s;
	s.parse_in("0.0.0.25");
	auto range = ipv4_range(f, s);
	for (ip : range) {
		cout << ip.parse_out() << endl;
	}
	return 0;
}

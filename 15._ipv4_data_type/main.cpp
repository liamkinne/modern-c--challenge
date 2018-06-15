#include <iostream>
#include <string>
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


int main()
{
	ipv4 s;
	s.data.all = 0x123456;
	cout << s.parse_out() << endl;
	s.parse_in("192.168.0.1");
	cout << s.parse_out() << endl;
	return 0;
}

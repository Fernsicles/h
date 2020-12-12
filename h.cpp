#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;
int main(int argc, char **argv) {
	string input = string(argv[2]);
	string output = "";
	if(string("e").compare(argv[1]) == 0) {
		boost::to_upper(input);
		for(int i = 0; input[i] != 0; i++) {
			unsigned char x = input[i];
			x -= 64;
			for(int j = 0b1; j <= 0b10000; j <<= 1) {
				if(x & j) {
					output.push_back('H');
				} else {
					output.push_back('h');
				}
			}
		}
	}
	if(string("d").compare(argv[1]) == 0) {
		for(int i = 0; input[i] != 0; i += 5) {
			unsigned char x = 0b0;
			for(int j = 0; j < 5; j++) {
				if(input[i + j] == 'H') {
					x |= (0b1 << j);
				}
			}
			x += 64;
			output.push_back(x);
		}
	}
	cout << output << endl;
}
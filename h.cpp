#include <string>
#include <iostream>
#include <cctype>
#include <unistd.h>

using namespace std;

void encode(char *encode_string) {
	for(int i = 0; encode_string[i] != 0; i++) {
		unsigned char x = toupper(encode_string[i]);
		switch(x) {
			case '!':
				cout << "hHhHH";
				break;
			case ' ':
				cout << "HHhHH";
				break;
			case '\'':
				cout << "hhHHH";
				break;
			case '.':
				cout << "HhHHH";
				break;
			case ',':
				cout << "hHHHH";
				break;
			case '?':
				cout << "HHHHH";
				break;
			default:
				x -= 65;
				for(int j = 0b1; j <= 0b10000; j <<= 1) {
					if(x & j) {
						cout << "H";
					} else {
						cout << "h";
					}
				}
				break;
		}
	}
	cout << endl;
}

void decode(char *decode_string) {
	for(int i = 0; decode_string[i] != 0; i += 5) {
		unsigned char x = 0b0;
		for(int j = 0; j < 5; j++) {
			if(decode_string[i + j] == 'H') {
				x |= (0b1 << j);
			}
		}
		switch(x) {
			case 26:
				x = '!';
				break;
			case 27:
				x = ' ';
				break;
			case 28:
				x = '\'';
				break;
			case 29:
				x = '.';
				break;
			case 30:
				x = ',';
				break;
			case 31:
				x = '?';
				break;
			default:
				x += 65;
				break;
		}
		cout << x;
	}
	cout << endl;
}

int main(int argc, char **argv) {
	extern char *optarg;
	extern int optind;
	int c, err = 0;
	int eflag = 0, dflag = 0, hflag = 0;
	char *estring, *dstring;
	static char usage[] = "usage: h [-h] [-d decode_string] [-e encode_string]";
	while((c = getopt(argc, argv, "hd:e:")) != -1) {
		switch(c) {
			case 'h':
				hflag = 1;
				break;
			case 'd':
				dflag = 1;
				dstring = optarg;
				break;
			case 'e':
				eflag = 1;
				estring = optarg;
				break;
			default:
				cout << endl;
				abort();
		}
	}

	if(hflag) {
		cout << usage << endl;
	} if(dflag) {
		decode(dstring);
	} if(eflag) {
		encode(estring);
	}
}
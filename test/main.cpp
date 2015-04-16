#include <cw/string.h>
#include <cw/utf8.h>
#include <iostream>

using namespace std;
using namespace cw;

int main() {
	cw::string<utf8> str("hello world\xF0\x90\x8D\x88");

	cout << std::distance( str.begin(), str.end() ) << endl;

	cout << endl << "Press enter to continue . . . "; cin.get();
}


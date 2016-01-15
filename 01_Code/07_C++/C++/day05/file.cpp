#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <iostream>
using namespace std;
class File {
public:
	File (char const* filename,
		char const* mode) {
		if (! (m_fp = fopen (filename,
			mode)))
			throw string (strerror (errno));
	}
	~File (void) {
		fclose (m_fp);
	}
	size_t read (void* buffer, size_t size,
		size_t count) {
		return fread (buffer, size, count,
			m_fp);
	}
	size_t write (void const* buffer,
		size_t size, size_t count) {
		return fwrite (buffer, size, count,
			m_fp);
	}
	// ...
private:
	FILE* m_fp;
};
int main (void) {
	File file ("test.txt", "a+");
	file.write ("Hello, World !\n", 1, 15);
	return 0;
}

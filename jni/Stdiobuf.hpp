#ifndef STDIOBUF_HPP
#define STDIOBUF_HPP

#include <streambuf>

using namespace std;

class Stdiobuf : public std::streambuf
{
private:
    FILE* d_file;
    char  d_buffer[8192];
public:
    Stdiobuf(FILE* file): d_file(file) {}
    ~Stdiobuf() { if (this->d_file) fclose(this->d_file); }
    int underflow() {
        if (this->gptr() == this->egptr() && this->d_file) {
            size_t size = fread(this->d_buffer, 8192,1, this->d_file);
            this->setg(this->d_buffer, this->d_buffer, this->d_buffer + size);
        }
        return this->gptr() == this->egptr()
            ? traits_type::eof()
            : traits_type::to_int_type(*this->gptr());
    }
};

#endif // STDIOBUF_HPP

#include <iostream>
#include <string>

#include <openssl/md5.h>

int main()
{
    // const std::string input = "abcdef609043";
    const unsigned char* input = (unsigned char*)"abcdef609043";
    std::string output;
    unsigned char res[MD5_DIGEST_LENGTH];

    MD5(input, sizeof(input), res);

    return 0;
}

// EmailFile.h
#include <cstring>
// EmailFile.cpp
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>
#include <fstream>

namespace seneca {

    const int BUFFER_SIZE = 1024;
    class EmailFile; // Forward declaration
    class Email {
        char* m_email{ nullptr };
        char* m_name{ nullptr };
        char m_year[5]{ '\0' };
        Email() {};
        ~Email();
        Email& operator=(const Email&);
        bool load(std::ifstream& in);
        friend class EmailFile;

    private:
        Email(const Email&); // Prohibits copying
    };

    class EmailFile {
        Email* m_emailLines{ nullptr };
        char* m_filename{};
        int m_noOfEmails{ 0 };
        void setEmpty();
        void setFilename(const char* filename);
        bool setNoOfEmails();
        void loadEmails();

    public:
        EmailFile();
        EmailFile(const char* filename);
        EmailFile(const EmailFile& other);
        EmailFile& operator=(const EmailFile& other);
        ~EmailFile();
        bool saveToFile(const char* filename) const;
        void fileCat(const EmailFile& obj, const char* name = nullptr);
        std::ostream& view(std::ostream& ostr) const;
        operator bool() const;
    };

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);
}

#endif // !SENECA_EMAILFILE_H

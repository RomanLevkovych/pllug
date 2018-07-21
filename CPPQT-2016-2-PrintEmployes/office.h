#ifndef OFFICE_H
#define OFFICE_H

#include <string>

#include "printable.h"

class Office : public Printable
{
public:
    Office(std::string name="",
           std::string address="",
           int square=0,
           int countWorkers=0);

    // Printable interface
    void print() const override;

    std::string name() const;
    void setName(const std::string &name);

    std::string address() const;
    void setAddress(const std::string &address);

    int square() const;
    void setSquare(int square);

    int countWorkers() const;
    void setCountWorkers(int countWorkers);

private:
    std::string mName;
    std::string mAddress;
    int mSquare;
    int mCountWorkers;
};

#endif // OFFICE_H

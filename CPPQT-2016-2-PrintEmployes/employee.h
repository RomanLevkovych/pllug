#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "printable.h"

class Employee : public Printable
{
public:
    Employee(std::string name=""
            ,std::string phoneNumber=""
            ,std::string address=""
            ,long salary=0
            ,int yearOfStartJob=0);

    // Printable interface
    void print() const override;

    int getYearOfStartTheJob() const;
    void setYearOfStartTheJob(int value);

    unsigned long getSalary() const;
    void setSalary(unsigned long salary);

    std::string getAddress() const;
    void setAddress(const std::string &address);

    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string &phoneNumber);

    std::string getName() const;
    void setName(const std::string &name);

private:
    std::string mName;
    std::string mPhoneNumber;
    std::string mAddress;
    unsigned long mSalary;
    int mYearOfStartTheJob;
};

#endif // EMPLOYEE_H

#include "employee.h"

#include <iostream>

Employee::Employee(std::string name, std::string phoneNumber, std::string address, long salary,int yearOfStartJob)
    : mName(name)
    , mPhoneNumber(phoneNumber)
    , mAddress(address)
    , mSalary(salary)
    , mYearOfStartTheJob(yearOfStartJob)
{

}

void Employee::print() const
{
    std::cout << mName << "\n"
              << mAddress << "\n"
              << mPhoneNumber << "\n"
              << mSalary << "$\n"
              << mYearOfStartTheJob << " years\n";
}

int Employee::getYearOfStartTheJob() const
{
    return mYearOfStartTheJob;
}

void Employee::setYearOfStartTheJob(int value)
{
    mYearOfStartTheJob = value;
}

unsigned long Employee::getSalary() const
{
    return mSalary;
}

void Employee::setSalary(unsigned long salary)
{
    mSalary = salary;
}

std::string Employee::getAddress() const
{
    return mAddress;
}

void Employee::setAddress(const std::string &address)
{
    mAddress = address;
}

std::string Employee::getPhoneNumber() const
{
    return mPhoneNumber;
}

void Employee::setPhoneNumber(const std::string &phoneNumber)
{
    mPhoneNumber = phoneNumber;
}

std::string Employee::getName() const
{
    return mName;
}

void Employee::setName(const std::string &name)
{
    mName = name;
}


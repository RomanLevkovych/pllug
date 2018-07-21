#include "office.h"
#include<iostream>

Office::Office(std::string name, std::string address, int square, int countWorkers)
    : mName(name)
    , mAddress(address)
    , mSquare(square)
    , mCountWorkers(countWorkers)
{

}

void Office::print() const
{
    std::cout << mName << "\n"
              << mAddress << "\n"
              << mSquare << "m2\n"
              << mCountWorkers << " workers\n";
}

std::string Office::name() const
{
    return mName;
}

void Office::setName(const std::string &name)
{
    mName = name;
}

std::string Office::address() const
{
    return mAddress;
}

void Office::setAddress(const std::string &address)
{
    mAddress = address;
}

int Office::square() const
{
    return mSquare;
}

void Office::setSquare(int square)
{
    mSquare = square;
}

int Office::countWorkers() const
{
    return mCountWorkers;
}

void Office::setCountWorkers(int countWorkers)
{
    mCountWorkers = countWorkers;
}

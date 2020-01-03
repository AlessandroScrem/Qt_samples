#include "watercooler.h"
#include "person.h"

WaterCooler::WaterCooler(QObject *parent) : QObject(parent)
{
    Person Cathy;
    Person Bob;
    Person Sally;

    Cathy.Name = "Chaty Cathy";
    Bob.Name = "Poor Bob";
    Sally.Name = "Silly Sally";

    connect(&Cathy, &Person::Speak, &Bob, &Person::Listen);
    connect(&Cathy, &Person::Speak, &Sally, &Person::Listen);
    Cathy.Gossip("I heard Mark is bald");
}

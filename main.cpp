#include <iostream>

#include "Utils.hpp"
#include "Miniature.hpp"
#include "Database.hpp"
#include "Commands.hpp"

int main(int argc, char ** args)
{
    // read the command and args
    COMMANDS command = COMMANDS::HELP;
    // the first arg is the path to this exec
    if (argc >= 2)
    {
        std::string in = std::string(args[1]);
        command = CommandForString(in);
    }

    // switch based on the given command
    switch (command)
    {
    case COMMANDS::ADD:
        // check there is a name and optionally a quantity
          // else print help for this command then break
        // ask database to add (quantity or 1) to quantity of record with given name
        break;

    case COMMANDS::SUBTRACT:
        // check there is a name and optionally a quantity
          // else print help for this command then break
        // ask database to subtract (quantity or 1) from quantity of record with given name
        break;

    case COMMANDS::RENAME:
        // check there is an old/currentname and a newname
          // else print help for this command then break
        // ask database to rename record from oldname to newname
        break;

    case COMMANDS::PAINT:
        // check there is a name and optionally a quantity
          // else print help for this command then break
        // ask database to add (quantity or 1) to painted of record with given name
        break;

    case COMMANDS::SEARCH:
        // check there is any text supplied
          // else print help for this command then break
        // ask database to find records with names that include supplied text
        // adding regex to this would be great
        break;

    case COMMANDS::LIST:
        // ask database for all (non-hidden) records
        // print each one in nice table format
        break;

    case COMMANDS::HIDE:
        // check there is a name supplied
          // else print help for this command then break
        // ask database to set record 'hide' flag to true
        break;

    case COMMANDS::RESTORE:
        // check there is a name supplied
          // else print help for this command then break
        // ask database to set record 'hide' flag to false
        break;

    case COMMANDS::HELP:
    default:
        // print about
        std::cout << "Miniatures-Tracker by Will Thomas <technimanx@gmail.com>" << std::endl;
        std::cout << "https://github.com/techniman/miniatures-tracker" << std::endl;
        // print commands usage and descriptions
        break;
    }

    // quit
    return 0;
}

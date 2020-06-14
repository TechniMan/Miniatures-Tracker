#include <iostream>

#include "Utils.hpp"
#include "Miniature.hpp"
#include "Database.hpp"
#include "Commands.hpp"

void print_help(COMMANDS command = COMMANDS::HELP)
{
    // print about
    std::cout << "Miniatures-Tracker v0.1 by Will Thomas <technimanx@gmail.com>" << std::endl;
    std::cout << "Source at https://github.com/techniman/miniatures-tracker" << std::endl;
    std::cout << std::endl;

    std::cout << "command <mandatory> [optional]" << std::endl << std::endl;

    // print commands usage and descriptions
    if (command == COMMANDS::HELP || command == COMMANDS::ADD)
    {
        std::cout << "add <name> [quantity=1]" << std::endl;
        std::cout << "If entry exists, add [quantity]; else, create a new one." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::SUBTRACT)
    {
        std::cout << "subtract <name> [quantity=1]" << std::endl;
        std::cout << "If entry exists, subtract [quantity]. If it would become lower than 0, warns the user." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::RENAME)
    {
        std::cout << "rename <currentname> <newname>" << std::endl;
        std::cout << "If entry exists, changes name to <newname>." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::PAINT)
    {
        std::cout << "paint <name> [quantity=1]" << std::endl;
        std::cout << "If entry exists, add [quantity] to the amount painted; else, create a new one with the quantity and painted." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::SEARCH)
    {
        std::cout << "search <text>" << std::endl;
        std::cout << "Show entries that include text in name." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::LIST)
    {
        std::cout << "list" << std::endl;
        std::cout << "List all existing entries." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::HIDE)
    {
        std::cout << "hide <name>" << std::endl;
        std::cout << "Hide an entry." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP || command == COMMANDS::RESTORE)
    {
        std::cout << "restore <name>" << std::endl;
        std::cout << "Unhide an entry." << std::endl;
        std::cout << std::endl;
    }
    if (command == COMMANDS::HELP)
    {
        std::cout << "help" << std::endl;
        std::cout << "Shows this!" << std::endl;
        std::cout << std::endl;
    }
}

int main(int argc, char ** args)
{
    // for now, initialise an empty database
    // in future, persist database to file
    Database db = Database();

    // read the command and args
    COMMANDS command = COMMANDS::HELP;
    // the first arg is the path to this exec
    if (argc >= 2)
    {
        std::string in = std::string(args[1]);
        command = CommandForString(in);
    }

    std::string arg0 = "", arg1 = "";
    if (argc >= 3)
    {
        arg0 = args[2];
    }
    if (argc >= 4)
    {
        arg1 = args[3];
    }

    // switch based on the given command
    switch (command)
    {
    case COMMANDS::ADD:
        // if a name wasn't specified, print help and quit
        if (arg0.size() == 0)
        {
            print_help(COMMANDS::ADD);
            break;
        }

        unsigned int quantity = 1;
        // check whether a quantity was specified
        if (arg1.size() > 0)
        {
            quantity = std::stoi(arg1);
        }

        // ask database to add (quantity or 1) to quantity of record with given name
        Miniature* mini = nullptr;
        if (db.Get(arg0, mini))
        {
            mini->quantity += quantity;
            db.Insert(*mini);
        }
        // if record wasn't found, insert a new one
        else
        {
            Miniature newMini;
            newMini.name = arg0;
            newMini.quantity = quantity;
            newMini.painted = 0;
            db.Insert(newMini);
        }
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
        print_help();
        break;
    }

    // quit
    return 0;
}

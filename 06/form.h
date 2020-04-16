#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <exception> 


template<class T>
std::string args_to_str(T&& val)
{
    std::stringstream out;
    out << val;
    return out.str();
}

template<class... ArgsT>
std::string format(const std::string& str, ArgsT&&... args)
{
    std::stringstream out;
    int snum;
    std::vector<std::string> args_new = {args_to_str(std::forward<ArgsT>(args))... };
    int size = str.size();
    int args_size = args_new.size();
    bool open = false;
    bool check_closed = false;

    for (int i = 0; i < size; i++)
    {
        if (check_closed)
        {
            if (str[i] == '}')
            {
                out << args_new[snum];
                check_closed = false;
                open=false;
                continue;
            }
            else
            {
                if (!std::isdigit(str[i]))
                {
                throw std::runtime_error("Bracket not closed");
                }
            }
        }

        if (open)
        {
            if (std::isdigit(str[i]))
            {
                snum*=10;
                snum+=str[i] - '0';
                if(snum < args_size)
                {
                    check_closed = true;
                    //open = false;
                }
                else
                {
                    throw std::runtime_error("Not so many args");
                }
            }
            else
            {
                throw std::runtime_error("Something wrong");
            }
        }
        else
        {
            if (str[i] == '{')
            {
                open = true;
                snum=0;
            }
            else if (str[i] == '}')
            {
                throw std::runtime_error("Single closing bracket");
            }
            else
            {
                out << str[i];
            }
        }

    }

    if (open||check_closed)
    {
        throw std::runtime_error("Single bracket in the end of string");
    }
    return out.str();
}
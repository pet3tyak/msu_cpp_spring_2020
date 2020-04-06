#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <string>

enum class Error
{
    NoError,
    CorruptedArchive
};

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

class Serializer
{
    static constexpr char Separator = ' ';
    std::ostream& out_;
public:
    explicit Serializer(std::ostream& out)
    : out_(out)
    {
    }
    
    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }
    
    template <class... ArgsT>
    Error operator()(ArgsT&... args)
    {
        return process(args...);
    }
    
private:
    template <class T, class... ArgsT>
    Error process (T&& val,ArgsT&&... args)
    {
        Error a = process(val);
        Error b = process(std::forward<ArgsT>(args)...);
        if ((a == Error::CorruptedArchive)||(b == Error::CorruptedArchive))
        {
            return Error::CorruptedArchive;
        }
        return Error::NoError;
    }
    Error process (bool val)
    {
        out_<<(val?"true":"false")<<Separator;
        return Error::NoError;
    }
    Error process (uint64_t val)
    {
        out_<<val<<Separator;
        return Error::NoError;
    }
};

class Deserializer
{
    static constexpr char Separator = ' ';
    std::istream& in_;
public:
    explicit Deserializer(std::istream& in)
    : in_(in)
    {
    }
    template <class T>
    Error load(T& object)
    {
        return object.deserialize(*this);
    }
    
    template <class... ArgsT>
    Error operator()(ArgsT&... args)
    {
        return process(args...);
    }
    
private:
    template <class T, class... ArgsT>
    Error process (T&& val,ArgsT&&... args)
    {
        Error a = process(val);
        Error b = process(std::forward<ArgsT>(args)...);
        if ((a == Error::CorruptedArchive)||(b == Error::CorruptedArchive))
        {
            return Error::CorruptedArchive;
        }
        return Error::NoError;
    }
    Error process (bool& val)
    {
        std::string text;
        in_ >> text;
        if (text == "true")
        {
            val = true;
        }
        else if (text == "false")
            val = false;
        else
            return Error::CorruptedArchive;
        
        return Error::NoError;
    }
    Error process (uint64_t& val)
    {
        std::string text;
        in_ >> text;
        if (is_number(text))
        {
            val=std::stoi(text);
        }
        else
            return Error::CorruptedArchive;
        return Error::NoError;
    }
};

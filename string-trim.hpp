#include <string>
#include <locale>
#include <algorithm>
#include <functional>

inline namespace char_utils
{

    template<typename CharT>
    inline bool is_space(CharT ch)
    {
        return std::isspace<CharT>(ch, std::locale{});
    }

}


/*
 * left_trim
*/

///Removes the whitespaces at the beginning of the string (lvalue version)
template<typename CharT>
inline std::basic_string<CharT> & left_trim(
    std::basic_string<CharT> & str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), is_sp));
    return str;
}

///Removes the whitespaces at the beginning of the string (rvalue version)
template<typename CharT>
inline std::basic_string<CharT> left_trim(
    std::basic_string<CharT> && str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), is_sp));
    return str;
}

///Removes the whitespaces at the beginning of the string (literal version)
template<typename CharT>
inline std::basic_string<CharT> left_trim(
    CharT const * arr,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    return left_trim(std::move(std::basic_string<CharT>{ arr }));
}

/*
 * right_trim
*/

///Removes the whitespaces at the end of the string (lvalue version)
template<typename CharT>
inline std::basic_string<CharT> & right_trim(
    std::basic_string<CharT> & str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    str.erase(std::find_if_not(str.rbegin(), str.rend(), is_sp).base(), str.end());
    return str;
}

///Removes the whitespaces at the end of the string (rvalue version)
template<typename CharT>
inline std::basic_string<CharT> right_trim(
    std::basic_string<CharT> && str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    str.erase(std::find_if_not(str.rbegin(), str.rend(), is_sp).base(), str.end());
    return str;
}

///Removes the whitespaces at the end of the string (literal version)
template<typename CharT>
inline std::basic_string<CharT> right_trim(
    CharT const * arr,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    return right_trim(std::move(std::basic_string<CharT>{ arr }));
}

/*
 * trim
*/

///Removes the whitespaces at the beginning and the end of the string (lvalue version)
template<typename CharT>
inline std::basic_string<CharT> & trim(
    std::basic_string<CharT> & str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    return left_trim(right_trim(str));
}

///Removes the whitespaces at the beginning and the end of the string (rvalue version)
template<typename CharT>
inline std::basic_string<CharT> trim(
    std::basic_string<CharT> && str,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    return left_trim(right_trim(str));
}

///Removes the whitespaces at the beginning and the end of the string (literal version)
template<typename CharT>
inline std::basic_string<CharT> trim(
    CharT const * arr,
    std::function<bool(CharT)> is_sp = is_space<CharT>)
{
    return left_trim(right_trim(std::move(std::basic_string<CharT>{ arr })));
}


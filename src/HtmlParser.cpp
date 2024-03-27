#include "HtmlParser.h"

#include <regex>

std::string HtmlParser::parse(const std::string &html)
{
    std::regex h1Regex("<h1>(.*?)</h1>", std::regex_constants::icase);
    std::smatch matches;
    if (std::regex_search(html, matches, h1Regex) && matches.size() > 1)
    {
        return matches[1].str();
    }
    return "";
}
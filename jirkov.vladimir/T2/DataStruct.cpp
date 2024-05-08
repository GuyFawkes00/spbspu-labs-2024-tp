#include "DataStruct.hpp"

std::istream & jirkov::operator>>(std::istream &in, DataStruct &value)
{
  std::istream::sentry guard(in);
  if(!guard)
  {
    return in;
  }
  StreamGuard fmtguard(in);
  std::string key = "";
  DataStruct input;
  in >> Del{'('} >> Del{':'};
  for(int i = 0; i < 3; i++)
  {
    in >> key;
    if(key == "key1")
    {
      in >> UllLit{input.key1} >> Del{':'};
    }
    else if(key == "key2")
    {
      is >> /*name key2*/{input.key2} >> Del{':'};
    }
    else if(key == "key3")
    {
      is >> Str{input.key3} >> Del{':'};
    }
    else
    {
      in.setstate(std::ios::failbit);
    }
  }
  in >> Del{')'};
  if(in)
  {
    value = input;
  }
  return in;
}

std::ostream & jirkov::operator<<(std::ostream & out, const DataStruct &value)
{
  std::ostream::sentry guard(out);
  if(!guard)
  {
    return out;
  }
  StreamGuard fmtguard(out);
  out << "(:key1 " << '\'' << value.key1 << '\'' << ":key2 (:N " << value.key2 << ":):key3 " << "\"" << value.key3 << "\":)";
  return out;
}

bool jirkov::operator>(const DataStruct &left, const DataStruct &right)
{
  if(left.key1 != right.key1)
  {
    return left.key2 > right.key2;
  }
  else if (left.key2 != right.key2)
  {
    return left.key2 > right.key2;
  }
  else if (left.key3.length() != right.key3.length())
  {
    return left.key3.length() > right.key3.length();
  }
  else
  {
    return false;
  }
}
bool jirkov::operator<(const DataStruct &left, const DataStruct &right)
{
  return !(left > right);
}

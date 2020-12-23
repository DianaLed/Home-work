#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "TRecord.h"
#include "TTable.h"
template<class T>
 TRecord<T>::TRecord(std::string _Name, T _Value)
{
   Name = _Name;
   Value = _Value;
}

 template<class T>
 std::string TRecord<T>::GetName()
 {
   return Name;
 }

 template<class T>
 TRecord<T>& TRecord<T>::operator=(const TRecord& rec)
 {
   Name = rec.Name;
   Value = rec.Value;
   return (*this);
 }

 template class TRecord<double>;
 template class TRecord<TRecord<double>>;
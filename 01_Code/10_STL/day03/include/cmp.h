#ifndef _CMP_H
#define _CMP_H
template<typename T>
T const& max (T const& x, T const& y);
template<typename T>
T const& min (T const& x, T const& y);
template<typename T>
class Comparator {
public:
	Comparator (T const& x, T const& y);
	T const& max (void) const;
	T const& min (void) const;
private:
	T const& m_x;
	T const& m_y;
};
#include "cmp.cpp"
#endif // _CMP_H

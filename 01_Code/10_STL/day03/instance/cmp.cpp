#include <string>
#include "cmp.h"
template<typename T>
T const& max (T const& x, T const& y) {
	return x < y ? y : x;
}
template<typename T>
T const& min (T const& x, T const& y) {
	return x < y ? x : y;
}
template<typename T>
Comparator<T>::Comparator (T const& x,
	T const& y) : m_x (x), m_y (y) {}
template<typename T>
T const& Comparator<T>::max (void) const {
	return m_x < m_y ? m_y : m_x;
}
template<typename T>
T const& Comparator<T>::min (void) const {
	return m_x < m_y ? m_x : m_y;
}
template int const& max<int> (
	int const&, int const&);
template double const& max<double> (
	double const&, double const&);
template std::string const& max<std::string> (
	std::string const&, std::string const&);
template int const& min<int> (
	int const&, int const&);
template double const& min<double> (
	double const&, double const&);
template std::string const& min<std::string> (
	std::string const&, std::string const&);
template class Comparator<int>;
template class Comparator<double>;
template class Comparator<std::string>;

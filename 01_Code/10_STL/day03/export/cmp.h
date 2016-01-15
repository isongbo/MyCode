#ifndef _CMP_H
#define _CMP_H
export template<typename T>
T const& max (T const& x, T const& y);
export template<typename T>
T const& min (T const& x, T const& y);
export template<typename T>
class Comparator {
public:
	Comparator (T const& x, T const& y);
	T const& max (void) const;
	T const& min (void) const;
private:
	T const& m_x;
	T const& m_y;
};
#endif // _CMP_H

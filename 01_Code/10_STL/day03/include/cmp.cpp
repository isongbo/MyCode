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
